#include "Cliente.h"
#include <fstream>

#pragma region Constructor
Cliente::Cliente(int _id, string _nombre, string _correo, string _telefono)
	: id(_id), nombre(_nombre), correo(_correo), telefono(_telefono)
{
	siguiente = anterior = nullptr;
}
#pragma endregion

#pragma region Metodo Mostrar
void Cliente::mostrar()
{
	cout << " ID: " << id 
		<< " | Nombre: " << nombre
		<< " | Correo: " << correo 
		<< " | Telefono: " << telefono << endl;
}
#pragma endregion

#pragma region Metodo toFileString
string Cliente::toFileString()
{
	return to_string(id) + "," + nombre + "," + correo + "," + telefono;
}
#pragma endregion

#pragma region Constructor ListaClientes
ListaClientes::ListaClientes()
{
	head = tail = nullptr;
	cargarArchivo();
}
#pragma endregion

#pragma region Metodo Insertar
void ListaClientes::insertar()
{
	int id;
	string nombre, correo, telefono;

	cout << "ID del cliente: " << endl;
	cin >> id;
	cin.ignore();
	cout << "Nombre del cliente: " << endl;
	getline(cin, nombre);
	cout << "Correo del cliente: " << endl;
	getline(cin, correo);
	cout << "Telefono del cliente: " << endl;
	getline(cin, telefono);

	Cliente* nuevo = new Cliente(id, nombre, correo, telefono);
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

	cout << "Cliente agregado exitosamente" << endl;
	guardarArchivo();
}
#pragma endregion

#pragma region Metodo Mostrar
void ListaClientes::mostrar()
{
	if (!head)
	{
		cout << "No hay clientes registrados" << endl;
		return;
	}
	cout << "Lista de Clientes:" << endl;
	Cliente* actual = head;
	while (actual)
	{
		actual->mostrar();
		actual = actual->getSiguiente();
	}
}
#pragma endregion

#pragma region Metodo Buscar
void ListaClientes::buscar(int idBuscado)
{
	Cliente* actual = head;
	while (actual)
	{
		if (actual->getId() == idBuscado)
		{
			cout << "Cliente encontrado: " << endl;
			actual->mostrar();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Cliente no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo Eliminar
void ListaClientes::eliminar(int idEliminar)
{
	Cliente* actual = head;
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
			cout << "Cliente eliminado correctamente" << endl;
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Cliente no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo GuardarArchivo
void ListaClientes::guardarArchivo()
{
	ofstream archivo("clientes.txt");
	if (!archivo)
	{
		cout << "Error al abrir el archivo para guardar." << endl;
		return;
	}
	Cliente* actual = head;
	while (actual)
	{
		archivo << actual->toFileString() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
#pragma endregion

#pragma region Metodo CargarArchivo
void ListaClientes::cargarArchivo()
{
	ifstream archivo("clientes.txt");
	if (!archivo)
	{
		cout << "No se pudo abrir el archivo de clientes para cargar" << endl;
		return;
	}

	string linea;
	while (getline(archivo, linea))
	{
		size_t p1 = linea.find(",");
		size_t p2 = linea.find(",", p1 + 1);
		size_t p3 = linea.find(",", p2 + 1);

		int id = stoi(linea.substr(0, p1));
		string nombre = linea.substr(p1 + 1, p2 - p1 - 1);
		string correo = linea.substr(p2 + 1, p3 - p2 - 1);
		string telefono = linea.substr(p3 + 1);

		Cliente* nuevo = new Cliente(id, nombre, correo, telefono);
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

#pragma region Destructor ListaClientes
ListaClientes::~ListaClientes()
{
	Cliente* actual = head;
	while (actual)
	{
		Cliente* sig = actual->getSiguiente();
		delete actual;
		actual = sig;
	}
}
#pragma endregion