#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <string.h>

#include <string>
#include <iostream>

using namespace std;

class Persona
{
protected:
	string nombre;
	string apellido;
	
public:



	Persona();


	Persona(string nombre, string apellido);


	virtual ~Persona();


	string getNombre() const;


	string getApellido() const;


	void setNombre(string nombre);


	void setApellido(string apellido);


	virtual void mostrarDatos() const = 0;
};

#endif