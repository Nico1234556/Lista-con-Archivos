#include <fstream>	//Gestion de Archivo
#include <string>	//getline
#include <sstream>	//stream
#include "Dependencies.h"
#include "Lista.h"
#include "Ciudadano.h"

#define nombre_archivo "cuidadanos.csv"
Lista<Ciudadano*> listaCiudadanos;

void lecturaDatosDeArchivo(Lista<Ciudadano*>& listaCiudadanos)
{
    ifstream archIN;
    archIN.open(nombre_archivo, ios::in); // Apertura

    if (!archIN.is_open())
    {
        cout << "Error: No se pudo abrir el archivo !!!" << endl;
        exit(1);
    }

    string linea;
    char delimitador = '|'; // Separador de cada columna de la línea

    // Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
    getline(archIN, linea);

    // Contenido: Leemos todas las líneas
    while (getline(archIN, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream

        string dni, edad, nombre, apellido, distrito, sueldo, telefono;
        getline(stream, dni, delimitador);
        getline(stream, edad, delimitador);
        getline(stream, nombre, delimitador);
        getline(stream, apellido, delimitador);
        getline(stream, distrito, delimitador);
        getline(stream, sueldo, delimitador);
        getline(stream, telefono, delimitador);

        // Crear un nuevo objeto Ciudadano y añadirlo a la lista
        Ciudadano* nuevoCiudadano = new Ciudadano(stoi(dni), stoi(edad), nombre, apellido, distrito, stoi(sueldo), stoi(telefono));
        listaCiudadanos.insertarFinal(nuevoCiudadano);
    }

    // Cerramos el archivo
    archIN.close();
}


void escrituraDatosEnArchivo(const Lista<Ciudadano*>& listaCiudadanos)
{
    ofstream archOUT;
    archOUT.open(nombre_archivo, ios::out); // Apertura

    if (!archOUT.is_open())
    {
        cout << "Error: No se pudo abrir el archivo !!!" << endl;
        exit(1);
    }

    // Escribimos el encabezado
    archOUT << "dni|edad|nombre|apellido|distrito|sueldo|teléfono" << endl;

    // Escribimos los datos de cada ciudadano
    for (int i = 0; i < listaCiudadanos.getTamano(); ++i)
    {
        Ciudadano* persona = listaCiudadanos.obtener(i);
        archOUT << persona->getDNI() << "|"
            << persona->getEdad() << "|"
            << persona->getnombre() << "|"
            << persona->getapellido() << "|"
            << persona->getdistrito() << "|"
            << persona->getsueldo() << "|"
            << persona->gettelefono() << endl;
    }

    // Cerramos el archivo
    archOUT.close();
    cout << "Datos escritos en el archivo " << nombre_archivo << " exitosamente." << endl;
}