#include <iostream>
#include "Cliente.h"
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

void nuevoCliente(Cliente objCliente)
{  

 int dni;
string nombre;
string apellido;
int edad;
int curso;

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


  objCliente.setNombre(nombre);
  objCliente.setApellido(apellido);
  objCliente.setEdad(edad);
  objCliente.setDNI(dni);
  objCliente.setCurso(curso);

  result = dbConnector.nuevoCliente(objCliente);
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

void alquilerLibro()
{

  result = dbConnector.alquilerLibro();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all libros" << std::endl;
    
  }
}
void alquilar(int dni, string nombre, int codigo, string titulo, int stock)
{

  result = dbConnector.alquilar(dni, nombre, codigo,titulo,stock);
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
    cout<<"Valora la biblioteca de deusto del 1 al 10";
    cin>>valoracion;
  

  ofstream fs;
  fs.open("Valoraciones.txt", ios::app);//ios:app para que escriba al final 


  fs << "Valoracion" << valoracion << endl;  
    
  fs.close();
  
  cout << "Esta es la valoracion guardada: " << endl;
  cout << endl << valoracion << endl;
    cout << "VALORACION GUARDADA" << endl<<endl;

}
       


int verValoraciones()
{
  
  string line;
  ifstream myFile("Valoraciones.txt");

  
  cout<<"Leyendo valoraciones...."<<endl;
  cout<<"________________________________________________________"<< endl;



  
  while(getline(myFile,line))
  {

    cout<< line <<endl;
  
  } 

  
  
  cout<<endl;
  myFile.close();


}


