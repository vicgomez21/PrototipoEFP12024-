#ifndef ASIGNACION-DE-RESULTADOS _H
#define ASIGNACION-DE-RESULTADOS _H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include"asignaciom_de_resultados.h"
using namespace std;

struct Asignacion{


char id_habitacion[15];
char id_tipohabitacion[15];
char id_tipocama[15];


    char precio[11];
        char estado[11];
    int acta;
};


class asignaciom_de_resultados
{
    public:
        asignacion_de_resultados ();


    void Menu();
    void asignarse_resultado();
    void actas();
    void imprimir_acta();

};

#endif // ASIGNACION-DE-RESULTADOS _H
