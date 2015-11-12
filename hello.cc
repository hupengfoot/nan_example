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

NAN_METHOD(Echo) {
    String::Utf8Value node_str(info[0]);
    std::string inputStr = string(*node_str);

    info.GetReturnValue().Set(Nan::New(inputStr).ToLocalChecked());
}

