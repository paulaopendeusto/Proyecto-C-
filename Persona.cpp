#include "Persona.hpp"
#include "string.h"

using namespace std;

Persona::Persona()
{

}

Persona::Persona(const char *nombre, const char *apellido)
{
	this->nombre= new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);

	this->apellido=new char[strlen(apellido)+1];
	strcpy(this->apellido, apellido);
}

Persona::Persona(const Persona& p)
{
	this->nombre= new char[strlen(p.nombre)+1];
	strcpy(this->nombre, p.nombre);

	this->apellido= new char[strlen(p.apellido)+1];
	strcpy(this->apellido, p.apellido);
}

Persona::~Persona()
{
	delete[] nombre;
	delete[] apellido;
}

const char* Persona::getNombre() const
{
	return nombre;
}

const char* Persona::getApellido() const
{
	return apellido;
}