#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <string.h>
#include <sstream>
#include <QCoreApplication>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class Usuario
{
private:
    char nombre[50];
    char contrasenia[50];
    char correo[50];
    unsigned int edad;
    unsigned int area_de_formacion;
public:
    Usuario();
    Usuario(string nombre,string contrasenia,string correo,unsigned int edad,unsigned int area);
    string getnombre(){
        string nombre(this->nombre);
        return nombre;
    };
    void setnombre(string nombre){
        strcpy(this->nombre, nombre.c_str());
    };
    string getcontrasenia(){
        string contrasenia(this->contrasenia);
        return contrasenia;
    };
    void setcontrasenia(string contrasenia){
        strcpy(this->contrasenia, contrasenia.c_str());
    };
    string getcorreo(){
        string correo(this->correo);
        return correo;
    };
    void setcorreo(string correo){
        strcpy(this->correo, correo.c_str());
    };
    unsigned int getedad(){
        return edad;
    };
    void setedad(unsigned int edad){
        this->edad=edad;
    };
    unsigned int getarea_de_formacion(){
        return area_de_formacion;
    };
    void setarea_de_formacion(unsigned int area_de_formacion){
        this->area_de_formacion=area_de_formacion;
    };
};

#endif // USUARIO_H
