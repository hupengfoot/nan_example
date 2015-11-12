#include <stdio.h> 
#include <sys/types.h> 
#include <regex.h>
#include <node.h>
#include <iostream>      
#include <nan.h>

#include "./hello.h"
#include "./async.h"
#include "./binary.h"

using v8::FunctionTemplate;
using namespace std;
using namespace v8;
using namespace Nan;

NAN_MODULE_INIT(InitAll) {
    Nan::Set(target, Nan::New("Echo").ToLocalChecked(),
	    Nan::GetFunction(Nan::New<FunctionTemplate>(Echo)).ToLocalChecked());
    Nan::Set(target, Nan::New("EchoAsync").ToLocalChecked(),
	    Nan::GetFunction(Nan::New<FunctionTemplate>(EchoAsync)).ToLocalChecked());
    Nan::Set(target, Nan::New("EchoBinary").ToLocalChecked(),
	    Nan::GetFunction(Nan::New<FunctionTemplate>(EchoBinary)).ToLocalChecked());
}

NODE_MODULE(addon, InitAll)
