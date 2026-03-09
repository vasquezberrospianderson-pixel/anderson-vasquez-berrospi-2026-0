#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include <string>
#include "categoria.h"

// ============================================================
// CLASE: Producto
// Descripción:
// Representa un producto con nombre, precio, cantidad y categoría
// ============================================================
class Producto {
private:
    std::string nombre;
    double precio;
    int cantidad;
    Categoria categoria;

public:
    // Constructor por defecto
    Producto() : nombre(""), precio(0), cantidad(0), categoria(Categoria::BEBIDAS) {}

    // Getters
    std::string getNombre() const;
    double getPrecio() const;
    int getCantidad() const;
    Categoria getCategoria() const;

    // Setters
    void setNombre(const std::string& n);
    void setPrecio(double p);
    void setCantidad(int c);
    void setCategoria(Categoria cat);
};

// ============================================================
// CLASE: Pedido
// Descripción:
// Representa un pedido con ID, lista de productos y estado
// ============================================================
enum class Estado { ACTIVO, CANCELADO };

class Pedido {
private:
    int id;
    std::vector<Producto> productos;
    Estado estado;

public:
    Pedido(int id);

    // Getters y setters
    int getId() const;
    Estado getEstado() const;
    void setEstado(Estado e);

    const std::vector<Producto>& getProductos() const;

    // Gestión de productos
    void agregarProducto(const Producto& p);
    void modificarProducto(int index, const Producto& p);
    void eliminarProducto(int index);

    // Cálculo de total
    double calcularTotal() const;

    // Mostrar en consola
    void mostrarPedido() const;

    // Persistencia
    std::string toFileString() const;
    void fromFileString(const std::string& str);
};

#endif