#ifndef LISTA_INVERTIDA_H
#define LISTA_INVERTIDA_H
#include "Vertice.h"
class Lista_Invertida
{
private:
    LinkedList<unsigned int> Areas[10];
public:
    Lista_Invertida();
    ~Lista_Invertida();
    string ImprimirLista(unsigned int area);
    void Agregar(Vertice* usuario);
    void Remover(Vertice* usuario);
    void guardar();
};

#endif // LISTA_INVERTIDA_H
