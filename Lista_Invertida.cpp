#include "Lista_Invertida.h"

Lista_Invertida::Lista_Invertida()
{
    string areas[10]{"Psicologia", "Educacion","Sociedad","Salud","Sistemas computacionales"
                ,"Literatura" ,"Economia","Transportes" , "Entretenimiento","Ingenieria"};
    ifstream fin("Areas_De_Formacion.txt");
    if(!fin.is_open()){
        for(int i = 0;i<10;i++){
            Areas[i].setarea(areas[i]);
        }
        return;
    }
    string entero;
    getline(fin,entero);
    for(int i = 0;i<10;i++){
        while(entero!="@"){
            Areas[i].addLast(stoi(entero));
            getline(fin,entero);
        }
        getline(fin,entero);
        Areas[i].setarea(areas[i]);
    }
}

Lista_Invertida::~Lista_Invertida()
{
    guardar();
}

string Lista_Invertida::ImprimirLista(unsigned int area)
{
    return Areas[area].print();
}

void Lista_Invertida::Agregar(Vertice *usuario)
{
    Areas[usuario->getarea()].addFirst(usuario->getreferencia());
}

void Lista_Invertida::Remover(Vertice *usuario)
{
    Areas[usuario->getarea()].remove(usuario->getreferencia());
}

void Lista_Invertida::guardar()
{
    ofstream fout("Areas_De_Formacion.txt");
    if(!fout.is_open()){
        return;
    }
    for(int i=0;i<10;i++){
        fout<<Areas[i].toFile()<<"@"<<endl;
    }
    fout.close();
}

