#include <iostream>
#include <stdexcept>
#include "SistemaPedidos.h"
#include "utils.h"

using namespace std;

/*------------------------------------------------------------
  FUNCIÓN: leerPassword()
  Descripción:
  Permite ingresar una contraseña mostrando '*' en lugar
  de los caracteres reales.
  Retorna:
    string con la contraseña ingresada
------------------------------------------------------------*/
string leerPassword() {
    return Utils::getPassword("Password: ");
}

/*------------------------------------------------------------
  FUNCIÓN PRINCIPAL
  Descripción:
    Controla el flujo general del programa:
      - Autenticación del usuario
      - Menú principal del sistema de pedidos
      - Llamadas a la clase SistemaPedidos
------------------------------------------------------------*/
int main() {

    // ===================== CREDENCIALES =====================
    // Usuario y contraseña predefinidos
    string usuarioCorrecto = "admin";
    string passwordCorrecto = "1234";

    int intentos = 0;
    bool accesoConcedido = false;

    // Mensaje de bienvenida
    cout << "=====================================\n";
    cout << "   SISTEMA DE PEDIDOS - EL BRASERITO\n";
    cout << "=====================================\n\n";

    /*------------------------------------------------------------
      BLOQUE DE AUTENTICACIÓN
      Permite máximo 3 intentos antes de bloquear el sistema
    ------------------------------------------------------------*/
    while (intentos < 3) {
        try {
            string usuarioIngresado;
            cout << "User: ";
            cin >> usuarioIngresado;

            string passwordIngresado = leerPassword();

            // Verificar credenciales
            if (usuarioIngresado != usuarioCorrecto ||
                passwordIngresado != passwordCorrecto) {
                throw runtime_error("Credenciales incorrectas");
            }

            accesoConcedido = true; // Acceso concedido
            break;  // Salir del ciclo
        }
        catch (exception &e) {
            Utils::setColorRed();
            cout << "ERROR: " << e.what() << endl;
            Utils::resetColor();

            intentos++;
            cout << "Intentos restantes: " << 3 - intentos << "\n\n";
        }
    }

    // Bloqueo del sistema tras 3 intentos fallidos
    if (!accesoConcedido) {
        Utils::setColorRed();
        cout << "Sistema bloqueado por seguridad.\n";
        Utils::resetColor();
        return 0;
    }

    // ===================== MENSAJE DE ACCESO =====================
    Utils::setColorGreen();          
    cout << "\nAcceso concedido correctamente.\n";
    Utils::resetColor();

    // ===================== INICIO DEL SISTEMA =====================
    // Instancia del sistema de pedidos
    SistemaPedidos sistema;

    int opcion;
    do {
        // ===================== MENÚ PRINCIPAL =====================
        cout << "\n========= MENU PRINCIPAL =========\n";
        cout << "1. Registrar Pedido\n";
        cout << "2. Mostrar Pedidos\n";
        cout << "3. Buscar Pedido\n";
        cout << "4. Cancelar Ultimo Pedido\n";
        cout << "5. Modificar Pedido\n";
        cout << "6. Ventas Totales\n";
        cout << "7. Ventas por Categoria\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        // ===================== OPCIONES DEL SISTEMA =====================
        switch(opcion) {
            case 1:
                sistema.registrarPedido(); // Registrar un nuevo pedido
                break;
            case 2:
                sistema.mostrarPedidos();  // Mostrar todos los pedidos
                break;
            case 3:
                sistema.buscarPedido();    // Buscar un pedido por ID
                break;
            case 4:
                sistema.cancelarUltimoPedido(); // Cancelar el último pedido registrado
                break;
            case 5: {
                int id;
                cout << "Ingrese ID del pedido a modificar: ";
                cin >> id;
                sistema.modificarPedido(id);    // Modificar un pedido existente
                break;
            }
            case 6:
                sistema.ventasTotales();        // Mostrar total de ventas activas
                break;
            case 7:
                sistema.ventasPorCategoria();   // Mostrar ventas por categoría
                break;
            case 8:
                cout << "\nGracias por usar el sistema.\n"; // Salida
                break;
            default:
                cout << "Opcion invalida.\n";  // Manejo de opción incorrecta
        }

    } while(opcion != 8); // Repetir mientras no sea salir

    return 0;
}