#include "variables.h"
#include "funciones.h"
#include <iostream>
#include <fstream>

using namespace std;

// ===== VARIABLES GLOBALES DINÁMICAS =====
Pedido* pedidos = nullptr;
int totalPedidos = 0;

// --------------------------------------------------
// Función: inicializarMemoria
// Propósito:
//     Reserva memoria dinámica para pedidos
//     y sus productos.
// --------------------------------------------------
void inicializarMemoria() {

    pedidos = new Pedido[MAX_PEDIDOS];

    for (int i = 0; i < MAX_PEDIDOS; i++) {
        pedidos[i].items = new Item[MAX_ITEMS];
        pedidos[i].numItems = 0;
        pedidos[i].activo = false;
    }

    totalPedidos = 0;
}

// --------------------------------------------------
// Función: liberarMemoria
// Propósito:
//     Libera la memoria dinámica utilizada.
// --------------------------------------------------
void liberarMemoria() {

    if (pedidos != nullptr) {

        for (int i = 0; i < MAX_PEDIDOS; i++) {
            delete[] pedidos[i].items;
        }

        delete[] pedidos;
        pedidos = nullptr;
    }
}

// --------------------------------------------------
// Función: validarCredenciales
// Propósito:
//     Validar el acceso al sistema mediante
//     usuario y contraseña.
//     Permite un máximo de tres intentos.
// Retorna:
//     true  -> si las credenciales son correctas.
//     false -> si se superan los tres intentos.
// --------------------------------------------------
bool validarCredenciales() {

    string usuario, clave;
    int intentos = 0;

    while (intentos < 3) {

        cout << "\n=== ACCESO AL SISTEMA EL BRASERITO ===\n";
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Contrasena: ";
        cin >> clave;

        if (usuario == "admin" && clave == "1234") {
            cout << "Acceso concedido.\n";
            return true;
        }

        cout << "Credenciales incorrectas.\n";
        intentos++;
    }

    return false;
}
// --------------------------------------------------
// Función: mostrarMenu
// Propósito:
//     Mostrar en pantalla el menú principal
//     con las opciones disponibles del sistema.
// --------------------------------------------------
void mostrarMenu() {

    cout << "\n=== EL BRASERITO - Sistema de Polleria ===\n";
    cout << "1. Registrar pedido\n";
    cout << "2. Mostrar pedidos\n";
    cout << "3. Cancelar ultimo pedido\n";
    cout << "4. Calcular total de ventas\n";
    cout << "5. Salir\n";
}

// --------------------------------------------------
// Función: guardarPedidosTXT
// Propósito:
//     Guardar en el archivo "pedidos.txt"
//     la información de todos los pedidos
//     registrados en memoria.
// --------------------------------------------------
void guardarPedidosTXT() {

    ofstream archivo("pedidos.txt");

    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    for (int i = 0; i < totalPedidos; i++) {

        if (pedidos[i].numItems == 0) continue;

        archivo << pedidos[i].activo << " "
                << pedidos[i].numItems << " ";

        for (int j = 0; j < pedidos[i].numItems; j++) {

            archivo << pedidos[i].items[j].nombre << " "
                    << pedidos[i].items[j].precio << " "
                    << pedidos[i].items[j].cantidad << " ";
        }

        archivo << endl;
    }

    archivo.close();
}

// --------------------------------------------------
// Función: cargarPedidosTXT
// Propósito:
//     Leer el archivo "pedidos.txt" y cargar
//     los pedidos previamente almacenados
//     en memoria dinámica.
// --------------------------------------------------
void cargarPedidosTXT() {

    ifstream archivo("pedidos.txt");

    if (!archivo) {
        totalPedidos = 0;
        return;
    }

    totalPedidos = 0;

    while (true) {

        bool activo;
        int nItems;

        archivo >> activo >> nItems;

        if (archivo.fail()) break;

        pedidos[totalPedidos].activo = activo;
        pedidos[totalPedidos].numItems = nItems;

        for (int j = 0; j < nItems; j++) {

            archivo >> pedidos[totalPedidos].items[j].nombre
                    >> pedidos[totalPedidos].items[j].precio
                    >> pedidos[totalPedidos].items[j].cantidad;
        }

        totalPedidos++;
    }

    archivo.close();
}

