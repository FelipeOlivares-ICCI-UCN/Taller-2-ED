#pragma once
#include "../logic/ChoiceMaker.h"

template <typename T>
class ChoiceNode {
private:
    bool isLeaf_;
    ChoiceNode* left_ = nullptr;
    ChoiceNode* right_ = nullptr;
    BaseChoiceMaker* elector_ = nullptr;
    T* result_;

public:
    ChoiceNode(BaseChoiceMaker* elector)
        : elector_(elector), isLeaf_(false), result_(nullptr) {}

    ChoiceNode(T* result)
        : elector_(nullptr), isLeaf_(true), result_(result) {}

    ~ChoiceNode() {
        delete elector_;
        delete left_;
        delete right_;
    }

    bool isLeaf() const { return isLeaf_; }
    ChoiceNode* getLeft() const { return left_; }
    ChoiceNode* getRight() const { return right_; }
    BaseChoiceMaker* getElector() const { return elector_; }
    T* getResult() const { return result_; }

    void setLeft(ChoiceNode* node) { left_ = node; }
    void setRight(ChoiceNode* node) { right_ = node; }
};
