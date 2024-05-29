//Encabezados de proteccion
#ifndef USUARIOS_H
#define USUARIOS_H
//Librerias
#include <iostream>


using namespace std;

//Estructura usuarios
struct Usuarios {
    char nombre[80]; // Almacena el nombre de usuario.
    char contra[80]; // Almacena la contrase�a del usuario.
};

// Declaraci�n de la clase usuarios para gestionar usuarios en el sistema.
class usuarios {
//Atributos privados
private:
    string nombre, contra; // Nombre y contrase�a del usuario.
//Atributos publicos
public:
    // Constructores
    usuarios(){} // Constructor predeterminado
    usuarios(string nombre, string contra); // Constructor con par�metros

    // M�todos para establecer y obtener el nombre del usuario
    string setnombre(string nombre);
    string getnombre();

    // M�todos para establecer y obtener la contrase�a del usuario
    string setcontra(string contra);
    string getcontra();

    // M�todos para la gesti�n de usuarios
    void menu(); // Men� de opciones para la gesti�n de usuarios
    void pideDatos(); // M�todo para solicitar datos de usuario
    void muestraDatos(); // M�todo para mostrar datos de usuario
    void editaDatos(); // M�todo para editar datos de usuario
    void borraDatos(); // M�todo para eliminar datos de usuario
};

#endif // USUARIOS_H
