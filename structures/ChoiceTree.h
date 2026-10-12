#pragma once
#include "ChoiceNode.h"

template <typename T>
class ChoiceTree {
private:
    ChoiceNode<T>* root_;
public:
    ChoiceTree(ChoiceNode<T>* root) : root_(root) {}

    ~ChoiceTree() {
        delete root_;
    }

    T evaluate() {
        if (!root_) return "Árbol vacío";

        ChoiceNode<T>* current = root_;
        while (!current->isLeaf()) {
            if (current->getElector()->compare()) {
                current = current->getLeft();
            } else {
                current = current->getRight();
            }
        }
        return current->getResult();
    }
};
