#ifndef _USUARIO_H
#define _USUARIO_H
#include <iostream>
#include "Persona.hpp"
#include <string.h>
using namespace std;

class Usuario
{
	string nombre;
	string apellido;
	int edad;
	string DNI;
	int curso;

public: 
	Usuario() {}

	Usuario(const string nombre, const string apellido, const int edad, const string DNI, const int curso);

	const string getNombre() const {return nombre;}
	const string getApellido() const {return apellido;}
	const int getEdad() const {return edad;}
	const string getDNI() const {return DNI;}
	const int getCurso() const {return curso;}

	friend istream& operator>>(istream& in, Cliente& c);

};

ostream& operator<<(ostream& out, const Cliente& c);

#endif

