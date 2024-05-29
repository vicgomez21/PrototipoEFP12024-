#include "habitaciones.h"


//Incluyendo las librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//Incluyendo el encabezado de bitacora
#include "Bitacora.h"
#include "Login.h"

using namespace std;

//Constructor alumnos y sus parametros
habitaciones::habitaciones(string id, string idhabitacion,string idcama)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->id = id;
    this->idhabitacion = idhabitacion;
    this->idcama=idcama;


}



string habitaciones::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniend deporte id
string habitaciones::getid()
{
    return id;
}

//Estableciendo el nombre del deporte
string habitaciones::setidhabitacion(string idhabitacion)
{
    this->idhabitacion = idhabitacion;
    return idhabitacion;
}


//Obteniendo el nombre del deport
string habitaciones::Getidhabitacion()
{
    return idhabitacion;
}

//Estableciendo el nombre del deporte
string habitaciones::setidcama(string idcama)
{
    this->idcama = idcama;
    return idcama;
}


//Obteniendo el nombre del deport
string habitaciones::getidcama()
{
    return idcama;
}
void habitaciones::menuhabitaciones()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "1500", "MDD"); // Parámetros

    //Definiendo Variable int
    int opcion;
    //Definiendo Variable char
	char continuar;

	do
    {
        //Limpiando pantalla
		system("cls");

		//Se muestra el diseño del sistema de gestion de deporte
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE HABITACIONES  |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|            1. Agregar habitacion                  |"<<endl;
		cout<<"|            2. Mostrar habitacion                   |"<<endl;
		cout<<"|            3. Modificar habitacion                  |"<<endl;
		cout<<"|            4. Borrar habitacion                     |"<<endl;
		cout<<"|            5. Regresar al menu                      |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]              |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cin>>opcion;

        //Permitiendo que el usuario eliga una opcion
		switch(opcion)
		{
		    //Opcion 1
			case 1:
				do
				{
				    //Funcion para insertar un deporte
					insertar();
					//Luego de ingresar un deporte mostrara el mensaje
					cout<<" -> ¿Deseas ingresar a otra habitacion? (S/N): ";
					cin>>continuar;

                //Si la respuesta es s o S, insertara otro habitacion
				}while(continuar=='S' || continuar=='s');
				break;

            //Opcion 2
			case 2:
			    //Funcion para poder desplegar los deporte registrados
                desplegar(  );
				break;

            //Opcion 3
			case 3:
			    //Funcion para modificar un habitacion registrado
                modificar();
				break;

            //Opcion 4
			case 4:
			    //Funcion para borrar un habitacion registrado

                borrar();
                break;

            case 5:
				break;
				//Si no elige una de las 5 opciones, mostrara el siguiente mensaje
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 5);
}

//Funcion para insertar un deporte
void habitaciones::insertar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "1501", "IDD"); // Parámetros


    //Limpiando pantalla
    system("cls");

    //Encabezado del diseño insertar deporte
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles de la habitacion          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Inicializando un generador de numeros aleatorios
    srand(time(NULL));

    //Constructor
    HabitacionesC habitaciones;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "5050-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        habitaciones.id[i] = idString[i];
    }
    habitaciones.id[idString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Generando id de la habitacion: " << habitaciones.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del deporte
    cout<<"       -> Ingrese el id de tipop de habitacion :  ";
    cin.getline(habitaciones.idhabitacion   , 50);

    //Mensaje para ingresar el nombre del deporte
    cout<<"       -> Ingrese el id de tipo de cama:  ";
    cin.getline(habitaciones.idcama, 50);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto deporte en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("habitaciones.dat", ios::binary | ios::app);
    /** \brief
     *
     * \param deporte1
     * \return archivo.write(reinterpret_cast<const char*>(&deporte1),
     *
     */
    archivo.write(reinterpret_cast<const char*>(&habitaciones), sizeof(habitaciones));
    archivo.close();
}

void habitaciones::desplegar()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "5002", "DDD"); // despliege de deporte

    //Limpiando pantalla
    system("cls");


    //Mostrando el encabezado de la tabla de detalles del deporte
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles de habitaciones                 +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    ifstream archivo3("habitaciones.dat", ios::binary | ios::in);

    if (!archivo3){
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }

    // instancia de la clase Deporte llamada deporte
    HabitacionesC habitaciones1;


    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
  while (archivo3.read(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC))) //archivo.read(reinterpret_cast<char*>(&procealumnos), sizeof(Procealumnos)) &&
    {

        //Se muestra los detalles del deporte
        cout << "                        Mostrando -> ID de la habitacion: " << habitaciones1.id << endl;
        cout << "                        Mostrando -> ID Tipo de habitacion: " << habitaciones1.idhabitacion << endl;
        cout << "                        Mostrando -> ID Tipo de cama: " << habitaciones1.idcama << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los deporte ya registrados
void habitaciones::modificar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "5003", "MDD"); // modificacion de deporte


    //Limpiando pantalla
	system("cls");
	//Declarando variables tipo fstream y string
    fstream archivo1;
    string idDeporte;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del Deporte                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo1.open("habitaciones.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo1) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID de la habitacion que desea modificar : ";
    cin >> idDeporte;

    HabitacionesC habitaciones1;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario
    while (archivo1.read(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC))) {
        if (habitaciones1.id == idDeporte) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo ID de la habitacion: ";
            cin >> habitaciones1.id;
            cout << "Ingrese el nuevo ID del tipo de habitacion: ";
            cin >> habitaciones1.idhabitacion;
           cout << "Ingrese el nuevo ID del tipo de Cama: ";
            cin >> habitaciones1.idcama;
            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo1.seekp(-static_cast<int>(sizeof(HabitacionesC)), ios::cur);

            // Escribe  nuevos detalles del deporte en el archivo
            archivo1.write(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró una Habitacion con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//funcion para borrarr a las alumnos registradas
void habitaciones::borrar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "5004", "BDD"); // Parámetros


    //Limpia pantalla
	system("cls");
	//declara una variable string
	string idDeporte;

	//Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Habitaciones                                       +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario deporte.dat en modo de lectura
    ifstream archivo("habitaciones.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("habitaciones2.dat", ios::binary);

	HabitacionesC habitaciones1;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID de la habitacion que desea eliminar: ";
    cin>>idDeporte;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&habitaciones1), sizeof(HabitacionesC)))
		{
		    // Si el nombre del deporte no coincide con el proporcionado, se escribe en el nuevo archivo
			if(habitaciones1.id != idDeporte)
			{
				archivo2.write(reinterpret_cast<const char*>(&habitaciones1), sizeof(HabitacionesC));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

        //remueve el Deportes.dat
		remove("habitaciones.dat");

        //y renombra el deporte2.dat a deporte.dat
		rename("habitaciones2.dat","habitaciones.dat");

		if (resta)
        {
        //Si se encuentra el deporte muestra el mensaje
        cout << "Deporte eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el deporte muestra el mensaje
        cout << "No se a podido encontrar el codigo de la habitacion" << endl;
        }
}
//----------------------------------------------------------------------------------------------------------------------------------------------
