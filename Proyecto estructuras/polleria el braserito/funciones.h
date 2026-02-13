#ifndef FUNCIONES_H
#define FUNCIONES_H

/*
--------------------------------------------------
Archivo: funciones.h
Propósito:
    Declarar todas las funciones del sistema.
--------------------------------------------------
*/

// ===== GESTIÓN DE MEMORIA =====

// --------------------------------------------------
// Función: inicializarMemoria
// Propósito:
//     Reserva memoria dinámica para los pedidos.
// --------------------------------------------------
void inicializarMemoria();

// --------------------------------------------------
// Función: liberarMemoria
// Propósito:
//     Libera la memoria dinámica utilizada.
// --------------------------------------------------
void liberarMemoria();

// ===== SISTEMA =====

// --------------------------------------------------
// Función: validarCredenciales
// Retorna:
//     true si las credenciales son correctas.
// --------------------------------------------------
bool validarCredenciales();

// --------------------------------------------------
void mostrarMenu();

// --------------------------------------------------
void registrarPedido();

// --------------------------------------------------
void mostrarPedidos();

// --------------------------------------------------
void cancelarUltimoPedido();

// --------------------------------------------------
float calcularTotalVentas();

// ===== ARCHIVOS =====

void guardarPedidosTXT();
void cargarPedidosTXT();

#endif