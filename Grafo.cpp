#include "Grafo.h"

Grafo::Grafo(bool Es_dirigido)
{
    primerVertice=nullptr;
    this->Es_dirigido=Es_dirigido;
    cont=0;
    ifstream fin("Usuarios.bin",ios::binary);
    if(!fin.is_open())
        return;
    Usuario obj;
    fin.read((char*)(&obj),sizeof(Usuario));
    while(!fin.eof()){
        if(obj.getarea_de_formacion()<10 and obj.getarea_de_formacion()>=0){
            recargaVertice(obj);
        }
        else
            cont++;
        fin.read((char*)(&obj),sizeof(Usuario));
    }
    fin.close();
    fin.open("Relaciones.bin",ios::binary);
    if(!fin.is_open())
        return;
    Amistad objamistad;
    fin.read((char*)(&objamistad),sizeof(Amistad));
    while(!fin.eof()){
        buscaVertice(objamistad.getusuario())->insertaArista(buscaVertice(objamistad.getamigo()),objamistad.gettipo_de_relacion());
        fin.read((char*)(&objamistad),sizeof(Amistad));
    }
}

Grafo::~Grafo()
{
    guardar_relaciones();
}

Vertice *Grafo::recargaVertice(Usuario dato)
{
    Vertice* nuevo=new Vertice(dato,cont);
    cont++;
    if(!primerVertice){
        primerVertice=nuevo;
    }
    else{
        Vertice* aux=primerVertice;
        while(aux->getsigVertice()){
            aux=aux->getsigVertice();
        }
        aux->setsigVertice(nuevo);
    }
    return nuevo;
}

Vertice *Grafo::insertaVertice(Usuario dato)
{
    Vertice* nuevo=new Vertice(dato,cont);
    ofstream fout("Usuarios.bin",ios::binary|ios::in);
    if(!fout.is_open()){
        fout.close();
        fout.open("Usuarios.bin",ios::binary);
    }
    fout.seekp(sizeof(Usuario)*cont);
    fout.write((char*)(&dato),sizeof(Usuario));
    cont++;
    if(!primerVertice){
        primerVertice=nuevo;
    }
    else{
        Vertice* aux=primerVertice;
        while(aux->getsigVertice()){
            aux=aux->getsigVertice();
        }
        aux->setsigVertice(nuevo);
    }
    return nuevo;
}

void Grafo::insertaArista(Vertice *v1, Vertice *v2)
{
    v2->insertaArista(v1,0);
    v1->insertaArista(v2,1);
}

Vertice *Grafo::buscaVertice(string datoBuscado)
{
    Vertice* aux=primerVertice;
    while(aux){
        if(aux->getusuario()==datoBuscado)
            break;
        aux=aux->getsigVertice();
    }
    return aux;
}

void Grafo::eliminaVertice(Vertice *e)
{
    Vertice* aux=anterior(e);
    string objetounos;
    if(existe(e)){
        unsigned int posicion=e->getreferencia();
        for(int i=0;i<sizeof(Usuario);i++){
            objetounos+="1";
        }
        if(aux){
            aux->setsigVertice(e->getsigVertice());
        }
        else{
            primerVertice=e->getsigVertice();
        }
        Vertice* aux2=primerVertice;
        while(aux2){
            if(aux2->buscaArista(e)){
                aux2->eliminaArista(aux2->buscaArista(e));
            }
            aux2=aux2->getsigVertice();
        }
        delete e;
        ofstream fout("Usuarios.bin",ios::binary|ios::in);
        if(fout.is_open()){
            char obj1[sizeof(Usuario)+2];
            strcpy(obj1,objetounos.c_str());
            fout.seekp(posicion);
            fout.write(obj1,sizeof(Usuario));
        }
    }

}

Vertice *Grafo::recupera(int indice)
{
    Vertice* aux=primerVertice;
    int i=0;
    while(aux){
        if(i==indice)
            break;
        aux=aux->getsigVertice();
        i++;
    }
    return aux;
}

string Grafo::toString()
{
    string cadena;
    Vertice* aux=primerVertice;
    while(aux){
        cadena+=aux->toString()+"\n|\n";
        aux=aux->getsigVertice();
    }
    return cadena;
}

Vertice *Grafo::anterior(Vertice *e)
{
    Vertice* aux=primerVertice;
    if(aux==e){
        return nullptr;
    }
    while(aux){
        if(aux->getsigVertice()==e)
            return aux;
        aux=aux->getsigVertice();
    }
    return nullptr;
}

bool Grafo::existe(Vertice *e)
{
    Vertice* aux=primerVertice;
    while(aux){
        if(aux==e)
            return 1;
        aux=aux->getsigVertice();
    }
    return 0;
}

Vertice *Grafo::validarIdentidad(string nombre, string contrasenia)
{
    Vertice* usuario=buscaVertice(nombre);
    if(usuario){
        if(usuario->getcontrasenia()==contrasenia){
            return usuario;
        }
        return nullptr;
    }
    return nullptr;
}

bool Grafo::modificar(Vertice *usuario, string dato, unsigned int opcion)
{
    ifstream fin("Usuarios.bin",ios::binary);
    if(!fin.is_open())
        return false;
    Usuario obj;
    fin.seekg(usuario->getreferencia());
    fin.read((char*)(&obj),sizeof(Usuario));
    switch (opcion) {
        case 1:{
            obj.setnombre(dato);
            usuario->setusuario(dato);
            break;
        }
        case 2:{
            obj.setcontrasenia(dato);
            usuario->setcontrasenia(dato);
            break;
        }
        case 3:{
            obj.setcorreo(dato);
            break;
        }
        default:
            return false;
    }
    fin.close();
    ofstream fout("Usuarios.bin",ios::binary|ios::in);
    fout.seekp(usuario->getreferencia());
    fout.write((char*)(&obj),sizeof(Usuario));
}

bool Grafo::modificar(Vertice *usuario, unsigned int dato, unsigned int opcion)
{
    ifstream fin("Usuarios.bin",ios::binary);
    if(!fin.is_open())
        return false;
    Usuario obj;
    fin.seekg(usuario->getreferencia());
    fin.read((char*)(&obj),sizeof(Usuario));
    switch (opcion) {
        case 4:{
            obj.setedad(dato);
            break;
        }
        case 5:{
            obj.setarea_de_formacion(dato);
            usuario->setarea(dato);
            break;
        }

        default:
            return false;
    }
    fin.close();
    ofstream fout("Usuarios.bin",ios::binary|ios::in);
    fout.seekp(usuario->getreferencia());
    fout.write((char*)(&obj),sizeof(Usuario));
}

string Grafo::amigostostring(Vertice *usuario)
{
    return usuario->toString()+"\n";
}

void Grafo::guardar_relaciones()
{
    ofstream fout("Relaciones.bin",ios::binary);
    Vertice* aux=primerVertice;
    int i=0;
    while(aux){
        if(aux->recupera(i)){
            Amistad obj(aux->getusuario(),aux->recupera(i)->getv_2()->getusuario(),aux->recupera(i)->getPonderacion());
            fout.write((char*)(&obj),sizeof(Amistad));
            i++;
        }
        else{
            i=0;
            aux=aux->getsigVertice();
        }
    }
}


