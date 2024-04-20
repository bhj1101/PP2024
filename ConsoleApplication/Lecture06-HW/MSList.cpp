#include "MSList.h"

MSListNode::MSListNode() : data(nullptr), next(nullptr) {}

MSListNode::~MSListNode() {
    delete next;
}

MSList::MSList() : head(nullptr), tail(nullptr) {}

MSList::~MSList() {
    clear();
}

void MSList::push_back(MObject* object) {
    MSListNode* newNode = new MSListNode;
    newNode->data = object;

    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

MObject* MSList::pop_back() {
    if (isEmpty()) {
        return nullptr;
    }

    MSListNode* temp = tail;
    MObject* data = temp->data;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->next;
    }

    delete temp;
    return data;
}

bool MSList::isEmpty() {
    return head == nullptr;
}

void MSList::clear() {
    while (!isEmpty()) {
        pop_back();
    }
}
