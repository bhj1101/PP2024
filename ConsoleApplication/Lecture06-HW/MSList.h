#ifndef MSList_h
#define MSList_h

#include <iostream>

class MObject;

class MSListNode {
public:
    MSListNode();
    ~MSListNode();

    MObject* data;
    MSListNode* next;
};

class MSList {
public:
    MSList();
    ~MSList();

    void push_back(MObject* object);
    MObject* pop_back();
    bool isEmpty();

    void clear();

    MSListNode* head;
    MSListNode* tail;
};

#endif
