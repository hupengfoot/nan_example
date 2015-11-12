#include <stdio.h> 
#include <sys/types.h> 
#include <regex.h>
#include <node.h>
#include <iostream>      
#include <nan.h>
#include "./hello.h"

using v8::FunctionTemplate;
using namespace std;
using namespace v8;
using namespace Nan;

NAN_METHOD(EchoBinary) {
    Local<Object> bufferObj = info[0]->ToObject();
    char* input = node::Buffer::Data(bufferObj);

    string output = input;
    node::Buffer *buf = node::Buffer::New(output.c_str(), output.length());
    info.GetReturnValue().Set(Nan::New(buf->handle_));
}

