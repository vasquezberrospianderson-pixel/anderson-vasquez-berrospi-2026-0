#include "SistemaPedidos.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <limits> // Para limpiar buffer de entrada

// ============================================================
// CONSTRUCTOR
// ============================================================
// Inicializa el sistema de pedidos y carga los pedidos existentes desde archivo.
// nextId se ajusta automáticamente para nuevos pedidos.
SistemaPedidos::SistemaPedidos() : nextId(1) {
    cargarPedidos();
}

// ============================================================
// PERSISTENCIA
// ============================================================

// Carga los pedidos desde el archivo "pedidos.txt".
// Cada línea representa un pedido serializado.
void SistemaPedidos::cargarPedidos() {
    std::ifstream file("pedidos.txt");
    if (!file) return; // Si no existe el archivo, no hace nada

    std::string line;
    while (getline(file, line)) {
        Pedido p(0);           // Pedido temporal para reconstruirlo
        p.fromFileString(line);
        pedidos.push_back(p);

        // Ajuste de nextId para mantener IDs únicos
        if (p.getId() >= nextId) nextId = p.getId() + 1;
    }
    file.close();
}

// Guarda todos los pedidos en "pedidos.txt", uno por línea
void SistemaPedidos::guardarPedidos() const {
    std::ofstream file("pedidos.txt");
    for (const auto& p : pedidos) {
        file << p.toFileString() << "\n";
    }
    file.close();
}

// ============================================================
// REGISTRO DE PEDIDOS
// ============================================================

// Permite al usuario registrar un nuevo pedido
void SistemaPedidos::registrarPedido() {
    Pedido p(nextId++);  // Crear pedido con ID único
    int numProductos;

    Utils::setColorYellow();
    std::cout << "[PREGUNTA] Cuantos productos desea registrar? ";
    Utils::resetColor();
    std::cin >> numProductos;

    if (numProductos <= 0) {
        Utils::setColorRed();
        std::cout << "[ERROR] Debe registrar al menos 1 producto.\n";
        Utils::resetColor();
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        Producto prod;
        int opcionProducto;

        // ======= Mostrar catálogo =======
        Utils::setColorYellow();
        std::cout << "\n===== PRODUCTOS DISPONIBLES =====\n";
        Utils::resetColor();

        std::cout << "1. Inca Kola (S/ 5) - Bebidas\n";
        std::cout << "2. Coca Cola (S/ 5) - Bebidas\n";
        std::cout << "3. Pollo Entero (S/ 45)\n";
        std::cout << "4. Medio Pollo (S/ 25)\n";

        Utils::setColorYellow();
        std::cout << "[PREGUNTA] Seleccione una opcion: ";
        Utils::resetColor();
        std::cin >> opcionProducto;

        // ======= Asignar datos según opción =======
        switch(opcionProducto) {
            case 1:
                prod.setNombre("Inca Kola"); prod.setPrecio(5); prod.setCategoria(Categoria::BEBIDAS); break;
            case 2:
                prod.setNombre("Coca Cola"); prod.setPrecio(5); prod.setCategoria(Categoria::BEBIDAS); break;
            case 3:
                prod.setNombre("Pollo Entero"); prod.setPrecio(45); prod.setCategoria(Categoria::POLLO_ENTERO); break;
            case 4:
                prod.setNombre("Medio Pollo"); prod.setPrecio(25); prod.setCategoria(Categoria::MEDIO_POLLO); break;
            default:
                Utils::setColorRed();
                std::cout << "[ERROR] Opcion invalida. Producto no agregado.\n";
                Utils::resetColor();
                i--; // repetir iteración
                continue;
        }

        // ======= Cantidad =======
        Utils::setColorYellow();
        std::cout << "[PREGUNTA] Cantidad: ";
        Utils::resetColor();
        int cant;
        std::cin >> cant;

        if (cant <= 0) {
            Utils::setColorRed();
            std::cout << "[ERROR] Cantidad invalida.\n";
            Utils::resetColor();
            i--;
            continue;
        }
        prod.setCantidad(cant);

        // Agregar producto al pedido
        p.agregarProducto(prod);
    }

    // Agregar pedido a la lista y guardar en archivo
    pedidos.push_back(p);
    guardarPedidos();

    Utils::setColorGreen();
    std::cout << "[INFO] Pedido registrado con exito!\n";
    Utils::resetColor();
}

// ============================================================
// CANCELAR PEDIDO
// ============================================================

// Cancela el último pedido registrado
void SistemaPedidos::cancelarUltimoPedido() {
    if (pedidos.empty()) {
        Utils::setColorRed(); 
        std::cout << "[ERROR] No hay pedidos para cancelar\n"; 
        Utils::resetColor();
        return;
    }

    pedidos.back().setEstado(Estado::CANCELADO);
    guardarPedidos();

    Utils::setColorGreen(); 
    std::cout << "[INFO] Ultimo pedido cancelado\n"; 
    Utils::resetColor();
}

// ============================================================
// BÚSQUEDA DE PEDIDOS
// ============================================================

// Busca un pedido por ID y devuelve puntero (nullptr si no existe)
Pedido* SistemaPedidos::buscarPedidoPorId(int id) {
    for (auto& p : pedidos)
        if (p.getId() == id)
            return &p;
    return nullptr;
}

