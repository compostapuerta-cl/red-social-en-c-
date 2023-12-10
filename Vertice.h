#ifndef VERTICE_H
#define VERTICE_H

#include "lista_simple_ligada.h"
class Vertice
{
private:
    class Arista
    {
    private:
        int ponderacion;
        Vertice* v_2;
        Arista* sigArista;
    public:
        Arista(Vertice* v_2,int ponderacion);
        string toString();

        Vertice *getv_2(){
            return v_2;
        };
        void setv_2(Vertice* v_2){
            this->v_2=v_2;
        };
        Arista* getsigArista(){
            return sigArista;
        };
        void setsigArista(Arista* sigArista){
            this->sigArista=sigArista;
        };
        int getPonderacion() const
        {
            return ponderacion;
        }

        void setPonderacion(int value)
        {
            ponderacion = value;
        }
    };
    string usuario;
    string contrasenia;
    unsigned int referencia;
    Arista* primerArista;
    Vertice* sigVertice;
    unsigned int area;
public:
    Vertice(Usuario dato,unsigned int cont);
    void insertaArista(Vertice* v2, int solicitante); //10 puntos.+
    Arista* buscaArista(Vertice* vBuscado); //15 puntos.+
    void eliminaArista(Arista* e); //10 puntos.+
    Arista *recupera(int indice); //10 puntos.+
    string toString();
    Arista* anterior(Arista* e);
    bool existe(Arista *e);

    void listasolicitudesdeamistad();

    string getusuario(){
        return usuario;
    };
    void setusuario(string usuario){
        this->usuario=usuario;
    };
    string getcontrasenia(){
        return contrasenia;
    };
    void setcontrasenia(string contrasenia){
        this->contrasenia=contrasenia;
    };
    unsigned int getreferencia(){
        return referencia;
    };
    void setreferencia(unsigned int referencia){
        this->referencia=referencia;
    };
    unsigned int getarea(){
        return area;
    };
    void setarea(unsigned int area){
        this->area=area;
    };
    Arista* getprimerArista(){
        return primerArista;
    };
    void setprimerArista(Arista* primerArista){
        this->primerArista=primerArista;
    };
    Vertice* getsigVertice(){
        return sigVertice;
    };
    void setsigVertice(Vertice* sigVertice){
        this->sigVertice=sigVertice;
    };
};

#endif // VERTICE_H
