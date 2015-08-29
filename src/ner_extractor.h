#ifndef NER_EXTRACTOR_H
#define NER_EXTRACTOR_H

#include <nan.h>
#include <mitie/named_entity_extractor.h>

class NerExtractor : public Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit NerExtractor(string ner_file_path);
    ~NerExtractor();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void Predict(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;
    mitie::named_entity_extractor ner_;
    vector<string> tagstr_;
};

#endif
