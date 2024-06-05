#pragma once

#ifndef __PUNTO_H__

#define __PUNTO_H__



#include <string>

#include <sstream>



using namespace std;



class Punto {

	int x, y;

public:

	Punto(int x = 0, int y = 0)

		:x(x), y(y)

	{}



	std::string toString() {

		std::ostringstream ss;



		//Opcion 1:

		ss << "p(";

		ss << x;

		ss << ", ";

		ss << y;

		ss << ")";



		//Opcion 2:

		//ss << "p(" << x << ", " << y << ")";



		return(ss.str());

	}



	//REZC: Usado para Busqueda

	int getX() { return x; }

	int getY() { return y; }



};

#endif