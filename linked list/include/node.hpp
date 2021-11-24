#pragma once

#include <sstream>

template <class Type>
struct Node {
    Node<Type> *next;
    Type data;

    Node(Type data) {
        this->next = nullptr;
        this->data = data;
    }
};