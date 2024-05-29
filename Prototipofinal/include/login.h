//Encabezados de proteccion
#ifndef LOGIN_H
#define LOGIN_H
//Librerias
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <cstring>
//Encabezados
#include "Bitacora.h"
#include "usuarios.h"

using namespace std;


class Login {
//Atributos privados
private:
    static string usuarioActual; // Variable est�tica para almacenar el usuario actual
    string nombre; // Nombre de usuario
    string contra; // Contrase�a de usuario
    int maxintentos; // N�mero m�ximo de intentos permitidos para iniciar sesi�n
    int contintentos; // Contador de intentos de inicio de sesi�n
//Atributos publicos
public:
    // Constructor de la clase Login con valores predeterminados
    Login(string nombre = "", string contra = "", int intentos = 3);

    // Funciones para establecer y obtener el nombre de usuario
    void setnombre(string nombre);
    string getnombre() const;

    // Funciones para establecer y obtener la contrase�a de usuario
    void setcontra(string contra);
    string getcontra() const;

    // Funci�n para validar el inicio de sesi�n
    bool validacion();

    // Funci�n para restablecer el contador de intentos de inicio de sesi�n
    void resetintentos();

    // Funci�n est�tica para obtener el usuario actual
    static string getUsuarioActual() {
        return usuarioActual;
    }
};

#endif // LOGIN_H
