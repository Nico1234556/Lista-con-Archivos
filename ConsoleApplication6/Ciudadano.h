#pragma once
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Dependencies.h"

class Ciudadano {

private:
    //dni, edad, nombre, apellido, distrito, sueldo, teléfono.
    int DNI;

    int edad;

    string nombre;

    string apellido;

    string distrito;

    int sueldo;

    int telefono;



public:

    Ciudadano(int DNI, int edad, string nombre, string apellido, string distrito, int sueldo, int teléfono) :

        DNI(DNI), edad(edad), nombre(nombre), apellido(apellido), distrito(distrito), sueldo(sueldo), telefono(teléfono) {}

    string toString() const {

        ostringstream ss;

        ss << "DNI: " << DNI << ", Edad: " << edad << ", Nombre: " << nombre << ", Apellido: " << apellido << ", Distrito: " << distrito << ", Sueldo: " << sueldo << ", Telefono: " << telefono << ")";

        return ss.str();

    }

    // Getters

    int getDNI() const { return DNI; }

    int getEdad() const { return edad; }

    string getnombre() const { return nombre; }

    string getapellido() const { return apellido; }

    string getdistrito() const { return distrito; }

    int getsueldo() const { return sueldo; }

    int gettelefono() const { return telefono; }



    // Setters

    void setDNI(int dni) { DNI = dni; }

    void setEdad(int e) { edad = e; }

    void setnombre(string n) { nombre = n; }

    void setapellido(string a) { apellido = a; }

    void setdistrito(string d) { distrito = d; }

    void setsueldo(int s) { sueldo = s; }

    void settelefono(int tel) { telefono = tel; }



    ~Ciudadano() {}





};



#endif