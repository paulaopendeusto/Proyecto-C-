#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gestion.h"
#include "gestion.hpp"
#include "Persona.hpp"
#include "Admin.hpp"
#include "Cliente.hpp"
#include "DBConnector.hpp"

#define MAX_LENGHT 50

using namespace std;
//CLIENTE://
int dni;
string nombre;
string apellido;
int edad;
int curso;

//LIBRO//
int codigo;
string titulo; 
string autor;
string genero;
int stock;

int menuCliente(void)
{
	char str[MAX_LENGHT];
	int option;
	int len;
	do
	{
		
		printf("Usted ha entrado como cliente\n");
		printf("\n");
		
		
		printf("1. Lista de libros disponibles para alquilar\n");
		printf("2. Alquilar libro\n");
		printf("3. Darse de baja de la aplicacion\n");
		printf("4. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '4') || (len > 0 && (option > 4 || option < 1)));
	
	return (str[0] == '4')?0:option;

}

int menuAdministrador(void)
{
	char str[MAX_LENGHT];
	int option;
	int len;
	do
	{
		
		printf("Usted ha entrado como administrador\n");
		printf("\n");
		printf("BIENVENIDO A LA BIBLIOTECA ONLINE DE LA UNIVERSIDAD DE DEUSTO!\n");
		printf("Indique su opcion: \n");
		
		printf("1. Lista de libros disponibles para alquilar\n");
		printf("2. Lista de clientes de la biblioteca de Deusto\n");
		printf("3. Introducir un nuevo cliente\n");
		printf("4. Introducir un nuevo libro \n");
		printf("5. Alquilar \n");
		printf("6. Lista alquilar\n");
		printf("7. Eliminar un cliente\n");
		printf("8. Eliminar un libro\n");
		printf("9. EXIT\n" );
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '9') || (len > 0 && (option > 9 || option < 1)));
	
	return (str[0] == '9')?0:option;

}


int main(int argc, char **argv, char **vectorClientes)
{
	int option;
	int total = 0;
	char n[30];
	char c[30]; 
	int log = 0;	
	do
	{
	 printf("\n\n\n\nBIENVENIDO A LA BIBLIOTECA DE DEUSTO\n");
	 printf("Escriba el nombre de usuario por favor (usuario - empleado)\n");
	 gets(n);
	 printf("Escriba su contrasena\n");
	 gets(c);
	
	
		if(strcmp(n, "admin")==0 && strcmp(c, "admin")==0)
		 {
		 	log = 1;
			do
			{
				option = menuAdministrador();
				

				switch (option)
				{
					case 1:
					listaLibros();
					break;

					case 2:

					listaClientes();
					break;
					
					case 3:
					nuevoCliente(dni, nombre, apellido, edad, curso);
					break;
					
					case 4:
					nuevoLibro(codigo, titulo, autor, genero, stock);
					break;

					case 5:
					alquilar();
					break;

					case 6: 
					listaAlquiler();
					break;

					case 7:
					{
					string nombre;
					cout<<"Inserta el nombre del cliente a borrar";
					getline(cin, nombre);
					vaciarClientes(nombre);
					break;
					}

					case 8:
					{
					string titulo;
					cout<<"Inserta el titulo del libro a borrar";
					getline(cin, titulo);
					vaciarLibros(titulo);
					break;
					}

					default:
					return -1;
					break;
			
				}

			}while(option!=0);	
		 }else
		 if(strcmp(n, "cliente")==0 && strcmp(c, "cliente")==0)
			{
				log = 1;
				do
				{

					option = menuCliente();

				
					switch (option)
					{
						default:
						return -1;
						break;

					}
				}while(option!=0);
			}else
			{	 
			log = 0;	
			printf("usuario/contraseña incorrecta\n");
			}
	}while(log == 0);

}




