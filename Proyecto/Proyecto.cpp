// Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Pago.h"

using namespace std;

#pragma region Menu Productos
void menuProductos(ListaProductos& productos)
{
	int opcion, id;
	do
	{
		cout << "\n--- MENU PRODUCTOS ---\n" << endl;
		cout << "1. Insertar Producto" << endl;
		cout << "2. Mostrar Productos" << endl;
		cout << "3. Buscar Producto" << endl;
		cout << "4. Eliminar Producto" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: productos.insertar();
			break;
		case 2: productos.mostrar();
			break;
		case 3: cout << "ID a buscar: " << endl;
			cin >> id;
			productos.buscar(id);
			break;
		case 4: cout << "ID a eliminar: " << endl;
			cin >> id;
			productos.eliminar(id);
			break;
		case 5: cout << "Regresando al menu principal" << endl;
			break;
		default: cout << "Opcion invalida, vuela a intentar" << endl;
		}
	} while (opcion != 5);
}
#pragma endregion

#pragma region Menu Clientes
void menuClientes(ListaClientes& clientes)
{
	int opcion, id;
	do
	{
		cout << "\n--- MENU CLIENTES ---\n" << endl;
		cout << "1. Insertar Cliente" << endl;
		cout << "2. Mostrar Clientes" << endl;
		cout << "3. Buscar Cliente" << endl;
		cout << "4. Eliminar Cliente" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: clientes.insertar();
			break;
		case 2: clientes.mostrar();
			break;
		case 3: cout << "ID a buscar: " << endl;
			cin >> id;
			clientes.buscar(id);
			break;
		case 4: cout << "ID a eliminar: " << endl;
			cin >> id;
			clientes.eliminar(id);
			break;
		case 5: cout << "Regresando al menu principal" << endl;
			break;
		default: cout << "Opcion invalida, vuelva a intentar" << endl;
		}
	} while (opcion != 5);
}
#pragma endregion

#pragma region Menu Pedidos
void menuPedidos(ListaPedidos& pedidos)
{
	int opcion, id;
	do
	{
		cout << "\n--- MENU PEDIDOS ---\n" << endl;
		cout << "1. Insertar Pedido" << endl;
		cout << "2. Mostrar Pedidos" << endl;
		cout << "3. Buscar Pedido" << endl;
		cout << "4. Eliminar Pedido" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: pedidos.insertar();
			break;
		case 2: pedidos.mostrar();
			break;
		case 3: cout << "ID a buscar: " << endl;
			cin >> id;
			pedidos.buscar(id);
			break;
		case 4: cout << "ID a eliminar: " << endl;
			cin >> id;
			pedidos.eliminar(id);
			break;
		case 5: cout << "Regresando al menu principal" << endl;
			break;
		default: cout << "Opcion invalida, vuelva a intentar" << endl;
		}
	} while (opcion != 5);
}
#pragma endregion

#pragma region Menu Pagos
void menuPagos(ListaPagos& pagos)
{
	int opcion, id;
	do
	{
		cout << "\n--- MENU PAGOS ---\n" << endl;
		cout << "1. Insertar Pago" << endl;
		cout << "2. Mostrar Pagos" << endl;
		cout << "3. Buscar Pago" << endl;
		cout << "4. Eliminar Pago" << endl;
		cout << "5. Volver al menu principal" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: pagos.insertar();
			break;
		case 2: pagos.mostrar();
			break;
		case 3: cout << "ID a buscar: " << endl;
			cin >> id;
			pagos.buscar(id);
			break;
		case 4: cout << "ID a eliminar: " << endl;
			cin >> id;
			pagos.eliminar(id);
			break;
		case 5: cout << "Regresando al menu principal" << endl;
			break;
		default: cout << "Opcion invalida, vuelva a intentar" << endl;
		}
	} while (opcion != 5);
}
#pragma endregion

int main()
{
	ListaProductos productos;
	ListaClientes clientes;
	ListaPedidos pedidos;
	ListaPagos pagos;

	int opcion;
	do
	{
		cout << "\n----- MENU PRINCIPAL -----\n" << endl;
		cout << "1. Menu Productos" << endl;
		cout << "2. Menu Clientes" << endl;
		cout << "3. Menu Pedidos" << endl;
		cout << "4. Menu Pagos" << endl;
		cout << "5. Salir" << endl;
		cout << "Seleccione una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case1: menuProductos(productos);
			break;
		case 2: menuClientes(clientes);
			break;
		case 3: menuPedidos(pedidos);
			break;
		case 4: menuPagos(pagos);
			break;
		case 5: cout << "Saliendo del programa" << endl;
			break;
		default: cout << "Opcion invalida, vuelva a intentar" << endl;
		}
	}while (opcion != 5);
}
