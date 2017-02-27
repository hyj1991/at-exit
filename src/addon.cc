#include "node.h"
#include "nan.h"
#include "exit.h"

namespace nodex {
  void InitializeProfiler(v8::Local<v8::Object> target) {
    Nan::HandleScope scope;
    //1.init EXIT Class
    EXIT::Initialize(target);
  }

  NODE_MODULE(profiler, InitializeProfiler)
}
