#infndef _PERSONA_H
#define _PERSONA_H

class Persona
{
	char *nombre;
	char *apellido;

public:

	Persona();
	Persona(const char*nombre, const char* apellido);
	Persona(cons Persona &p);
	virtual ~Persona();

	const char* getNombre() const;
	const char* getApellido() const;
	
};

#endif