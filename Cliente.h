
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Persona.h"


using namespace std;



class Cliente: public Persona
{
	int edad;
	int DNI;
	int curso;

public:



	Cliente();



	Cliente(string nombre, string apellido, int edad, int DNI, int curso);

	

	virtual ~Cliente();
	


	int getEdad() const;


	int getDNI() const;


	int getCurso() const; 


	virtual void mostrarDatos() const;


	void setEdad(int edad);


	void setDNI(int DNI);


	void setCurso(int curso);

};

#endif




ostream& operator<<(ostream &out, const Cliente p);