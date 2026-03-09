#include "pedido.h"
#include "utils.h"
#include <iostream>
#include <sstream>

// ============================================================
// CLASE: Producto
// ============================================================
// Esta sección implementa los métodos de la clase Producto.
// Representa un producto con nombre, precio, cantidad y categoría.
// Se utiliza encapsulación: los atributos son privados y se accede a ellos mediante getters y setters.
// ============================================================

// ==================== GETTERS ====================
// Devuelven el valor de cada atributo privado
std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getCantidad() const { return cantidad; }
Categoria Producto::getCategoria() const { return categoria; }

// ==================== SETTERS ====================
// Permiten modificar los atributos privados de manera controlada
void Producto::setNombre(const std::string& n) { nombre = n; }
void Producto::setPrecio(double p) { precio = p; }
void Producto::setCantidad(int c) { cantidad = c; }
void Producto::setCategoria(Categoria cat) { categoria = cat; }

// ============================================================
// CLASE: Pedido
// ============================================================
// Representa un pedido con ID, lista de productos y estado (ACTIVO o CANCELADO).
// Demuestra composición: un Pedido contiene muchos Productos.
// ============================================================

// ==================== CONSTRUCTOR ====================
// Inicializa el pedido con un ID y establece su estado como ACTIVO
Pedido::Pedido(int id) : id(id), estado(Estado::ACTIVO) {}

// ==================== GETTERS Y SETTERS ====================
int Pedido::getId() const { return id; }
Estado Pedido::getEstado() const { return estado; }
void Pedido::setEstado(Estado e) { estado = e; }

// Devuelve una referencia constante al vector de productos
const std::vector<Producto>& Pedido::getProductos() const { return productos; }

// ============================================================
// GESTIÓN DE PRODUCTOS
// ============================================================

// Agrega un producto al pedido
void Pedido::agregarProducto(const Producto& p) { 
    productos.push_back(p); 
}

// Modifica un producto en la posición indicada (reemplaza el existente)
void Pedido::modificarProducto(int index, const Producto& p) { 
    productos[index] = p; 
}

// Elimina un producto en la posición indicada
void Pedido::eliminarProducto(int index) { 
    productos.erase(productos.begin() + index); 
}

// ============================================================
// CÁLCULO DE TOTAL
// ============================================================

// Calcula el total del pedido sumando (precio * cantidad) de cada producto
double Pedido::calcularTotal() const {
    double total = 0;
    for (const auto& p : productos) 
        total += p.getPrecio() * p.getCantidad();
    return total;
}

// ============================================================
// MOSTRAR PEDIDO EN CONSOLA
// ============================================================

// Muestra la información completa del pedido en consola de manera legible
void Pedido::mostrarPedido() const {
    std::cout << "ID: " << id << " | Estado: "
              << (estado == Estado::ACTIVO ? "Activo" : "Cancelado") << "\n";

    for (size_t i = 0; i < productos.size(); ++i) {
        const auto& p = productos[i];
        std::cout << i+1 << ". " << p.getNombre()
                  << " | Precio: S/ " << p.getPrecio()
                  << " | Cantidad: " << p.getCantidad()
                  << " | Categoria: " << Utils::categoriaToString(p.getCategoria())
                  << "\n";
    }
}

// ============================================================
// PERSISTENCIA: GUARDAR Y CARGAR DESDE ARCHIVO
// ============================================================

// Convierte el pedido en una cadena para guardar en archivo
// Formato: ID;ESTADO;Producto1,...;Producto2,...;
std::string Pedido::toFileString() const {
    std::ostringstream oss;
    oss << id << ";" 
        << (estado == Estado::ACTIVO ? "ACTIVO" : "CANCELADO") << ";";

    for (const auto& p : productos) {
        oss << p.getNombre() << "," 
            << p.getPrecio() << "," 
            << p.getCantidad() << "," 
            << Utils::categoriaToString(p.getCategoria()) << ";";
    }
    return oss.str();
}

// Carga un pedido desde una línea de archivo
// Separa ID, estado y productos, y reconstruye los objetos Producto
void Pedido::fromFileString(const std::string& str) {
    productos.clear(); // Limpiar productos existentes

    std::istringstream iss(str);
    std::string token;

    // ID
    getline(iss, token, ';'); 
    id = std::stoi(token);

    // Estado
    getline(iss, token, ';'); 
    estado = (token == "ACTIVO" ? Estado::ACTIVO : Estado::CANCELADO);

    // Productos
    while (getline(iss, token, ';')) {
        if (token.empty()) continue;

        std::istringstream prodStream(token);
        std::string nombre, precio, cantidad, catStr;

        getline(prodStream, nombre, ',');
        getline(prodStream, precio, ',');
        getline(prodStream, cantidad, ',');
        getline(prodStream, catStr, ',');

        Producto p;
        p.setNombre(nombre);
        p.setPrecio(std::stod(precio));
        p.setCantidad(std::stoi(cantidad));
        p.setCategoria(Utils::stringToCategoria(catStr));

        productos.push_back(p);
    }
}