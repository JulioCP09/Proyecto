#include "Producto.h"
#include <fstream>

#pragma region Constructor
Producto::Producto(int _id, string _nombre, float _precio, int _stock)
	: id(_id), nombre(_nombre), precio(_precio), stock(_stock)
{
	siguiente = anterior = nullptr;
}
#pragma endregion

#pragma region Metodo Mostrar
void Producto::mostrar()
{
	cout << "ID: " << id << " | Nombre: " << nombre 
		<< " | Precio: " << precio << " | Stock: " << stock << endl;
}
#pragma endregion

#pragma region Metodo toFileString
string Producto::toFileString()
{
	return to_string(id) + "," + nombre + "," + to_string(precio) + "," + to_string(stock);
}
#pragma endregion

#pragma region Constructor ListaProductos
ListaProductos::ListaProductos()
{
	head = tail = nullptr;
	cargarArchivo();
}
#pragma endregion

#pragma region Metodo Insertar
void ListaProductos::insertar()
{
	int id, stock;
	float precio;
	string nombre;

	cout << "ID del producto: " << endl;
	cin >> id;
	cin.ignore();
	cout << "Nombre del producto: " << endl;
	getline(cin, nombre);
	cout << "Precio del producto: " << endl;
	cin >> precio;
	cout << "Stock del producto: " << endl;
	cin >> stock;
	
	Producto* nuevo = new Producto(id, nombre, precio, stock);
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

	cout << "Producto agregado exitosamente" << endl;
	guardarArchivo();
}
#pragma endregion

#pragma region Metodo Mostrar
void ListaProductos::mostrar()
{
	Producto* actual = head;
	if (!actual)
	{
		cout << "No hay productos en la lista." << endl;
		return;
	}
	cout << "Lista de Productos:" << endl;
	while (actual)
	{
		actual->mostrar();
		actual = actual->getSiguiente();
	}
}
#pragma endregion

#pragma region Metodo Buscar
void ListaProductos::buscar(int idBuscado)
{
	Producto* actual = head;
	while (actual) 
	{
		if (actual->getId() == idBuscado) 
		{
			cout << "Producto encontrado: " << endl;
			actual->mostrar();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Producto no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo Eliminar
void ListaProductos::eliminar(int idEliminar)
{
	Producto* actual = head;
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
			cout << "Producto eliminado correctamente" << endl;
			guardarArchivo();
			return;
		}
		actual = actual->getSiguiente();
	}
	cout << "Producto no encontrado" << endl;
}
#pragma endregion

#pragma region Metodo GuardarArchivo
void ListaProductos::guardarArchivo()
{
	ofstream archivo("productos.txt");
	if (!archivo)
	{
		cout << "Error al abrir el archivo para guardar." << endl;
		return;
	}
	Producto* actual = head;
	while (actual) 
	{
		archivo << actual->toFileString() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
#pragma endregion

#pragma region Metodo CargarArchivo
void ListaProductos::cargarArchivo()
{
	ifstream archivo("productos.txt");
	if (!archivo) 
	{
		cout << "No se pudo abrir el archivo para cargar" << endl;
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
		float precio = stod(linea.substr(p2 + 1, p3 - p2 - 1));
		int stock = stoi(linea.substr(p3 + 1));

		Producto* nuevo = new Producto(id, nombre, precio, stock);
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

#pragma region Destructor ListaProductos
ListaProductos::~ListaProductos()
{
	Producto* actual = head;
	while (actual) 
	{
		Producto* sig = actual->getSiguiente();
		delete actual;
		actual = sig;
	}
}
#pragma endregion