//
// Created by robert on 6/13/17.
//

#ifndef GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H
#define GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H

#include <iostream>
#include <list>
#include "queue.h"
#include "stack.h"


using namespace std;

class grafo{
private:
    int numeroVertices;
    int **arreglo;
    //list<int> *adyacencia;  //este apunta a un arreglo que es el que se va a encargar de mantener la lista de adyacencia
    //void busquedaProfundidad(int v, bool visitados[]);

public:
    grafo(int tamano = 2);
    void agregarArista(int vertice1, int vertice2);
    void printDFS(int source, int target);
    void printBFS(int start);
    bool conexion(int, int);
};


grafo::grafo(int tamano) {
    int a, b;
    if(tamano<2){
        numeroVertices=2;
    }
    else{
        numeroVertices = tamano;
    }

    arreglo = new int *[numeroVertices];
    for (a = 0; a<numeroVertices; a++){
        arreglo[a] = new int[numeroVertices];
    }

    for(a=0; a<numeroVertices; a++){
        for(b=0; b<numeroVertices; b++){
            arreglo[a][b]=0;
        }
    }

}

void grafo::agregarArista(int vertice1, int vertice2) {
    arreglo[vertice1-1][vertice2-1]=arreglo[vertice2-1][vertice1-1]=1;
}

/*void grafo::busquedaProfundidad(int v, bool visitados[]) {

    visitados[v]=true;
    cout<< v <<endl;    //imprime el nodo visitado actual

    list<int> :: iterator i;
    for(i = adyacencia[v].begin(); i!=adyacencia[v].end(); i++){
        if(!visitados[*i]){
            busquedaProfundidad(*i, visitados);
        }
    }
}*/

bool grafo::conexion(int x, int y) {
    return (arreglo[x-1][y-1]==1);
}

void grafo::printDFS(int source, int target) {

    stack s;

    bool *visitados = new bool[numeroVertices+1];
    int i;

    for(i=0; i <= numeroVertices; i++){              //si hay un error en el recorrido, revisar esta linea ya que no estoy seguro si el indexado esta bien
        visitados[i]=false;
    }

    s.push(source);

    visitados[source] = true;
    if(source==target) return;
    cout<<"busqueda en profundidad empieza en el vertice: "<<source<<" y termina en el vertice: "<<target<<endl;
    while(!s.isempty()){
        int k = s.pop();
        if(k==target){break;}
        cout<<k<<" ";
        for(i=numeroVertices; i>=0; i--){        //revisar tambien este ciclo por lo del indexado
            if(conexion(k, i) && !visitados[i]){
                s.push(i);
                visitados[i] = true;
            }
        }
    }
    cout<<target;
    cout<<endl;
    delete[]visitados;
    /*for(int j=0; j < numeroVertices; j++){
        if(visitados[j]==false){
            busquedaProfundidad(j, visitados);
        }
    }*/
}

void grafo::printBFS(int start) {
    queue q;

    bool *encontrados = new bool[numeroVertices+1];

    for(int i=0; i<=numeroVertices; i++){
        encontrados[i] = false;
    }

    q.enqueue(start);
    encontrados[start]=true;

    cout<<"busqueda en profundidad empezando desde el vertice: "<< start <<endl;

    while(!q.isEmpty()){
        int verticeActual = q.dequeue();

        cout<< verticeActual<<" ";

        for(int verticeConectado = 1; verticeConectado <= numeroVertices; ++verticeConectado){
            if(conexion(verticeActual, verticeConectado) && !encontrados[verticeConectado]){
                q.enqueue(verticeConectado);
                encontrados[verticeConectado] = true;
            }
        }

    }
    delete []encontrados;
}

#endif //GRAPHSEARCHALGORITHMS_EDD2_GRAFO_H
