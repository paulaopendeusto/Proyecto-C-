#include <iostream>
#include "Admin.hpp"
#include "Cliente.hpp"
#include "Persona.hpp"
#include "gestion.hpp"
#include <iostream>
#include <fstream>
#include "string.h"
#include "DBConnector.hpp"

#define MAX_LENGHT 50
using namespace std;

DBConnector dbConnector("test.sqlite");
int result;

void nuevoCliente(int dni, std :: string nombre, std :: string apellido, int edad, int curso)
{
	
  
  
  
  cout << "Nombre: ";
  cin >> nombre;
  cout << "Apellido: ";
  cin >> apellido;
  cout << "Edad: ";
  cin >> edad;
  cout << "DNI: ";
  cin >> dni;
  cout << "Curso: ";
  cin >> curso;

  result = dbConnector.nuevoCliente(dni, nombre, apellido, edad, curso);
  if (result != SQLITE_OK) {
    std::cout << "Error " << std::endl;
  
    }

     	
}

void listaClientes()
{

  result = dbConnector.listaClientes();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all clientes" << std::endl;
    
  }
}