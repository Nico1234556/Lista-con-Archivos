#pragma once
#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Dependencies.h"
#include <iostream>

template<class T>
class Lista {
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Lista() : inicio(NULL), longitud(0) {}

    ~Lista() {
        vaciar();
    }

    void insertarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor, inicio);
        inicio = nuevo;
        longitud++;
    }

    void insertarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (inicio == NULL) {
            inicio = nuevo;
        }
        else {
            Nodo<T>* temp = inicio;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
        longitud++;
    }

    void push(T valor) {
        insertarFinal(valor);
    }

    T pop() {
        if (longitud == 0) {
            cout << "Error: La lista está vacía\n";
            return NULL; // Retorna NULL para tipos de puntero, cambia según necesidades
        }

        if (longitud == 1) {
            T valor = inicio->valor;
            delete inicio;
            inicio = NULL;
            longitud--;
            return valor;
        }

        Nodo<T>* actual = inicio;
        while (actual->siguiente->siguiente != NULL) {
            actual = actual->siguiente;
        }

        T valor = actual->siguiente->valor;
        delete actual->siguiente;
        actual->siguiente = NULL;
        longitud--;
        return valor;
    }

    T obtenerUltimoSinEliminar() {
        if (longitud == 0) {
            std::cout << "Error: La lista está vacía\n";
            return NULL; // Cambia según las necesidades del tipo de dato
        }

        Nodo<T>* actual = inicio;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        return actual->valor;
    }

    int getTamano() const {
        return longitud;
    }

    T obtener(int indice) const {
        if (indice < 0 || indice >= longitud) {
            cout << "Error: Índice fuera de rango\n";
            return NULL; // Adecúa esto según tu gestión de errores y tipo de T
        }

        Nodo<T>* actual = inicio;
        for (int i = 0; i < indice; ++i) {
            actual = actual->siguiente;
        }
        return actual->valor;
    }

    void mostrar() const {
        if (inicio == NULL) {
            cout << "La lista está vacía.\n";
            return;
        }

        Nodo<T>* actual = inicio;
        while (actual != NULL) {
            cout << actual->valor->toString() << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL\n";
    }

    void ordenarBySeleccion() {
        if (inicio == nullptr || inicio->siguiente == nullptr) {
            return; // Lista vacía o con un solo elemento, ya está ordenada
        }

        Nodo<T>* nodo_i = inicio;
        while (nodo_i != nullptr) {
            Nodo<T>* minNodo = nodo_i;
            Nodo<T>* nodo_k = nodo_i->siguiente;

            while (nodo_k != nullptr) {
                if (nodo_k->valor != nullptr && minNodo->valor != nullptr) {
                    Ciudadano* Ciudadano_min = dynamic_cast<Ciudadano*>(minNodo->valor);
                    Ciudadano* Ciudadano_k = dynamic_cast<Ciudadano*>(nodo_k->valor);
                    if (Ciudadano_min && Ciudadano_k && Ciudadano_k->getsueldo() < Ciudadano_min->getsueldo()) {
                        minNodo = nodo_k;
                    }
                }
                nodo_k = nodo_k->siguiente;
            }

            // Intercambiar valores de nodo_i y minNodo
            if (minNodo != nodo_i) {
                T temp = nodo_i->valor;
                nodo_i->valor = minNodo->valor;
                minNodo->valor = temp;
            }

            nodo_i = nodo_i->siguiente;
        }
    }

   

    void vaciar() {
        while (inicio != NULL) {
            Nodo<T>* temp = inicio;
            inicio = inicio->siguiente;
            delete temp->valor; // Asumiendo que T es un puntero a objeto
            delete temp;
        }
        longitud = 0;
    }
};

#endif
