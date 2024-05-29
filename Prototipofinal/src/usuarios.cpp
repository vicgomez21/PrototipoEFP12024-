//Incluyendo librerias
#include <iostream>
#include <fstream>
#include <iomanip>
//Incluyendo datos
#include "usuarios.h"
#include "Login.h"
#include "Bitacora.h"

using namespace std;

//contructor usuarios con sus parametros
usuarios::usuarios(string nombre, string contra){


this->nombre = nombre;
this->contra = contra;




}
//Estableciendo nombre
string usuarios::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo nombre
string usuarios::getnombre()
{
    return nombre;
}

//Estableciendo contraseña
string usuarios::setcontra(string contra)
{
    this->contra = contra;
    return contra;
}

//obteniendo contraseña
string usuarios::getcontra()
{
    return contra;
}

//Funcion mostrar menu
void usuarios::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2100", "GUA"); // Parámetros

    //Variable opc
    int opc;
    //Bucle do while
    do
    {
        //Limpiando pantalla
        system("cls");

        //Diseño de la tabla de gestion de usuarios
        cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|        Gestion de Usuarios de Alumnos         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Usuario                 |"<<endl;
		cout<<"|            2. Mostrar Usuario                 |"<<endl;
		cout<<"|            3. Modificar Usuario               |"<<endl;
		cout<<"|            4. Borrar Usuario                  |"<<endl;
		cout<<"|            5. Regresar al menu                |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|         Ingrese su opcion [1/2/3/4/5]         |"<<endl;
		cout<<"+-----------------------------------------------+"<<endl;
        cin >> opc;

        //Switch opc
        switch(opc)
        {
        //Opcion 1
        case 1:
            //Funcion mostrar datos
            pideDatos();
            break;

        //Opcion 2
        case 2:
            //Funcion mostrar datos
            muestraDatos();
            break;

        //Opcion 3
        case 3:
            //Funcion editar datos
            editaDatos();
            break;

        //Opcion 4
        case 4:
            //Funcion borrar datos
            borraDatos();
            break;

        //Opcion 5
        case 5:
            break;
        }
    //Si es 5 regresa
    } while (opc!=5);

}

//Funcion pedir datos
void usuarios::pideDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2102", "USPD"); // Parámetros

    //Limpiar pantalla
    system("cls");

    //Encabezado
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Agregar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Instancia de la clase usuarios
    Usuarios usuario;

    //Obteniendo datos
    cout<<"       -> Ingrese un nombre: ";
    cin.ignore();
    cin.getline(usuario.nombre, 80);
    cout<<"       -> Ingrese una contrasena: ";
    cin.getline(usuario.contra, 80);

    // Abre el archivo "Usuario.dat" en modo de escritura binaria, añadiendo datos al final del archivo
    ofstream archivo("Usuario.dat", ios::binary | ios::app);

    // Escribe el contenido de la estructura usuario en el archivo
    archivo.write(reinterpret_cast<const char*>(&usuario), sizeof(usuario));

    // Cierra el archivo después de escribir
    archivo.close();
}

//Funcion mostrar datos
void usuarios::muestraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2102", "USMD"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Encabezado mostrar detalles
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|        Mostrar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //crea un archivo usuario dat en modo binario y en lectura
    ifstream archivo("Usuario.dat", ios::binary | ios::in);
    if(!archivo)
    {
        //Si no hay informacion muestra lo siguiente
        cout << "No hay informacion registrada";
        return;
    }
        //Instancia de usuarios
        Usuarios usuario;

        // Bucle para leer los datos del archivo "Usuario.dat" registro por registro
        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
        {
            cout<<"       -> Nombre de usuario: "<< usuario.nombre << endl;
            cout<<"       -> Contrasena usuario: "<<usuario.contra << endl;
            cout << "+---------------------------------------------------------+" << endl;
        }
            //Cierra el archivo
            archivo.close();


    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//Funcion editar datos
void usuarios::editaDatos()
 {
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2103", "USED"); // Parámetros

    //Limpiando pantalla
    system("cls");

    //Variables fstram y string
    fstream archivo;
    string nom;
    //Variable bool
    bool encontrado = false;

    //Encabezado editar detalles
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|         Editar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Abre archivo usuario.dat en binario y en lectura
    archivo.open("Usuario.dat",ios::binary | ios::in | ios::out);
    if(!archivo){

        //Si no hay informacion muestra lo siguiente
        cout << "No hay informacion registrada";
        return;
    }
        //0bteniendo nombre
        cout << "Ingrese el nombre del usuario que quiera modificar: ";
        cin >> nom;

        //Instancia de usuarios
        Usuarios usuario;


        // Bucle para leer los datos del archivo "Usuario.dat" registro por registro
        while (archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios))) {
        if (usuario.nombre == nom) {
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo nombre del usuario: ";
            cin >> usuario.nombre;
            cout << "Ingrese la nueva contraseña del usuario: ";
            cin >> usuario.contra;


            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo.seekp(-static_cast<int>(sizeof(Usuarios)), ios::cur);

            // Escribe  nuevos detalles del estudiante en el archivo
            archivo.write(reinterpret_cast<char*>(&usuario), sizeof(Usuarios));
            break;
        }
    }

    archivo.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un usuario con el nombre proporcionado." << endl;
    }

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion borrar datos
void usuarios::borraDatos()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2104", "USBD"); // Parámetros

    //Limpiando pantalla
   	system("cls");

    //Variable string
	string nom;

    //Encabezado eliminar detalles
	cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|       Eliminar detalles del Usuario de Alumnos          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Abre un archivo en binario
    ifstream archivo("Usuario.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Usuario2.dat", ios::binary);
	Usuarios usuario;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el nombre de la persona que desea eliminar: ";
    cin>>nom;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&usuario), sizeof(Usuarios)))
		{
		    // Si el nombre del usuario no coincide con el proporcionado, se escribe en el nuevo archivo
			if(usuario.nombre != nom)
			{
			    // Escribe los datos de la estructura usuario en el archivo archivo2
				archivo2.write(reinterpret_cast<const char*>(&usuario), sizeof(Usuarios));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

        //remueve el Alumnos.dat
		remove("Usuario.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Usuario2.dat","Usuario.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Usuario eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el nombre del Usuario" << endl;
        }
}



