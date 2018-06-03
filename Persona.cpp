#include "Persona.h"

using namespace std;

Persona::Persona()
{
	this->nombre = string(""); 
	this->apellido = string("");

}

Persona::Persona(string nombre, string apellido)
{
	this->nombre = nombre;
	this->apellido = apellido;
}

Persona::~Persona()
{}

string Persona::getNombre() const
{
	return nombre;
}
string Persona::getApellido() const
{
	return apellido;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Persona::setApellido(string apellido)
{
	this->apellido = apellido;
}
