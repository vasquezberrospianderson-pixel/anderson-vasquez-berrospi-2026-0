#include "variables.h"
#include "funciones.h"
#include <iostream>

using namespace std;

// --------------------------------------------------
// Función principal (main)
// Propósito:
//  - Controla el flujo general del sistema.
//  - Valida las credenciales de acceso.
//  - Inicializa y carga los pedidos almacenados.
//  - Ejecuta las opciones del menú hasta que el
//    usuario decida salir.
// Retorna:
//  - 0 cuando el programa finaliza correctamente.
// --------------------------------------------------
int main() {

    // ===== VALIDACIÓN DE ACCESO =====
    if (!validarCredenciales()) {
        cout << "Acceso denegado. Programa finalizado.\n";
        return 0;
    }

    // ===== INICIALIZACIÓN DE MEMORIA DINÁMICA =====
    // Se reserva memoria para los pedidos y sus productos.
    inicializarMemoria();

    // ===== CARGA DE PEDIDOS DESDE ARCHIVO =====
    cargarPedidosTXT();

    int opcion;

    // ===== CICLO PRINCIPAL DEL SISTEMA =====
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // ===== VALIDACIÓN DE ENTRADA =====
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Ingrese un numero.\n";
            continue;
        }

        // ===== ESTRUCTURA DE CONTROL (switch) =====
        switch (opcion) {
            case 1:
                registrarPedido();
                break;

            case 2:
                mostrarPedidos();
                break;

            case 3:
                cancelarUltimoPedido();
                break;

            case 4:
                cout << "\nTotal de ventas: S/ "
                     << calcularTotalVentas() << endl;
                break;

            case 5:
                cout << "\nGracias por usar El Braserito.\n";
                break;

            default:
                cout << "Opcion fuera de rango. Intente nuevamente.\n";
        }

    } while (opcion != 5);

    // ===== LIBERACIÓN DE MEMORIA =====
    // Se libera la memoria dinámica antes de finalizar
    liberarMemoria();

    return 0;
}