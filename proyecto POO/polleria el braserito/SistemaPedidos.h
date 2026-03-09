#ifndef SISTEMA_PEDIDOS_H
#define SISTEMA_PEDIDOS_H

#include <vector>
#include "Pedido.h"

// ============================================================
// CLASE: SistemaPedidos
// Descripción:
// Administra todos los pedidos de la pollería.
// Permite registrar, mostrar, buscar, modificar, cancelar pedidos
// y calcular estadísticas de ventas.
// ============================================================
class SistemaPedidos {
private:
    std::vector<Pedido> pedidos;  // Lista de todos los pedidos
    int nextId;                   // ID automático para nuevos pedidos

    // ==================== Persistencia ====================
    void cargarPedidos();         // Carga pedidos desde "pedidos.txt"
    void guardarPedidos() const;  // Guarda pedidos en "pedidos.txt"

public:
    // Constructor: inicializa nextId y carga pedidos
    SistemaPedidos();

    // ==================== Gestión de pedidos ====================
    void registrarPedido();
    void mostrarPedidos() const;
    void cancelarUltimoPedido();
    void modificarPedido(int id);

    // ==================== Búsqueda ====================
    Pedido* buscarPedidoPorId(int id);
    void buscarPedido();

    // ==================== Análisis de ventas ====================
    void ventasTotales() const;
    void ventasPorCategoria() const;
};

#endif