#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"
#include <iostream>


template <class T>
class Queue {
private:
    Node<T>* start;
    Node<T>* end;
public:
    Queue() {
        start = nullptr;
        end = nullptr;
    };
    ~Queue() {
        while (start != nullptr) {
            Node<T> * temp = start;
            start = start->getNext();
            delete temp;
        }
    };

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (start == nullptr) {
            start = newNode;
            end = newNode;
        }
        else {
            end->setNext(newNode);
            end = newNode;
        }
    }

    void pop() {
        if (start == nullptr) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node<T>* temp = start;
        start = start->getNext();

        delete temp;

        if (start == nullptr) {
            end = nullptr;
        }
    }

    T& top() {
        if (start == nullptr) {
            throw std::out_of_range("Queue is empty");
        }

        return start->getValue();
    }

    void show() {
        Node<T>* temp = start;
        int i = 1;

        std::cout << "  ==========  " << std::endl;
        if (this->empty()) {
        std::cout << "  Sin Valores  " << std::endl;

        std::cout << "  ==========  " << std::endl;
        return;

        }

        while (temp != nullptr) {
            std::cout << i << "] " << std::endl << temp->getValue() << std::endl;
            temp = temp->getNext();
            i++;
            std::cout << "  ==========  " << std::endl;
        }
    }

    bool empty() {
        if (start == nullptr) {
            return true;
        }

        return false;
    }
};
