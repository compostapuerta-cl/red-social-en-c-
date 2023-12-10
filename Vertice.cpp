#include "Vertice.h"

Vertice::Vertice(Usuario dato, unsigned int cont)
{
    usuario=dato.getnombre();
    contrasenia=dato.getcontrasenia();
    referencia=cont*sizeof(Usuario);
    area=dato.getarea_de_formacion();
    primerArista=nullptr;
    sigVertice=nullptr;
}

void Vertice::insertaArista(Vertice *v2, int solicitante)
{

    Arista* nueva= new Arista(v2,solicitante);
    if(this->primerArista){
        Arista* aux=primerArista;
        while(aux){
            if(!(aux->getsigArista())){
                aux->setsigArista(nueva);
                break;
            }
            aux=aux->getsigArista();
        }
    }
    else{
        primerArista=nueva;
    }
}

Vertice::Arista *Vertice::buscaArista(Vertice *vBuscado)
{
    Arista* aux=primerArista;
    while(aux){
        if(aux->getv_2()==vBuscado){
            break;
        }
        aux=aux->getsigArista();
    }
    return aux;
}

void Vertice::eliminaArista(Vertice::Arista *e)
{
    Arista* aux= anterior(e);
    if(existe(e)){
        if(aux){
            aux->setsigArista(e->getsigArista());
        }
        else{
            primerArista=e->getsigArista();
        }
        delete e;
    }
}

Vertice::Arista *Vertice::recupera(int indice)
{
    Arista* aux=primerArista;
    int i=0;
    while(aux){
        if(i==indice)
            break;
        aux=aux->getsigArista();
        i++;
    }
    return aux;
}

string Vertice::toString()
{
    string cadena= usuario;
    Arista* aux=primerArista;
    while(aux){
        if(aux->getPonderacion()==2)
            cadena+="->"+aux->toString();
        aux=aux->getsigArista();
    }
    return cadena;
}

Vertice::Arista *Vertice::anterior(Vertice::Arista *e)
{
    Arista* aux=primerArista;
    if(aux==e){
        return nullptr;
    }
    while(aux){
        if(aux->getsigArista()==e)
            return aux;
        aux=aux->getsigArista();
    }
    return nullptr;
}

bool Vertice::existe(Vertice::Arista *e)
{
    Arista* aux=primerArista;
    while(aux){
        if(aux==e)
            return 1;
        aux=aux->getsigArista();
    }
    return 0;
}

void Vertice::listasolicitudesdeamistad()
{
    Arista* aux=primerArista;
    while(aux){
        if(aux->getPonderacion()==0){
            int opc;
            cout << "El usuario " << aux->getv_2()->getusuario() << endl
                 << "1. Aceptar usuario" << endl
                 << "2. Rechazar usuario" << endl;
            cin >> opc;
            if(opc==1){
                aux->setPonderacion(2);
                aux->getv_2()->buscaArista(this)->setPonderacion(2);
                aux=aux->getsigArista();
            }
            else if(opc==2){
                aux->getv_2()->eliminaArista(aux->getv_2()->buscaArista(this));
                Arista*arista_siguiente=aux->getsigArista();
                eliminaArista(aux);
                aux=arista_siguiente;
            }
        }
        else{
            aux=aux->getsigArista();
        }
    }
}

Vertice::Arista::Arista(Vertice *v_2, int ponderacion)
{
    this->v_2=v_2;
    this->ponderacion=ponderacion;
    sigArista=nullptr;
}


string Vertice::Arista::toString()
{
    return v_2->getusuario();
}
