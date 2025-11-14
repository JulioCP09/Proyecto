#include "Pago.h"
#include <fstream>

#pragma region Constructor
Pago::Pago(int _id, int _idPedido, float _monto, string _metodo)
	: id(_id), idPedido(_idPedido), monto(_monto), metodo(_metodo)
{
	siguiente = anterior = nullptr;
}
#pragma endregion

#pragma region Metodo Mostrar
void Pago::mostrar()
{
	cout << " ID Pago: " << id 
		<< " | ID Pedido: " << idPedido
		<< " | Monto: " << monto 
		<< " | Metodo: " << metodo << endl;
}
#pragma endregion

#pragma region Metodo toFileString
string Pago::toFileString()
{
	return to_string(id) + "," + to_string(idPedido) + "," + to_string(monto) + "," + metodo;
}
#pragma endregion

#pragma region Constructor ListaPagos
ListaPagos::ListaPagos()
{
	head = tail = nullptr;
	cargarArchivo();
}
#pragma endregion

#pragma region Metodo Insertar
void ListaPagos::insertar()
{
	int id, idPedido;
	float monto;
	string metodo;

	cout << "ID del pago: " << endl;
	cin >> id;
	cout << "ID del pedido: " << endl;
	cin >> idPedido;
	cout << "Monto: " << endl;
	cin >> monto;
	cin.ignore();
	cout << "Metodo de pago (efectivo, tarjeta, SINPE, etc): " << endl;
	getline(cin, metodo);

	Pago* nuevo = new Pago(id, idPedido, monto, metodo);
	if (!head)
	{
		head = tail = nuevo;
	}
	else
	{
		tail->setSiguiente(nuevo);
		nuevo->setAnterior(tail);
		tail = nuevo;
	}

	cout << "Pago agregado exitosamente" << endl;
	guardarArchivo();
}
#pragma endregion