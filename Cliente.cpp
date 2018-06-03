#include "Cliente.h"


using namespace std;


Cliente::Cliente(): Persona()
{
	this->edad = 0;
	this->DNI = 0;
	this->curso = 0;
}
Cliente::Cliente(string nombre, string apellido, int edad, int DNI, int curso): Persona(nombre, apellido)
{
	this->edad = edad;
	this->DNI = DNI;
	this->curso = curso;
	
}

Cliente::~Cliente()
{}


int Cliente::getEdad() const
{
	return edad;
}
int Cliente::getDNI() const
{
	return DNI;
}
int Cliente::getCurso() const
{
	return curso;
}

void Cliente::mostrarDatos() const
{
	cout << "Datos del Cliente: (" << this->edad <<","<<this->DNI << "," <<this->curso <<")" << endl;
}

void Cliente::setEdad(int edad)
{
	this->edad = edad;
}
void Cliente::setDNI(int DNI)
{
	this->DNI = DNI;
}
void Cliente::setCurso(int curso)
{
	this->curso = curso;
}



ostream& operator<<(ostream &out, const Cliente p)
{
	out << "\t" << p.getNombre() << endl;
	return out;
}