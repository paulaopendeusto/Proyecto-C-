#ifndef _CLIENTE_H
#define _CLIENTE_H
#include <iostream>
#include "Persona.hpp"
#include <string.h>
using namespace std;

class Cliente 
{
	int edad;
	int DNI;
	int curso;
	char *nombre;
	char *apellido;

public: 
	Cliente() {}

	Cliente(const char* nombre, const char* apellido, const int edad, int DNI, const int curso);

	const char* getNombre() const {return nombre;}
	const char* getApellido() const {return apellido;}
	const int getEdad() const {return edad;}
	const int getDNI() const {return DNI;}
	const int getCurso() const {return curso;}

	friend istream& operator>>(istream& in, Cliente& c);

};

ostream& operator<<(ostream& out, const Cliente& c);

#endif

