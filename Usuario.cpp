#include "Usuario.h"

Usuario::Usuario(string nombre, string contrasenia, string correo, unsigned int edad, unsigned int area)
{
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->contrasenia, contrasenia.c_str());
    strcpy(this->correo, correo.c_str());
    this->edad=edad;
    this->area_de_formacion=area;
}

Usuario::Usuario()
{

}
