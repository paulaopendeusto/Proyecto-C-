#include "Cliente.hpp"
#include <iostream>
#include <string.h>
#include <ctype.h>

Cliente::Cliente(const string nombre, const string apellido, const int edad, const string DNI, const int curso)
{
	this->nombre= nombre;
	this->apellido=apellido;
	this->edad=edad;
	this->DNI=DNI;
	this->curso=curso;
}

istream& operator<<(istream& in, Cliente& c)
{
	cout << "Nombre: ";
	cin >> c.nombre;
	cout << "Apellido: ";
	cin >> c.apellido;
	cout << "Edad: ";
	cin >> c.edad;
	cout << "DNI: ";
	cin >> c.DNI;
	cout << "Curso: ";
	cin >> c.curso;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Cliente& c)
{
	out << c.getNombre() << " " << c.getApellido() << " " << c.getEdad() << " " << c.getDNI() << " " << c.getCurso();

	return out;
}