// Permite al usuario buscar un pedido e imprimirlo
void SistemaPedidos::buscarPedido() {
    if (pedidos.empty()) {
        Utils::setColorRed();
        std::cout << "[ERROR] No hay pedidos registrados.\n";
        Utils::resetColor();
        return;
    }

    int idBuscar;
    Utils::setColorYellow();
    std::cout << "[PREGUNTA] Ingrese el ID del pedido a buscar: ";
    Utils::resetColor();
    std::cin >> idBuscar;

    Pedido* p = buscarPedidoPorId(idBuscar);
    if (!p) {
        Utils::setColorRed();
        std::cout << "[ERROR] Pedido no encontrado.\n";
        Utils::resetColor();
        return;
    }

    Utils::setColorGreen();
    std::cout << "[INFO] Pedido encontrado:\n";
    Utils::resetColor();
    p->mostrarPedido();
}

// ============================================================
// MODIFICAR PEDIDO
// ============================================================

void SistemaPedidos::modificarPedido(int id) {
    Pedido* p = buscarPedidoPorId(id);
if (!p) { 
    Utils::setColorRed(); 
    std::cout << "[ERROR] Pedido no encontrado\n"; 
    Utils::resetColor(); 
    return; 
}

// ======= Nuevo bloque para reactivar pedido =======
if (p->getEstado() == Estado::CANCELADO) {
    char opcion;
    Utils::setColorYellow();
    std::cout << "[PREGUNTA] Este pedido esta cancelado. Desea reactivarlo? (S/N): ";
    Utils::resetColor();
    std::cin >> opcion;

    if (opcion == 'S' || opcion == 's') {
        p->setEstado(Estado::ACTIVO);
        guardarPedidos();
        Utils::setColorGreen();
        std::cout << "[INFO] Pedido reactivado correctamente\n";
        Utils::resetColor();
        return; // Salimos porque solo queríamos reactivarlo
    } else {
        Utils::setColorRed();
        std::cout << "[INFO] Pedido sigue cancelado\n";
        Utils::resetColor();
        return;
    }
}

    int opcion;
    Utils::setColorYellow(); 
    std::cout << "[PREGUNTA] 1.Modificar Producto 2.Eliminar Producto: "; 
    Utils::resetColor();
    std::cin >> opcion; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(opcion == 1){
        int index; 
        std::cout << "Indice del producto a modificar: "; 
        std::cin >> index; 
        index--; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(index < 0 || index >= (int)p->getProductos().size()) { 
            Utils::setColorRed(); 
            std::cout << "[ERROR] Indice invalido\n"; 
            Utils::resetColor(); 
            return; 
        }

        Producto prod;
        std::string nombre; double precio; int cantidad; std::string catStr;

        std::cout << "Nuevo nombre: "; std::getline(std::cin, nombre); prod.setNombre(nombre);
        std::cout << "Nuevo precio: "; std::cin >> precio; prod.setPrecio(precio);
        std::cout << "Nueva cantidad: "; std::cin >> cantidad; prod.setCantidad(cantidad); std::cin.ignore();
        std::cout << "Nueva categoria: "; std::getline(std::cin, catStr);
        try { 
            prod.setCategoria(Utils::stringToCategoria(catStr)); 
        } catch(...) { 
            prod.setCategoria(Categoria::BEBIDAS); 
        }

        p->modificarProducto(index, prod);

    } else if(opcion == 2){
        int index; 
        std::cout << "Indice del producto a eliminar: "; 
        std::cin >> index; 
        index--;

        if(index < 0 || index >= (int)p->getProductos().size()) { 
            Utils::setColorRed(); 
            std::cout << "[ERROR] Indice invalido\n"; 
            Utils::resetColor(); 
            return; 
        }

        p->eliminarProducto(index);

    } else { 
        Utils::setColorRed(); 
        std::cout << "[ERROR] Opcion invalida\n"; 
        Utils::resetColor(); 
        return; 
    }

    guardarPedidos();
    Utils::setColorGreen(); 
    std::cout << "[INFO] Pedido modificado\n"; 
    Utils::resetColor();
}

// ============================================================
// MOSTRAR TODOS LOS PEDIDOS
// ============================================================

void SistemaPedidos::mostrarPedidos() const {
    if (pedidos.empty()) {
        Utils::setColorRed();
        std::cout << "[INFO] No hay pedidos registrados.\n";
        Utils::resetColor();
        return;
    }

    for (const auto& p : pedidos) {
        p.mostrarPedido();  // Método de la clase Pedido
        std::cout << "-----------------------------\n";
    }
}

// ============================================================
// VENTAS
// ============================================================

// Total de ventas considerando solo pedidos activos
void SistemaPedidos::ventasTotales() const {
    double total = 0;
    for (const auto& p : pedidos) 
        if (p.getEstado() == Estado::ACTIVO) 
            total += p.calcularTotal();

    Utils::setColorGreen(); 
    std::cout << "[INFO] Total ventas activas: S/ " << total << "\n"; 
    Utils::resetColor();
}

// Total de ventas por categoría
void SistemaPedidos::ventasPorCategoria() const {
    double bebidas=0, pollo=0, medio=0;

    for (const auto& p : pedidos) {
        if (p.getEstado() != Estado::ACTIVO) continue;

        for (const auto& prod : p.getProductos()) {
            switch(prod.getCategoria()){
                case Categoria::BEBIDAS: bebidas += prod.getPrecio() * prod.getCantidad(); break;
                case Categoria::POLLO_ENTERO: pollo += prod.getPrecio() * prod.getCantidad(); break;
                case Categoria::MEDIO_POLLO: medio += prod.getPrecio() * prod.getCantidad(); break;
            }
        }
    }

    Utils::setColorGreen();
    std::cout << "[INFO] Total Bebidas: S/ " << bebidas << "\n";
    std::cout << "[INFO] Total Pollo Entero: S/ " << pollo << "\n";
    std::cout << "[INFO] Total Medio Pollo: S/ " << medio << "\n";
    Utils::resetColor();
}