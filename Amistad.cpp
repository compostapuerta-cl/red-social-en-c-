#include "Amistad.h"

Amistad::Amistad(string usuario, string amigo, unsigned int tipo_de_relacion)
{
    strcpy(this->usuario, usuario.c_str());
    strcpy(this->amigo, amigo.c_str());
    this->tipo_de_relacion=tipo_de_relacion;
}
Amistad::Amistad()
{

}
