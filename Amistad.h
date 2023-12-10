#ifndef AMISTAD_H
#define AMISTAD_H

#include <string>
#include <string.h>
using namespace std;


class Amistad
{
private:
    char usuario[50];
    char amigo[50];
    unsigned int tipo_de_relacion;
public:
    Amistad();
    Amistad(string usuario,string amigo,unsigned int tipo_de_relacion);
    string getusuario(){
        string usuario(this->usuario);
        return usuario;
    };
    void setusuario(string usuario){
        strcpy(this->usuario, usuario.c_str());
    };
    string getamigo(){
        string amigo(this->amigo);
        return amigo;
    };
    void setamigo(string amigo){
        strcpy(this->amigo, amigo.c_str());
    };
    unsigned int gettipo_de_relacion(){
        return tipo_de_relacion;
    };
    void settipo_de_relacion(unsigned int tipo_de_relacion){
        this->tipo_de_relacion=tipo_de_relacion;
    };
};

#endif // AMISTAD_H
