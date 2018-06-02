#ifndef _GESTION_HPP
#define _GESTION_HPP

#include "Admin.hpp"
#include "Persona.hpp"
#include "Cliente.hpp"
#include "string.h"
#include "DBConnector.hpp"

using namespace std;

void nuevoCliente(int dni, string nombre, string apellido, int edad, int curso);
void listaClientes();
void vaciarClientes();

void nuevoLibro(int codigo, string titulo, string autor, string genero, int stock);
void listaLibros();
void vaciarLibros();

void buscarLibro();
void buscarCliente();

void alquilar();

#endif