#include "node.h"
#include "nan.h"

namespace nodex{
    using v8::Local;
    using v8::Object;
    using v8::Value;
    using v8::Function;

    class EXIT{
        public:
            static void Initialize(Local<Object> target);
            //define constructor
            EXIT();
            ~EXIT();
        protected:
            //define Inner Function List
            static void RegisterFunction(const Nan::FunctionCallbackInfo<Value>& info);
            static void AtExitCallback(void* arg);
    };
}