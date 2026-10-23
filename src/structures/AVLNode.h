#pragma once

template <class T>
class AVLNode {
private:
    T value_;
    AVLNode* left_;
    AVLNode* right_;
    int height_;
public:
    AVLNode(const T& value): value_(value), left_(nullptr), right_(nullptr), height_(1) {};

    const T& getValue() const { return this->value_; };
    AVLNode<T>* getLeft() const { return this->left_; };
    AVLNode<T>* getRight() const { return this->right_;};
    int getHeight() {return this->height_;};

    void setValue(const T& newValue) {this->value_ = newValue;};
    void setLeft(AVLNode<T>* newLeft){this->left_ = newLeft;};
    void setRight(AVLNode<T>* newRight) {this->right_ = newRight;};
    void setHeight(int newHeight) {this->height_ = newHeight;}
};

