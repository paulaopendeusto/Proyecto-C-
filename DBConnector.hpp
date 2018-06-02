#ifndef _DBCONNECTOR_HPP_
#define _DBCONNECTOR_HPP_


#include "string.h"
#include "sqlite3.h"

using namespace std;

class DBConnector 
{

private:
  sqlite3 *db = NULL;


public:
  DBConnector(std::string dbFile) 
  {
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error opening database" << std::endl;
      
    }

    // Crate table cliente
    char sql[] = "CREATE TABLE cliente (dni int, nombre TEXT, apellido TEXT, edad int, curso int);";
    result = sqlite3_exec(db, sql, 0, 0, NULL);

    if (result != SQLITE_OK) {
      std::cout << "Error executing CREATE" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;    
    }

    char sql1[] = "CREATE TABLE libro (codigo int, titulo TEXT, autor TEXT, genero TEXT, stock int);";
    result = sqlite3_exec(db, sql1, 0, 0, NULL);

    if (result != SQLITE_OK) {
      std::cout << "Error executing CREATE" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;    
    }

    char sql2[] = "CREATE TABLE alquiler (dni int, codigo int);";
    result = sqlite3_exec(db, sql2, 0, 0, NULL);

    if (result != SQLITE_OK) {
      std::cout << "Error executing CREATE" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;    
    }
    
  }
  
  ~DBConnector() 
  {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK) {
      std::cout << "Error closing database" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
    }	
  }


int nuevoCliente(int dni, string nombre, string apellido, int edad, int curso)
{
  sqlite3_stmt *stmt;

    char sql[] = "insert into cliente (dni, nombre, apellido, edad, curso) values (?, ?,?,?,?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

   
    result = sqlite3_bind_int(stmt, 1, dni);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, apellido.c_str(), apellido.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    result = sqlite3_bind_int(stmt, 4, edad);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 5, curso);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into cliente table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Nuevo Cliente resgistrado" << std::endl;

    return SQLITE_OK;
  }


 int listaClientes() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "select dni, nombre, apellido, edad, curso from cliente";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (SELECT)" << std::endl;

    int dni;
    char nombre[100];
    char apellido[100];
    int edad;
    int curso;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Lista de Clientes de la blibioteca de la Universidad de Deusto" << std::endl;

    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
        dni = sqlite3_column_int(stmt, 0);
        strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
        strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
        edad = sqlite3_column_int(stmt, 3);
        curso = sqlite3_column_int(stmt, 4);
        std::cout << "DNI: " << dni << " Nombre: " << nombre << " Apellido: " << apellido << " Edad: " << edad << " Curso: " << curso << std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (SELECT)" << std::endl;

    return SQLITE_OK;
  }


  int vaciarClientes()
  {
     sqlite3_stmt *stmt;

    char sql[] = "delete from cliente";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) 
    {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (DELETE)" << std::endl;

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (DELETE)" << std::endl;

    return SQLITE_OK;
  }

///////////////////////////////LIBROS///////////////////////////////////////

int nuevoLibro(int codigo, string titulo, string autor, string genero, int stock)
{
  sqlite3_stmt *stmt;

    char sql[] = "insert into libro (codigo, titulo, autor, genero, stock) values (?,?,?,?,?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;

    result = sqlite3_bind_int(stmt, 1, codigo);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, titulo.c_str(), titulo.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, autor.c_str(), autor.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    result = sqlite3_bind_text(stmt, 4, genero.c_str(), genero.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    result = sqlite3_bind_int(stmt, 5, stock);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into libro table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Nuevo Cliente resgistrado" << std::endl;

    return SQLITE_OK;
  }
 int listaLibros() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "select codigo, titulo, autor, genero, stock from libro";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (SELECT)" << std::endl;

    int codigo;
    char titulo[100];
    char autor[100];
    char genero[100];
    int stock;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Lista de Clientes de la blibioteca de la Universidad de Deusto" << std::endl;

    do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
        codigo = sqlite3_column_int(stmt, 0);
        strcpy(titulo, (char *) sqlite3_column_text(stmt, 1));
        strcpy(autor, (char *) sqlite3_column_text(stmt, 2));
        strcpy(genero, (char *) sqlite3_column_text(stmt, 3));
        stock = sqlite3_column_int(stmt, 4);
        
        std::cout << "CODIGO: " << codigo << " Titulo: " << titulo << " Autor: " << autor << " Genero: " << genero << " Stock: " << stock << std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (SELECT)" << std::endl;

    return SQLITE_OK;
  }
  int vaciarLibros()
  {
     sqlite3_stmt *stmt;

    char sql[] = "delete from libro";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) 
    {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (DELETE)" << std::endl;

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (DELETE)" << std::endl;

    return SQLITE_OK;
  }

int buscarLibro() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "select codigo, titulo, stock from libro";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    int codigo;
    int cl; // codigo del libro introducido
    char titulo[100];
    char autor[100];
    char genero[100];
    int stock;
    int dnic; //dni del cliente introducido
    char nombre[100];


    listaLibros();

    cout<< "Introduce el codigo del libro que desea alquilar"<<endl;
    cin>>cl;


     do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
                 
        if(cl==sqlite3_column_int(stmt,0))
        {
          strcpy(titulo, (char *) sqlite3_column_text(stmt, 1));
          stock=sqlite3_column_int(stmt,4);
          cout <<"Libro seleccionado -->  CODIGO: " << cl << " Titulo: " << titulo <<endl;

        }
        else
        {
          cout<<"No existe ningun libro con ese codigo"<<endl;
          buscarLibro();
        }

      }
    } while (result == SQLITE_ROW);

    
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
   

    return cl;
    return SQLITE_OK;
  }

int buscarCliente() 
  {
    sqlite3_stmt *stmt;

    char sql[] = "select dni, nombre from cliente";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }


    int dnic; //dni del cliente introducido
    char nombre[100];


    cout<< "Introduce el dni ppara realizar la reserva"<<endl;
    cin>>dnic;


     do 
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
                 
        if(dnic==sqlite3_column_int(stmt,0))
        {
          strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
          cout <<"Eres tu? -->  dni: " << dnic << " Nombre: " << nombre <<endl;

        }
        else
        {
          cout<<"No existe ningun cliente con ese dni"<<endl;
          buscarCliente();
        }

      }
    } while (result == SQLITE_ROW);

  
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
   

    return dnic;
    return SQLITE_OK;
  }

  int alquilar()
  {
    int dni;
    int codigo;
    char nombre[100];
    int stock;

    codigo=buscarLibro();
    
    dni= buscarCliente();


    sqlite3_stmt *stmt;

    char sql[] = "insert into alquiler (dni, codigo) values (?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 1, dni);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_int(stmt, 2, codigo);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into alquiler table" << std::endl;
      return result;
    }

  
    std::cout << std::endl;
    std::cout << "Su alquiler se ha realizado con existo!!!" << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------------------------------"<<std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    return SQLITE_OK;
 
  }

};
#endif
