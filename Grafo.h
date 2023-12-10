#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"
#include "Amistad.h"
class Grafo
{
private:
    Vertice* primerVertice;
    bool Es_dirigido;
    unsigned int cont;
public:
    Grafo(bool Es_ponderado);
    ~Grafo();
    Vertice *recargaVertice(Usuario dato);
    Vertice *insertaVertice(Usuario dato);
    void insertaArista(Vertice* v1, Vertice* v2);
    Vertice* buscaVertice(string datoBuscado);
    void eliminaVertice(Vertice* e);
    Vertice* recupera(int indice);
    string toString();
    Vertice *anterior(Vertice* e);
    bool existe(Vertice* e);

    Vertice *validarIdentidad(string nombre,string contrasenia);
    bool modificar(Vertice* usuario,string dato,unsigned int opcion);
    bool modificar(Vertice* usuario,unsigned int dato,unsigned int opcion);
    string amigostostring(Vertice* usuario);
    void guardar_relaciones();

};



#endif // GRAFO_H
