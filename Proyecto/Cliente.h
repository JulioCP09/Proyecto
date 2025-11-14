#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
	int id;
	string nombre;
	string correo;
	string telefono;
	Cliente* siguiente;
	Cliente* anterior;

public:
	//Constructor
	Cliente(int _id, string _nombre, string _correo, string _telefono);

	//Metodos
	void mostrar();
	string toFileString();

	int getId() const { return id; }
	Cliente* getSiguiente() const { return siguiente; }
	Cliente* getAnterior() const { return anterior; }
	void setSiguiente(Cliente* sig) { siguiente = sig; }
	void setAnterior(Cliente* ant) { anterior = ant; }
};

class ListaClientes
{
private:
	Cliente* head;
	Cliente* tail;

public:
	//Constructor
	ListaClientes();

	//Metodos
	void insertar();
	void mostrar();
	void buscar(int idBuscado);
	void eliminar(int idEliminar);
	void guardarArchivo();
	void cargarArchivo();

	//Destructor
	~ListaClientes();
};

