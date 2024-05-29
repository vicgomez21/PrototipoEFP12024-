#include "asignaciom_de_resultados.h"

#include "login.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include<iomanip>
//Implementación de Bitácora realizado por: Pablo Romeo Palencia Rosales 9959-23-736
#include "Bitacora.h"
#include"habitaciones.h"

using namespace std;
string users;

void asignaciom_de_resultados::Menu()
{//Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "4500", "ADR"); // Parámetros
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|      BIENVENIDO AL MENU PROCESO      |"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignacion De Habitaciones               |"<<endl;
	cout<<"\t\t\t|2. Actas                                  |"<<endl;
	cout<<"\t\t\t|4. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3]                |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:

         {
          asignarse_resultado();
            //Realiza el proceso de asignar maestro a curso y se registra en la bitacora
            bitacora.ingresoBitacora(usuarioActual,"4002","ASG"); //ASG = Asignación de resultados
            //mandamos a auditoria un ingreso a la bitacora que registra el usuario que realiza dicha accion, el codigo de proceso y la accion que hace
            break;
        }


    case 2:
        {
            actas();
            //Realiza el proceso de imprimir las actas y luego se registra en la bitacora
           bitacora.ingresoBitacora(usuarioActual,"4002","DAC"); //DAC = Despliega Actas
            //mandamos al usuario, el codigo del proceso/accion y 3 letras que resumen la accion
            break;

        }
 case 3:


            break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;}
        }while(opcion!= 3);

    }

void asignaciom_de_resultados::asignarse_resultado()
 {
     system("cls");
    char res='S'; //variable que controla la validacion: Pablo Palencia 9959-23-736

//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;



/* **********   DESPLIEGUE Deportes.DAT   ********** */
    cout<<"---------------- Habitaciones existentes---------------------"<<endl;
    ifstream archivo11("habitaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo11) {
        cout << "No hay habitaciones registradas." << endl;
        return;
    }
    HabitacionesC habitaciones1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo11.read(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC))) {

        cout << num<< ". " << habitaciones1.id <<"-|- "<<habitaciones1.idhabitacion<<"-|- "<<habitaciones1.idcama<<endl;

        num++;
    }
    archivo11.close(); // Cerrar el archivo

do
{
    string ideporte;
    cout<<"ingrese codigo de la habitacion : ";
    cin >> ideporte;
    fstream archivo25("habitaciones.dat", ios::binary | ios::in | ios::out);
    if (!archivo25) {
        cout << "No hay habitaciones registrados." << endl;
        return;
    }
    HabitacionesC habitaciones1;
    bool encontrada = false;
    while (archivo25.read(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC))) {
        if (habitaciones1.id == ideporte) {
            archivo25.seekp(-static_cast<int>(sizeof(HabitacionesC)), ios::cur);
            strcpy(Asigna.id_habitacion,(ideporte).c_str());
             strcpy(Asigna.id_tipohabitacion,(habitaciones1.idhabitacion));
             strcpy(Asigna.id_tipocama,(habitaciones1.idcama));
            cin.ignore();
            encontrada = true;
             res='N';
            break;
        }
    }
    archivo25.close();
    if (!encontrada) {
        cout << "No se encontro la habitacion registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
            system("cls");

string marcador1="";
string marcador2="";
cout <<"ingrese el Precio de la habitacion  :"<<endl;
    cin >> marcador1;
     strcpy(Asigna.precio,(marcador1).c_str());
cout <<"ingrese el Estado de la habitacion  :"<<endl;
    cin >> marcador2;
     strcpy(Asigna.estado,(marcador2).c_str());




    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
    cout << "------------------------------------------------" << endl;

    // Mostrar el número de acta
    cout<<"Numero de Acta: " <<Asigna.acta<<endl;
    cin.ignore();

         system("cls");


}

void asignaciom_de_resultados::actas()
{
    system("cls");
    cout<<"------------------ ASIGNACIONES DE HABITACIONES --------------------"<<endl<< endl;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("asignaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    Asignacion asign1;
    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
cout << "NO. Acta: "<<   asign1.acta<< endl;
cout<<"habitacion: "<< asign1.id_habitacion<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;
cout<<"|    " <<"Codigo de Tipo de habitacion:   "<< asign1.id_tipohabitacion<<endl;
cout<<"|    " <<"Nombre del  Tipo de cama:   "<< asign1.id_tipocama<<endl;
cout<<"|    " <<"PRECIO:   "<< asign1.precio<<endl;
cout<<"|    " <<"Estado:   "<< asign1.estado<<endl;
cout<<"--------------------------------------------------------------------------------------"<<endl;

cout<<"************************************************************************************************"<<endl;
    }

    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

