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
		printf("4. Puntuar la biblioteca de deusto\n");
		printf("5. Ver valoraciones\n");
		printf("6. EXIT\n");
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '6') || (len > 0 && (option > 6 || option < 1)));
	
	return (str[0] == '6')?0:option;

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
		printf("3. Introducir un nuevo libro \n");
		printf("4. Introducir un nuevo libro \n");
		printf("5. Lista alquilar\n");
		printf("6. Eliminar un libro\n");
		printf("7. EXIT\n" );
		printf("\n");
		
		fgets(str, 50, stdin);
	
		len = sscanf(str, "%d", &option); 
		printf("\n");

	}while ((len == 0 && str[0] != '7') || (len > 0 && (option > 7 || option < 1)));
	
	return (str[0] == '7')?0:option;

}


int main(int argc, char **argv)
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
					listaAlquiler();
					break;
				

					case 6:
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
						case 1:
						listaLibros();
						break;

						case 2:
						alquilerLibro();
						break;

						case 3:
						{
							string nombre;
							cout<<"Inserta el nombre del cliente a borrar";
							getline(cin, nombre);
							vaciarClientes(nombre);
							break;
						}

						case 4:
						valorarBiblioteca();
						break;

						case 5: 
						verValoraciones();
						break;

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