// --------------------------------------------------
// Función: registrarPedido
// Propósito:
//     Permitir el registro de un nuevo pedido,
//     solicitando productos y cantidades,
//     almacenándolos en memoria dinámica.
// --------------------------------------------------
void registrarPedido() {

    if (totalPedidos >= MAX_PEDIDOS) {
        cout << "Limite de pedidos alcanzado.\n";
        return;
    }

    int opcion, cantidad;
    string nombre;
    float precio;
    int prodIndex = 0;

    cout << "\n=== Registrar Pedido ===\n";

    do {

        if (prodIndex >= MAX_ITEMS) {
            cout << "Limite de productos alcanzado.\n";
            break;
        }

        cout << "\n1. Pollo entero - S/30\n";
        cout << "2. Medio pollo - S/16\n";
        cout << "3. Cuarto de pollo - S/9\n";
        cout << "4. Gaseosa - S/5\n";
        cout << "Selecciona el producto: ";
        cin >> opcion;

        cout << "Cantidad: ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "Cantidad invalida.\n";
            continue;
        }

        switch (opcion) {
            case 1: nombre = "Pollo_entero"; precio = 30; break;
            case 2: nombre = "Medio_pollo"; precio = 16; break;
            case 3: nombre = "Cuarto_pollo"; precio = 9; break;
            case 4: nombre = "Gaseosa"; precio = 5; break;
            default:
                cout << "Opcion invalida.\n";
                continue;
        }

        pedidos[totalPedidos].items[prodIndex].nombre = nombre;
        pedidos[totalPedidos].items[prodIndex].precio = precio;
        pedidos[totalPedidos].items[prodIndex].cantidad = cantidad;

        prodIndex++;
        pedidos[totalPedidos].numItems = prodIndex;

        cout << "Producto agregado.\n";
        cout << "Desea agregar otro producto? (s/n): ";
        char resp;
        cin >> resp;

        if (resp != 's' && resp != 'S') break;

    } while (true);

    if (prodIndex > 0) {

        pedidos[totalPedidos].activo = true;
        totalPedidos++;
        guardarPedidosTXT();

        cout << "Pedido registrado correctamente.\n";
    }
}

// --------------------------------------------------
// Función: mostrarPedidos
// Propósito:
//     Mostrar en pantalla todos los pedidos
//     registrados, incluyendo su estado,
//     productos, cantidades y totales.
// --------------------------------------------------
void mostrarPedidos() {

    cout << "\n=== Pedidos Registrados ===\n";

    if (totalPedidos == 0) {
        cout << "No hay pedidos registrados.\n";
        return;
    }

    for (int i = 0; i < totalPedidos; i++) {

        cout << "\nPedido #" << i + 1
             << " | Estado: "
             << (pedidos[i].activo ? "Activo" : "Cancelado") << endl;

        float total = 0;

        for (int j = 0; j < pedidos[i].numItems; j++) {

            float subtotal =
                pedidos[i].items[j].precio *
                pedidos[i].items[j].cantidad;

            cout << "  "
                 << pedidos[i].items[j].nombre
                 << " x"
                 << pedidos[i].items[j].cantidad
                 << " = S/ "
                 << subtotal << endl;

            total += subtotal;
        }

        cout << "Total del pedido: S/ " << total << endl;
    }
}

// --------------------------------------------------
// Función: cancelarUltimoPedido
// Propósito:
//     Cambiar el estado del último pedido
//     registrado a "cancelado" sin eliminarlo.
// --------------------------------------------------
void cancelarUltimoPedido() {

    if (totalPedidos > 0) {

        pedidos[totalPedidos - 1].activo = false;
        guardarPedidosTXT();

        cout << "Ultimo pedido cancelado.\n";
    }
}

// --------------------------------------------------
// Función: calcularTotalVentas
// Propósito:
//     Calcular el monto total de ventas
//     considerando únicamente los pedidos activos.
// Retorna:
//     Un valor float correspondiente al total
//     acumulado de ventas.
// --------------------------------------------------
float calcularTotalVentas() {

    float total = 0;

    for (int i = 0; i < totalPedidos; i++) {

        if (pedidos[i].activo) {

            for (int j = 0; j < pedidos[i].numItems; j++) {

                total += pedidos[i].items[j].precio *
                         pedidos[i].items[j].cantidad;
            }
        }
    }

    return total;
}