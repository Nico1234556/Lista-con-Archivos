#pragma once

#ifndef __PILA_H__

#define __PILA_H__

#include "Nodo.h"



// En Pila.h

template<class T>

class Pila {

private:

    Nodo<T>* cima;



public:

    Pila() : cima(nullptr) {}



    void push(T v) {

        Nodo<T>* nuevo = new Nodo<T>(v);

        cima = nuevo;

    }



    T pop() {

        if (cima != nullptr) {

            Nodo<T>* temp = cima;

            T valor = temp->valor;

            cima = cima->siguiente;

            delete temp;

            return valor;

        }

        return T(); // Valor por defecto de T

    }



    bool isEmpty() const {

        return cima == nullptr;

    }

};



#endif