#ifndef _GESTION_HPP
#define _GESTION_HPP



#include "Cliente.h"
#include "string.h"
#include "DBConnector.hpp"

using namespace std;

//void nuevoCliente(int dni, string nombre, string apellido, int edad, int curso);
void nuevoCliente(Cliente objCliente);
void listaClientes();
void vaciarClientes(string nombre);

void nuevoLibro(int codigo, string titulo, string autor, string genero, int stock);
void listaLibros();
void vaciarLibros(string titulo);

void alquilerLibro();

void alquilar();
void listaAlquiler();
void vaciarAlquiler();

void valorarBiblioteca();
int verValoraciones();

#endif