#ifndef HABITACIONES_H
#define HABITACIONES_H

#include "habitaciones.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

//Estructura del alumno
    struct HabitacionesC {

    char id[20];
    char idhabitacion[50];
    char idcama[50];      // Almacena el nombre  del alumno ingresado
};

class habitaciones
{
     private:
        string  id,idhabitacion,idcama;


    public:
        habitaciones(){}
        habitaciones(string id, string idhabitacion,string idcama);
        //Estableciendo la id
        string setid(string id);
        //obteniendo la id
        string getid();


        //Estableciendo el nombre
        string setidhabitacion(string idhabitacion);
        //obteniendo el nombre
        string Getidhabitacion();

         //Estableciendo el nombre
        string setidcama(string idcama);
        //obteniendo el nombre
        string getidcama();



 //Funciones

    void menuhabitaciones(); //Funcion menu para poder mostar el menu de alumnos

    void insertar(); //Funcion para insertar un nuevo alumno
    void desplegar(); //Funcion para poder desplegar los alumnos registrados
    void modificar(); //Funcion para modificar un alumno registrado
    void buscar(); //Funcion para poder buscar un alumno por medio de la id
    void borrar(); //Funcion para poder borrar algun alumno

};

#endif // HABITACIONES_H
