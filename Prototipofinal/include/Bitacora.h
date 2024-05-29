//Encabezado de proteccion
#ifndef BITACORA_H
#define BITACORA_H
//Librerias
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

//Incluyendo encabezados
#include "usuarios.h"
using namespace std; // Uso del espacio de nombres est�ndar

// Estructura registro bitacora
struct RegistroBitacora {

    char accion[80]; // Acci�n realizada
    char aplicacion[80]; // Aplicaci�n en la que se realiz� la acci�n
    char nombre[80]; // Nombre del usuario
    char fechaHora[80]; // Fecha y hora de la acci�n
};

// Clase bitacora
class Bitacora {
//Atributos publicos
public:
    // Funci�n para registrar una entrada en la bit�cora
    void ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso);

    // Funci�n para mostrar la bit�cora
    void mostrarBitacora();

};

#endif // BITACORA_H

