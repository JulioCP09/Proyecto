#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto
{
private:
	int id;
	string nombre;
	float precio;
	int stock;
	Producto* siguiente;
	Producto* anterior;

public:
	//Constructor
	Producto(int _id, string _nombre, float _precio, int _stock);

	//Métodos
	void mostrar();
	string toFileString();

	int getId() const { return id; }
	string getNombre() const { return nombre; }
	float getPrecio() const { return precio; }
	int getStock() const { return stock; }

	Producto* getSiguiente() const { return siguiente; }
	Producto* getAnterior() const { return anterior; }

	void setSiguiente(Producto* sig) { siguiente = sig; }
	void setAnterior(Producto* ant) { anterior = ant; }
};

class ListaProductos
{
private:
	Producto* head;
	Producto* tail;

public:
	ListaProductos();
	void insertar();
	void mostrar();
	void buscar(int idBuscado);
	void eliminar(int idEliminar);
	void guardarArchivo();
	void cargarArchivo();
	~ListaProductos();
};