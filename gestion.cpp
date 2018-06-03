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

void clear_if_needed(char *str)
{
    if (str[strlen(str) - 1] != '\n')
    {
        int c;    
        while ( (c = getchar()) != EOF && c != '\n');
    }
}

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
void vaciarClientes(std :: string nombre)
{

  result = dbConnector.vaciarClientes(nombre); 
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

void vaciarLibros(std :: string titulo)
{
   result=dbConnector.vaciarLibros(titulo);
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

void listaAlquiler()
{

  result = dbConnector.listaAlquiler();
  if (result != SQLITE_OK) {
    std::cout << "Error getting alquilar" << std::endl;
    
  }
}
void vaciarAlquiler()
{
   result=dbConnector.vaciarAlquiler();
    if (result != SQLITE_OK) {
      std::cout << "Error deleting all libros" << std::endl;
      
    }
}

void valorarBiblioteca()
{
    int valoracion;
    int valoracionf;

    FILE* file;

    file=fopen("Valoraciones.txt", "w");
    if(file==NULL)
    {
      file=fopen("Valoraciones.txt", "w");
      do{
        cout<<"Valora la biblioteca de deusto del 1 al 10";
        cin>>valoracion;

        if(valoracion >=0 && valoracion <=10)
        {
          fprintf(file, "%i", valoracion);
        }else{
          cout<<"La valoracion tiene que estar contenida entre el 1 y el 10" << endl;

        }

      }while(valoracion < 0 || valoracion>10);
    }
else
{
  char str[10];
      file=fopen("Valoraciones.txt","r");

      while(fgets(str,10,file)!=NULL)
      {
        clear_if_needed(str);

        sscanf(str,"%i",&valoracionf);
      }
      fclose(file);
      
      file=fopen("Valoraciones.txt","w");
      do{
      cout<<"Como valorarias a la biblioteca de deusto ";
      cin>>valoracion;
      if(valoracion >=0 && valoracion <=10){
      valoracionf += valoracion;  
      fprintf(file,"%i",valoracionf);
      }else{
        cout << "La puntuacion ha de ser mayor que 0 y menor que 10" << endl;
      }
      }while(valoracion <0 || valoracion >10);
    }
    fclose(file);
}


