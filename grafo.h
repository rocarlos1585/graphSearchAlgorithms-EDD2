//
// Created by robert on 6/13/17.
//

#ifndef GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H
#define GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H

#include <iostream>
#include <list>

using namespace std;

class grafo{
    int numeroVertices;
    list<int> *adyacencia;  //este apunta a un arreglo que es el que se va a encargar de mantener la lista de adyacencia
    void busquedaProfundidad(int v, bool visitados[]);

public:
    grafo(int V);
    void agregarArista(int vertice1, int vertice2);
    void print(int source, int target);
};


grafo::grafo(int V) {
    this -> numeroVertices = V;
    adyacencia = new list<int>[V];
}

void grafo::agregarArista(int vertice1, int vertice2) {
    adyacencia[vertice1].push_back(vertice2);
}

void grafo::busquedaProfundidad(int v, bool visitados[]) {

    visitados[v]=true;
    cout<< v <<endl;    //imprime el nodo visitado actual

    list<int> :: iterator i;
    for(i = adyacencia[v].begin(); i!=adyacencia[v].end(); i++){
        if(!visitados[*i]){
            busquedaProfundidad(*i, visitados);
        }
    }
}

void grafo::print(int source, int target) {

    bool *visitados = new bool[numeroVertices];
    for(int i=0; i < numeroVertices; i++){
        visitados[i]=false;
    }

    for(int j=0; j < numeroVertices; j++){
        if(visitados[j]==false){
            busquedaProfundidad(j, visitados);
        }
    }
}
#endif //GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H
