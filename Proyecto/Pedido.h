#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pedido
{
private:
	int id;
	int idCliente;
	int idProducto;
	int cantidad;
	Pedido* siguiente;
	Pedido* anterior;

public:
	//Constructor
	Pedido(int _id, int _idCliente, int _idProducto, int _cantidad);

	//Metodos
	void mostrar();
	string toFileString();

	int getId() const { return id; }
	Pedido* getSiguiente() const { return siguiente; }
	Pedido* getAnterior() const { return anterior; }
	void setSiguiente(Pedido* sig) { siguiente = sig; }
	void setAnterior(Pedido* ant) { anterior = ant; }
};

class ListaPedidos
{
private:
	Pedido* head;
	Pedido* tail;

public:
	//Constructor
	ListaPedidos();

	//Metodos
	void insertar();
	void mostrar();
	void buscar(int idBuscado);
	void eliminar(int idEliminar);
	void guardarArchivo();
	void cargarArchivo();

	//Destructor
	~ListaPedidos();
};

