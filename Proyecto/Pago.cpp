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

#pragma region Metodo Mostrar
void ListaPagos::mostrar()
{
	if (!head)
	{
		cout << "No hay pagos registrados" << endl;
		return;
	}
	cout << "Lista de Pagos:" << endl;
	Pago* actual = head;
	while (actual)
	{
		actual->mostrar();
		actual = actual->getSiguiente();
	}
}
#pragma endregion

#pragma region Metodo Buscar
void ListaPagos::buscar(int idBuscado)
{
	Pago* actual = head;
	while (actual)
	{
		if (actual->getId() == idBuscado)
		{
			cout << "Pago encontrado:" << endl;
			actual->mostrar();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Pago no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo Eliminar
void ListaPagos::eliminar(int idEliminar)
{
	Pago* actual = head;
	while (actual)
	{
		if (actual->getId() == idEliminar) 
		{
			if (actual == head)
			{
				head = actual->getSiguiente();
				if (head)
				{
					head->setAnterior(nullptr);
				}
			}
			else if (actual == tail)
			{
				tail = actual->getAnterior();
				if (tail)
				{
					tail->setSiguiente(nullptr);
				}
			}
			else
			{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());
			}
			delete actual;
			cout << "Pago eliminado correctamente" << endl;
			guardarArchivo();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Pago no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo GuardarArchivo
void ListaPagos::guardarArchivo()
{
	ofstream archivo("pagos.txt");
	if (!archivo)
	{
		cout << "Error al abrir el archivo para guardar." << endl;
		return;
	}
	Pago* actual = head;
	while (actual)
	{
		archivo << actual->toFileString() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
#pragma endregion

#pragma region Metodo CargarArchivo
void ListaPagos::cargarArchivo()
{
	ifstream archivo("pagos.txt");
	if (!archivo)
	{
		cout << "No se pudo abrir el archivo de pagos para cargar" << endl;
		return;
	}

	string linea;
	while (getline(archivo, linea))
	{
		size_t p1 = linea.find(",");
		size_t p2 = linea.find(",", p1 + 1);
		size_t p3 = linea.find(",", p2 + 1);

		int id = stoi(linea.substr(0, p1));
		int idPedido = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
		float monto = stof(linea.substr(p2 + 1, p3 - p2 - 1));
		string metodo = linea.substr(p3 + 1);

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
	}
	archivo.close();
}
#pragma endregion

#pragma region Destructor
ListaPagos::~ListaPagos()
{
	Pago* actual = head;
	while (actual)
	{
		Pago* sig = actual->getSiguiente();
		delete actual;
		actual = sig;
	}
}
#pragma endregion