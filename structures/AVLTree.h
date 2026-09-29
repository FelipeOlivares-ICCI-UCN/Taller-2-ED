#pragma once

#include "AVLNode.h"
#include <iostream>

template <class T>
class AVLTree {
private:
    AVLNode<T>* root;
    int height(AVLNode<T>* node){if (node == nullptr) return 0; return node->getHeight();};

    int balanceFactor(AVLNode<T>* node){
        if (node ==nullptr) return 0;
        return height(node->getLeft()) - height(node->getRight());
    };

    AVLNode<T>* rotateRight(AVLNode<T>* y)
    {
        AVLNode<T>* x = y->getLeft();
        AVLNode<T>* temp = x->getRight();

        x->setRight(y);
        y->setLeft(temp);

        y->setHeight(1 + std::max(height(y->getLeft()),
                                  height(y->getRight()))
                     );
        x->setHeight(1 + std::max(height(x->getLeft()),
                                  height(x->getRight())));

        return x;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x)
    {
        AVLNode<T>* y = x->getRight();
        AVLNode<T>* temp = y->getLeft();

        y->setLeft(x);
        x->setRight(temp);

        x->setHeight(1 + std::max(height(x->getLeft()),
                                  height(x->getRight()))
                     );
        y->setHeight(1 + std::max(height(y->getLeft()),
                                  height(y->getRight())));
        return y;
    }

    AVLNode<T>* insert(AVLNode<T>* node, const T& value)
    {
        if (node == nullptr)
            {
                return new AVLNode<T>(value);
            }

        if (value < node->getValue())
            {
                node->setLeft(insert(node->getLeft(), value));
            }

        else if (node->getValue() < value)
            {
                node->setRight(insert(node->getRight() ,value));
            }

        else
            {
                return node;
            }

        node->setHeight(1 + std::max(height(node->getLeft()),
                                     height(node->getRight())
                                     ));
        int balance = balanceFactor(node);

        if (balance > 1)
            {
                if (balanceFactor(node->getLeft()) >= 0)
                    {
                        return rotateRight(node);
                    }
                else
                    {
                        node->setLeft(rotateLeft(node->getLeft()));
                        return rotateRight(node);
                    }
            }
        if (balance < -1)
            {
                if (balanceFactor(node->getRight()) <= 0)
                    {
                        return rotateLeft(node);
                    }
                else
                    {
                        node->setRight(rotateRight(node->getRight()));
                        return rotateLeft(node);
                    }
            }


        return node;
    }

    AVLNode<T>* search(AVLNode<T>* node, T value)
    {
        if (node == nullptr) return nullptr;

        if (node->getValue() == value) return node;

        if (value < node->getValue()) return search(node->getLeft(), value);

        return search(node->getRight(), value);
    }





    void preorder(AVLNode<T>* node)
    {
        if (node == nullptr)
            {
                return;
            }

        std::cout << node->getValue() << " ";

        preorder(node->getLeft());
        preorder(node->getRight());
    }

public:
    AVLTree():
        root(nullptr){};

    void insert(const T& value)
    {
        root = insert(root, value);
    }

    void printPreOrder()
    {
        preorder(root);
    }

    void search(T value)
    {
        AVLNode<T>* node = search(root, value);
        if (node == nullptr)
            {
                std::cout << "Value doesnt exists" << std::endl;
            }
        else
            {
                std::cout << node->getValue() << std::endl;
            }


    }

};
