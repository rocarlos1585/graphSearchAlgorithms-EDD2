#include <iostream>
#include "grafo.h"

using namespace std;

int main() {
    int source;
    int target;


    grafo G(6);

    G.agregarArista(1,3);
    G.agregarArista(1,6);
    G.agregarArista(2,3);
    G.agregarArista(2,4);
    G.agregarArista(2,5);
    G.agregarArista(5,3);
    G.agregarArista(4,5);
    G.agregarArista(4,6);
    G.agregarArista(6,5);

    cout<<"introduce el inicio: ";
        cin>>source;
    cout<<"introduce el objetivo: ";
        cin>>target;

    G.printDFS(source, target);

    G.printBFS(source);

    return 0;
}