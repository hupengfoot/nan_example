#include <node.h>
#include <nan.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "./async.h"

using v8::Function;
using v8::Local;
using v8::Null;
using v8::Number;
using v8::Value;
using namespace std;

int echo(std::string input, std::string& output);

class EchoAsyncWorker : public Nan::AsyncWorker {
    public:
	EchoAsyncWorker(Nan::Callback *callback, std::string input)
	    : Nan::AsyncWorker(callback), input(input){}
	~EchoAsyncWorker() {}

	// Executed inside the worker-thread.
	// It is not safe to access V8, or V8 data structures
	// here, so everything we need for input and output
	// should go on `this`.
	void Execute () {
	    echo(input, output);
	}

	// Executed when the async work is complete
	// this function will be run inside the main event loop
	// so it is safe to use V8 again
	void HandleOKCallback () {

	    Local<Value> argv[] = {
		Nan::Null()
		    , Nan::New(output).ToLocalChecked()
	    };

	    callback->Call(2, argv);
	}

    private:
	std::string input;
	std::string output;
};

int echo(std::string input, std::string& output)
{
    output = input;
    return 0;
}

// Asynchronous access to the `Estimate()` function
NAN_METHOD(EchoAsync) {
    v8::String::Utf8Value node_str(info[0]);
    std::string input = std::string(*node_str);
    Nan::Callback *callback = new Nan::Callback(info[1].As<Function>());

    Nan::AsyncQueueWorker(new EchoAsyncWorker(callback, input));
    info.GetReturnValue().Set(Nan::New("").ToLocalChecked());
}
