//
// Created by happy on 15/09/2022.
//

#include "Node.h"

Node::Node(Punt punt) {
    this->punt=punt;
    next=nullptr;
}

Node::Node() {
    punt=Punt();
    next=nullptr;
}

Punt Node::getValor() const {
    return punt;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *node) {
    next=node;
}
Node::Node(Punt punt, Node* next) {
    this->punt=punt;
    if(next==nullptr) {
        this->next = nullptr;
    } else if(next->next== nullptr) {
        this->next = new Node(next->punt);
    } else {
        this->next = new Node(next->punt,next->next);
    }
}

Node *Node::getLast() {
    Node* last = this;
    while (last->getNext() != nullptr){
        last=last->next;
    }
    return last;
}

Node::~Node() {
    delete this->next;
}
