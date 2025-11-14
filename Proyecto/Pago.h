#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pago
{
private:
	int id;
	int idPedido;
	float monto;
	string metodo;
	Pago* siguiente;
	Pago* anterior;

public:
	//Constructor
	Pago(int _id, int _idPedido, float _monto, string _metodo);

	//Métodos
	void mostrar();
	string toFileString();

	int getId() const { return id; }
	Pago* getSiguiente() const { return siguiente; }
	Pago* getAnterior() const { return anterior; }
	void setSiguiente(Pago* sig) { siguiente = sig; }
	void setAnterior(Pago* ant) { anterior = ant; }
};

class ListaPagos
{
private:
	Pago* head;
	Pago* tail;

public:
	//Constructor
	ListaPagos();

	//Métodos
	void insertar();
	void mostrar();
	void buscar(int idBuscado);
	void eliminar(int idEliminar);
	void guardarArchivo();
	void cargarArchivo();

	//Destructor
	~ListaPagos();
};