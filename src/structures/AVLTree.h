#pragma once

#include "AVLNode.h"
#include <iostream>

template <class T>
class AVLTree {
private:
    AVLNode<T>* root;
    int height(AVLNode<T>* node);

    int balanceFactor(AVLNode<T>* node);

    AVLNode<T>* rotateRight(AVLNode<T>* y);

    AVLNode<T>* rotateLeft(AVLNode<T>* x);

    AVLNode<T>* insert(AVLNode<T>* node, const T& value);

    AVLNode<T>* search(AVLNode<T>* node, T value);

    void preorder(AVLNode<T>* node);

    void inorder(AVLNode<T>* node);

    void postorder(AVLNode<T>* node);

public:
    AVLTree();

    void insert(const T& value);

    void printPreOrder();

    void printInOrder();

    void printPostOrder();


    void search(const T& value);

    void printTreeInfo();
};

extern template class AVLTree<int>;
extern template class AVLTree<std::string>;
