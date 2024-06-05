#include "pch.h"
#include "Dependencies.h"
#include "Administrador.h"
#include "Lista.h"
#include <iostream>
#include <string>
#include <functional>
#include "Ciudadano.h"
#include "Pila.h"
#include "Archivos.h"

using namespace System;
using namespace std;

int generarNumeroAleatorio(int min, int max) {
    return min + rand() % ((max + 1) - min);
}

//dni, edad, nombre, apellido, distrito, sueldo, teléfono.
Ciudadano* generarDatosAleatorios() {
    int DNI = generarNumeroAleatorio(10000000, 99999999);
    int edad = generarNumeroAleatorio(18, 90);

    string nombre;
    switch (rand() % 6) {
    case 0: nombre = "Lisa"; break;
    case 1: nombre = "Juan"; break;
    case 2: nombre = "Pablo"; break;
    case 3: nombre = "Celeste"; break;
    case 4: nombre = "Claudia"; break;
    case 5: nombre = "Felipe"; break;
    }

    string apellido;
    switch (rand() % 6) {
    case 0: apellido = "Perez"; break;
    case 1: apellido = "Garcia"; break;
    case 2: apellido = "Ramirez"; break;
    case 3: apellido = "Ortiz"; break;
    case 4: apellido = "Alarcon"; break;
    case 5: apellido = "Alvarez"; break;
    }

    string distrito;
    switch (rand() % 5) {
    case 0: distrito = "Lima"; break;
    case 1: distrito = "Magdalena"; break;
    case 2: distrito = "Pueblo libre"; break;
    case 3: distrito = "Miraflores"; break;
    case 4: distrito = "Barranco"; break;
    }

    int sueldo = generarNumeroAleatorio(500, 5000);
    int telefono = generarNumeroAleatorio(912345679, 999999999);

    return new Ciudadano(DNI, edad, nombre, apellido, distrito, sueldo, telefono);
}

// Función para generar datos para "n" jóvenes
void generarDatosJovenes(Lista<Ciudadano*>& listaEstudiantes, int n) {
    // Inicializa la semilla aleatoria
    srand(time(0));

    // Genera datos para "n" jóvenes y los agrega a la lista de estudiantes
    for (int i = 0; i < n; ++i) {
        Ciudadano* nuevoCiudadano = generarDatosAleatorios();
        listaEstudiantes.insertarFinal(nuevoCiudadano);
    }
}

void mostrarmenu() {
    cout << "\n========================================\n";
    cout << "===            Menu BONOPAY          ===\n";
    cout << "========================================\n\n";
    cout << "1. Registrar ciudadanos\n";
    cout << "2. ciudadanos que recibiran Bono\n";
    cout << "3. Ordenar ciudadanos por sueldo\n";
    cout << "4. Salir\n";
    cout << "========================================\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    Pila<Ciudadano*> pilaBanco;
    Lista<Ciudadano*> listaCiudadanos;

    int n;
    int opcion;
    Administrador admin("admin123");

    // Solicitar inicio de sesión del administrador
    if (!admin.inicioSesion()) {
        cout << "Demasiados intentos fallidos. Saliendo del sistema.\n";
        return 1; // Salir del programa si hay demasiados intentos fallidos
    }
    system("cls");
    do {
        mostrarmenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            cout << "\n*Registro de Ciudadanos y Escritura en Archivo*\n";
            do {
                cout << "Ingrese el numero de ciudadanos a generar (entre 100 y 1000): ";
                cin >> n;
            } while (n < 100 || n > 1000);

            generarDatosJovenes(listaCiudadanos, n);

            for (int i = 0; i < n; ++i) {
                Ciudadano* persona = listaCiudadanos.obtener(i);
                cout << "Ciudadano " << i + 1 << ": " << persona->toString() << endl;
            }

            // Escribir datos en el archivo
            escrituraDatosEnArchivo(listaCiudadanos);
            break;

        case 2:
            system("cls");
            cout << "\n*Lectura de Ciudadanos del Archivo*\n";
            lecturaDatosDeArchivo(listaCiudadanos);

            for (int i = 0; i < listaCiudadanos.getTamano(); ++i) {
                Ciudadano* persona = listaCiudadanos.obtener(i);
                cout << "Ciudadano " << i + 1 << ": " << persona->toString() << endl;
            }
            break;

        case 3:
            system("cls");
            cout << "Ciudadanos que recibiran Bono\n";
            for (int i = 0; i < listaCiudadanos.getTamano(); ++i) {
                Ciudadano* persona = listaCiudadanos.obtener(i);
                if (persona->getEdad() >= 30 && persona->getEdad() <= 75 && persona->getsueldo() < 1000) {
                    pilaBanco.push(persona);
                    cout << "Ciudadano " << i + 1 << ": " << persona->toString() << endl;
                }
            }
            break;

        case 4:
            system("cls");
            cout << "\nOrdenado por Seleccion:\n";
            listaCiudadanos.ordenarBySeleccion();
            listaCiudadanos.mostrar();
            break;

        default:
            break;
        }

    } while (opcion != 5);

    return 0;
}
