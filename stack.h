//
// Created by robert on 6/14/17.
//

#ifndef GRAPHSEARCHALGORITHMS_EDD2_STACK_H
#define GRAPHSEARCHALGORITHMS_EDD2_STACK_H

#include <iostream>
#include <ctime>
#include <malloc.h>


using namespace std;

struct nod{
    int info;
    struct nod *next;
};

class stack{
    struct nod *top;

public:
    stack();
    void push(int);
    int pop();
    bool isempty();
    void printStack();
};

stack::stack() {
    top=NULL;
}

void stack::push(int data) {
    nod *p;

    if((p=(nod*)malloc(sizeof(nod)))==NULL){
        cout<<"memoria desbordada"<<endl;
        exit(0);
    }
    p = new nod;
    p->info = data;
    p->next = NULL;
    if(top!=NULL){
        p->next = top;
    }
    top = p;
}

int stack::pop() {

    struct nod *temp;
    int value;
    if(top == NULL){
        cout<<"la pila esta vacia"<<endl;
    }
    else{
        temp=top;
        top=top->next;
        value=temp->info;
        delete temp;
    }
    return value;
}

bool stack::isempty() {
    return(top==NULL);
}

void stack::printStack() {
    struct nod *p=top;
    if(top==NULL){
        cout<<"la pila esta vacia";
    }
    else{
        while(p!=NULL){
            cout<<p->info<<endl;
            p=p->next;
        }
    }
}
#endif //GRAPHSEARCHALGORITHMS_EDD2_STACK_H






















