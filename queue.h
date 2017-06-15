//
// Created by robert on 6/14/17.
//

#ifndef GRAPHSEARCHALGORITHMS_EDD2_QUEUE_H
#define GRAPHSEARCHALGORITHMS_EDD2_QUEUE_H

#include <iostream>
#include <ctime>

using namespace std;

struct node{
    int info;
    node *next;
};

class queue{
private:
    node *front;
    node *back;

public:
    queue();
    bool isEmpty();
    void enqueue(int);
    int dequeue();
    void print();
};


queue::queue() {
    front = NULL;
    back = NULL;
}

void queue::print() {
    node *p = new node;
    p = front;
    if(front==NULL){
        cout<<"la cola esta vacia"<<endl;
    }
    else{
        while(p!=NULL){
            cout<< p->info <<endl;
            p = p->next;
        }
    }

}


void queue::enqueue(int dato) {

    node *aux = new node();
    aux->info = dato;
    aux->next = NULL;

    if(front == NULL){
        front = aux;
    }
    else{
        back->next = aux;
    }
    back = aux;
}

int queue::dequeue() {
    node *temporal = new node();
    int valor;
    if(front == NULL){
        cout<<"la pila esta vacia"<<endl;
    }
    else{
        temporal = front;
        valor = temporal->info;
        front = temporal->next;
        delete temporal;
    }
    return valor;
}

bool queue::isEmpty() {
    return(front == NULL);
}

#endif //GRAPHSEARCHALGORITHMS_EDD2_QUEUE_H
