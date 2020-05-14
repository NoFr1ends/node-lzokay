#include <nan.h>
#include <lzokay.hpp>

#include <iostream>

using namespace Nan;
using namespace v8;

NAN_METHOD(Decompress) {
    Nan::MaybeLocal<Object> sourceBuffer = Nan::To<Object>(info[0]);
    if(sourceBuffer.IsEmpty()) {
        info.GetReturnValue().Set(false);
        return;
    }
    Nan::Maybe<int> length = Nan::To<int>(info[1]);
    if(length.IsNothing()) {
        info.GetReturnValue().Set(false);
        return;
    }
    char *source = (char*) node::Buffer::Data(sourceBuffer);

    std::cout << "Decompressed length: " << length.FromJust() << std::endl;

    info.GetReturnValue().Set(true);
}

NAN_MODULE_INIT(Initialize) {
    Nan::Set(target, New<String>("decompress").ToLocalChecked(), GetFunction(New<FunctionTemplate>(Decompress)).ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)