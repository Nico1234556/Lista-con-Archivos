#pragma once
#ifndef __NODO_H__
#define __NODO_H__
template<class T>
class Nodo {
public:
	T valor;
	Nodo<T>* siguiente;
	Nodo<T>* anterior; // Agregar puntero al nodo anterior

	Nodo(T val) : valor(val), siguiente(nullptr), anterior(nullptr) {}

	Nodo(T val, Nodo<T>* sig, Nodo<T>* ant) : valor(val), siguiente(sig), anterior(ant) {}

};
#endif

