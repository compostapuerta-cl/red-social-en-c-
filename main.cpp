#include "Grafo.h"
#include "Lista_Invertida.h"
void print_areas_de_formacion();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int opc;
    Grafo grafo(1);
    Lista_Invertida areas;
    do{
        cout << "1. Agregar usuario." << endl
             << "2. Acceder a usuario." << endl
             << "3. Mostrar red." << endl
             << "4. Mostrar lista invertida de:" << endl
             << "5. Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:{
                cin.ignore();
                string nombre_usuario;
                string contrasenia;
                string confirmacion_contrasenia;
                string correo;
                unsigned int edad;
                unsigned int area_de_formacion;
                char caracter;
                cout << "Ingrese el nombre de usuario:" << endl;
                getline(cin,nombre_usuario);
                do{
                    confirmacion_contrasenia="";
                    cout << "Ingrese la contrasenia:" << endl;
                    getline(cin,contrasenia);
                    cout << "Ingrese la contrasenia de nuevo:" << endl;
                    caracter=getch();
                    while(caracter != 13){
                        confirmacion_contrasenia.push_back(caracter);
                        cout << "*";
                        caracter=getch();
                    }
                    cout << endl;
                }while(contrasenia!=confirmacion_contrasenia);
                do{
                    cout << "Ingrese su correo electronico:" << endl;
                    getline(cin,correo);
                }while(!((correo.find("@")!= string::npos)&&(correo.find(".")!= string::npos)));
                do{
                    cout << "Ingrese su edad:" << endl;
                    cin >> edad;
                }while(edad>100);
                do{
                    cout << "Seleccione una:" << endl;
                    print_areas_de_formacion();
                    cout << "Digite la opcion deseada: ";
                    cin >> area_de_formacion;
                }while(area_de_formacion<0 or area_de_formacion>10);
                Usuario nuevo(nombre_usuario,contrasenia,correo,edad,area_de_formacion);
                grafo.insertaVertice(nuevo);
                areas.Agregar(grafo.buscaVertice(nombre_usuario));
                   break;
           }
           case 2:{
                cin.ignore();
                string nombre_usuario;
                string contrasenia;
                char caracter;
                cout << "Ingrese el nombre de usuario:" << endl;
                getline(cin,nombre_usuario);
                cout << "Ingrese la contrasenia:" << endl;
                caracter=getch();
                while(caracter != 13){
                    contrasenia.push_back(caracter);
                    cout << "*";
                    caracter=getch();
                }
                Vertice* usuario=grafo.validarIdentidad(nombre_usuario,contrasenia);
                if(!usuario){
                    cout << "\nUsuario o Contrasenia Incorrecta\n";
                    break;
                }
                do{
                    cout << "\n1. Modificar." << endl
                         << "2. Mostrar lista de amigos." << endl
                         << "3. Agregar amigo." << endl
                         << "4. Eliminar amigo." << endl
                         << "5. Ver propuestas de amistad." << endl
                         << "6. Eliminar cuenta." << endl
                         << "7. Volver al menu principal." << endl;
                    cin >> opc;
                    switch (opc) {
                        case 1:{
                            cout << "\n1. Usuario." << endl
                                 << "2. Contrasenia." << endl
                                 << "3. Correo." << endl
                                 << "4. Edad." << endl
                                 << "5. Area de formacion." << endl
                                 << "6. Cancelar." << endl;
                            cin >> opc;
                            cin.ignore();
                            switch(opc){
                                case 1:{
                                    string nombre_usuario;
                                    cout << "Ingrese el nombre de usuario:" << endl;
                                    getline(cin,nombre_usuario);
                                    grafo.modificar(usuario,nombre_usuario,opc);
                                    break;
                                }
                                case 2:{
                                    string contrasenia;
                                    string confirmacion_contrasenia;
                                    do{
                                        confirmacion_contrasenia="";
                                        cout << "Ingrese la contrasenia:" << endl;
                                        getline(cin,contrasenia);
                                        cout << "Ingrese la contrasenia de nuevo:" << endl;
                                        caracter=getch();
                                        while(caracter != 13){
                                            confirmacion_contrasenia.push_back(caracter);
                                            cout << "*";
                                            caracter=getch();
                                        }
                                        cout << endl;
                                    }while(contrasenia!=confirmacion_contrasenia);
                                    grafo.modificar(usuario,contrasenia,opc);
                                    break;
                                }
                                case 3:{
                                    string correo;
                                    do{
                                        cout << "Ingrese su correo electronico:" << endl;
                                        getline(cin,correo);
                                    }while(!((correo.find("@")!= string::npos)&&(correo.find(".")!= string::npos)));
                                    grafo.modificar(usuario,correo,opc);
                                    break;
                                }
                                case 4:{
                                    unsigned int edad;
                                    do{
                                        cout << "Ingrese su edad:" << endl;
                                        cin >> edad;
                                    }while(edad>100);
                                    grafo.modificar(usuario,edad,opc);
                                    break;
                                }
                                case 5:{
                                    int area_de_formacion;
                                    do{
                                        cout << "Seleccione una:" << endl;
                                        print_areas_de_formacion();
                                        cout << "Digite la opcion deseada: ";
                                        cin >> area_de_formacion;
                                    }while(area_de_formacion<0 or area_de_formacion>10);
                                    areas.Remover(usuario);
                                    grafo.modificar(usuario,area_de_formacion,opc);
                                    areas.Agregar(usuario);
                                    break;
                                }
                               case 6:
                                   break;
                               default:
                                   break;
                            }
                            opc=1;
                            break;
                        }
                        case 2:{
                            cout << grafo.amigostostring(usuario);
                            break;
                        }
                        case 3:{
                            cin.ignore();
                            string nombre_amigo;
                            cout << "Ingrese el nombre del usuario a amistar: " << endl;
                            getline(cin,nombre_amigo);
                            Vertice* amigo=grafo.buscaVertice(nombre_amigo);
                            if(amigo){
                                grafo.insertaArista(usuario,amigo);
                            }
                            else{
                                cout << "El usuario no existe." << endl;
                            }
                            break;
                        }
                        case 4:{
                            cin.ignore();
                            string nombre_amigo;
                            cout << "Ingrese el nombre del amigo a eliminar: " << endl;
                            getline(cin,nombre_amigo);
                            Vertice* amigo=grafo.buscaVertice(nombre_amigo);
                            if(amigo){
                                if(usuario->existe(usuario->buscaArista(amigo))){
                                    if(usuario->buscaArista(amigo)->getPonderacion()){
                                        usuario->eliminaArista(usuario->buscaArista(amigo));
                                        amigo->eliminaArista(amigo->buscaArista(usuario));
                                    }
                                    else{
                                        cout << "No haz aceptado la solicitud de este usuario" << endl;
                                    }
                                }
                                else{
                                    cout << "No eres amigo de este usuario" << endl;
                                }
                            }
                            else{
                                cout << "El usuario no existe." << endl;
                            }
                            break;
                        }
                        case 5:{
                            usuario->listasolicitudesdeamistad();
                            break;
                        }
                       case 6:{
                        cin.ignore();
                        string confirmacion;
                        cout << "Estas a punto de eliminar tu cuenta\nSi estas seguro de esto ingresa \"SI\":" << endl;
                        getline(cin,confirmacion);
                        if(confirmacion=="SI"){
                            areas.Remover(usuario);
                            grafo.eliminaVertice(usuario);
                            opc=7;
                        }
                           break;
                        }
                       default:
                           break;
                    }
                }while(opc!=7);
                opc=2;
                break;
            }
            case 3:{
                cout << grafo.toString() << endl;
                break;
            }
            case 4:{
                do{
                    print_areas_de_formacion();
                    cin >> opc;
                }while(opc<0 or opc>10);
                cout << "Area de " << areas.ImprimirLista(opc);
                opc=4;
                break;
            }
            case 5:
                break;
            default:
                cout << "NON" << endl;
            }
    }while(opc!=5);
    cout << "Exito!" << endl;
}

void print_areas_de_formacion(){
    cout << "0. Psicologia" << endl
         << "1. Educacion" << endl
         << "2. Sociedad" << endl
         << "3. Salud" << endl
         << "4. Sistemas computacionales" << endl
         << "5. Literatura" << endl
         << "6. Economia" << endl
         << "7. Transportes" << endl
         << "8. Entretenimiento" << endl
         << "9. Ingenieria" << endl;
}
