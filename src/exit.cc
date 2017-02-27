#include "exit.h"

namespace nodex{
    using node::AtExit;

    //define inner global params
    Local<Function> callback;
    Nan::Persistent<Function> func_p(callback);

    void EXIT::Initialize(Local<Object> target){
        Nan::HandleScope scope;

        //set this method into target
        Nan::SetMethod(target, "registerFunction", EXIT::RegisterFunction);
    }

    //register js function which called before process exit
    void EXIT::RegisterFunction(const Nan::FunctionCallbackInfo<Value>& info){
        int argumentsLength = info.Length();

        //simple arguments check
        if(argumentsLength < 1){
            printf("Arguments at least 1!\n");
            return;
        }
        if(!info[0]->IsFunction()){
            printf("Arguments 1 must be function!\n");
            return;
        }

        Local<Function> callback = info[0].As<Function>();
        func_p.Reset(callback);
        AtExit(EXIT::AtExitCallback);
    }

    //before exit hook
    void EXIT::AtExitCallback(void* arg){
        Nan::HandleScope scope;

        Local<Object> recv = Nan::New<Object>();
        const int argc = 0;
        Local<Value> argv[argc] = {};
        Local<Function> callback_tmp = Nan::New(func_p);
        Nan::Call(callback_tmp, recv, argc, argv);
    }
}