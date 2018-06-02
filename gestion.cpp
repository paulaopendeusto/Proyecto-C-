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
void vaciarClientes()
{
   result=dbConnector.vaciarClientes();
    if (result != SQLITE_OK) {
      std::cout << "Error deleting all clientes" << std::endl;
      
    }
}
void nuevoLibro(int codigo, std :: string titulo, std :: string autor, std :: string genero, int stock)
{  
  cout << "Titulo: ";
  cin >> titulo;
  cout << "Autor: ";
  cin >> autor;
  cout << "Genero: ";
  cin >> genero;
  cout << "Stock: ";
  cin >> stock;
  cout << "Codigo: ";
  cin >> codigo;

  result = dbConnector.nuevoLibro(codigo, titulo, autor, genero, stock);
  if (result != SQLITE_OK) {
    std::cout << "Error " << std::endl;
  
    }

      
}

void listaLibros()
{

  result = dbConnector.listaLibros();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all libros" << std::endl;
    
  }
}

void vaciarLibros()
{
   result=dbConnector.vaciarLibros();
    if (result != SQLITE_OK) {
      std::cout << "Error deleting all libros" << std::endl;
      
    }
}
void buscarLibro()
{

  result = dbConnector.buscarLibro();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all libros" << std::endl;
    
  }
}
void buscarCliente()
{

  result = dbConnector.buscarCliente();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all clientes" << std::endl;
    
  }
}

void alquilar()
{

  result = dbConnector.alquilar();
  if (result != SQLITE_OK) {
    std::cout << "Error getting alquilar" << std::endl;
    
  }
}

