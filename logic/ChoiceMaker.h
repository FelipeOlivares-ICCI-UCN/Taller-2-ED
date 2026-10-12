#pragma once
#include "ChoiceMakerBase.h"

template <typename T, typename GetterFunc, typename ValueType>
class ChoiceMaker : public BaseChoiceMaker {
public:
    enum Comparations //possible comparations
    {
        EQUALS,
        GREATER,
        LESS,
        LESSEQ,
        GREATEREQ
    };
private:
    T* obj;
    GetterFunc objGetter;
    ValueType comparedValue; //the one being compared
    Comparations comparedMethod;
public:
   ChoiceMaker(T* obj, GetterFunc getter, ValueType comparedValue, Comparations comparedMethod):
       obj(obj), objGetter(getter), comparedValue(comparedValue), comparedMethod(comparedMethod) {}

    bool compare() override
    {
        switch (comparedMethod)
           {
           case EQUALS:
            return (obj->*objGetter)() == comparedValue;
           case GREATER:
            return (obj->*objGetter)() > comparedValue;
           case LESS:
            return (obj->*objGetter)() < comparedValue;
           case LESSEQ:
            return (obj->*objGetter)() <= comparedValue;
           case GREATEREQ:
            return (obj->*objGetter)() > comparedValue;
           default:
            return false;
           }
    }
};

