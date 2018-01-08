#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "arista.h"
#include <vector>

using namespace std;

class nodo{
public:
    nodo();
    string padre="z";
    string tab="";
    string cordenada="z";
    vector <int> orden_visita;
    string estado;//abierto o cerrado
    string otro="";
    float costo=0;
    float total=0;
    float tot=0;
    float distancia=0;
    int color=0;
    int nivel=0;

};

#endif // NODO_H
