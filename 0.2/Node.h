//
// Created by happy on 15/09/2022.
//

#ifndef INC_0_1_NODE_H
#define INC_0_1_NODE_H


#include "Punt.h"

class Node {
public:
    Node();
    ~Node();
    explicit Node(Punt punt);
    Node(Punt punt, Node* next);
    void setNext(Node* node);
    Punt getValor() const;
    Node* getNext() const;
    Node* getLast();
private:
    Punt punt;
    Node* next;
};


#endif //INC_0_1_NODE_H
