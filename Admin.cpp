#include "Admin.hpp"
#include <iostream>
#include <string.h>

using namespace std;

Admin::Admin(const char* nombre, const char* apellido, const char* usuario, const char* contrasenya): Persona(nombre, apellido)
{
	this->usuario=new char[strlen(usuario)+1];
	strcpy(this->usuario, usuario);
	this->contrasenya=new char[strlen(contrasenya)+1];
	strcpy(this->contrasenya, contrasenya);
}

Admin::Admin(const Admin &a)
{
	this->usuario=new char[strlen(usuario)+1];
	strcpy(this->usuario, a.usuario);
	this->contrasenya=new char[strlen(contrasenya)+1];
	strcpy(this->contrasenya, a.contrasenya);
}

Admin::~Admin()
{
	delete[] usuario;
	delete[] contrasenya;
}

const char* Admin::getUsuario()
{
	return usuario;
}

const char* Admin::getContrasenya()
{
	return contrasenya;
}