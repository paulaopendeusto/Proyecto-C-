#ifndef _ADMIN_HPP
#define _ADMIN_HPP

#include "Persona.hpp"

class Admin: public Persona
{
	char *usuario;
	char* contrasenya;

public:
	Admin(const char* nombre, const char* apellido, const char* usuario, const char* contrasenya);
	Admin(const Admin &a);
	~Admin();

	const char* getUsuario();
	const char* getContrasenya();
};

#endif