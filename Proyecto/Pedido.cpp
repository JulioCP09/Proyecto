#include "Pedido.h"
#include <fstream>

#pragma region Constructor
Pedido::Pedido(int _id, int _idCliente, int _idProducto, int _cantidad)
	: id(_id), idCliente(_idCliente), idProducto(_idProducto), cantidad(_cantidad)
{
	siguiente = anterior = nullptr;
}
#pragma endregion

#pragma region Metodo Mostrar
void Pedido::mostrar()
{
	cout << " ID Pedido: " << id 
		<< " | ID Cliente: " << idCliente
		<< " | ID Producto: " << idProducto 
		<< " | Cantidad: " << cantidad << endl;
}
#pragma endregion

#pragma region Metodo toFileString
string Pedido::toFileString()
{
	return to_string(id) + "," + to_string(idCliente) + "," + to_string(idProducto) + "," + to_string(cantidad);
}
#pragma endregion

#pragma region Constructor ListaPedidos
ListaPedidos::ListaPedidos()
{
	head = tail = nullptr;
	cargarArchivo();
}
#pragma endregion

#pragma region Metodo Insertar
void ListaPedidos::insertar()
{
	int id, idCliente, idProducto, cantidad;
	cout << "ID del pedido: " << endl;
	cin >> id;
	cout << "ID del cliente: " << endl;
	cin >> idCliente;
	cout << "ID del producto: " << endl;
	cin >> idProducto;
	cout << "Cantidad: " << endl;
	cin >> cantidad;

	Pedido* nuevo = new Pedido(id, idCliente, idProducto, cantidad);
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

	cout << "Pedido agregado exitosamente" << endl;
	guardarArchivo();
}
#pragma endregion

#pragma region Metodo Mostrar
void ListaPedidos::mostrar()
{
	if (!head)
	{
		cout << "No hay pedidos registrados" << endl;
		return;
	}
	cout << "Lista de Pedidos:" << endl;
	Pedido* actual = head;
	while (actual)
	{
		actual->mostrar();
		actual = actual->getSiguiente();
	}
}
#pragma endregion

#pragma region Metodo Buscar
void ListaPedidos::buscar(int idBuscado)
{
	Pedido* actual = head;
	while (actual)
	{
		if (actual->getId() == idBuscado)
		{
			cout << "Pedido encontrado:" << endl;
			actual->mostrar();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Pedido no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo Eliminar
void ListaPedidos::eliminar(int idEliminar)
{
	Pedido* actual = head;
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
			cout << "Pedido eñiminado correctamente" << endl;
			guardarArchivo();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Pedido no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo GuardarArchivo
void ListaPedidos::guardarArchivo()
{
	ofstream archivo("pedidos.txt");
	if (!archivo)
	{
		cout << "Error al abrir el archivo para guardar." << endl;
		return;
	}
	Pedido* actual = head;
	while (actual)
	{
		archivo << actual->toFileString() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
#pragma endregion

#pragma region Metodo CargarArchivo
void ListaPedidos::cargarArchivo()
{
	ifstream archivo("pedidos.txt");
	if (!archivo)
	{
		cout << "No se pudo abrir el archivo de pedidos para cargar" << endl;
		return;
	}

	string linea;
	while (getline(archivo,linea))
	{
		size_t p1 = linea.find(",");
		size_t p2 = linea.find(",", p1 + 1);
		size_t p3 = linea.find(",", p2 + 1);

		int id = stoi(linea.substr(0, p1));
		int idCliente = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
		int idProducto = stoi(linea.substr(p2 + 1, p3 - p2 - 1));
		int cantidad = stoi(linea.substr(p3 + 1));

		Pedido* nuevo = new Pedido(id, idCliente, idProducto, cantidad);
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

#pragma region Destructor ListaPedidos
ListaPedidos::~ListaPedidos()
{
	Pedido* actual = head;
	while (actual)
	{
		Pedido* sig = actual->getSiguiente();
		delete actual;
		actual = sig;
	}
}
#pragma endregion