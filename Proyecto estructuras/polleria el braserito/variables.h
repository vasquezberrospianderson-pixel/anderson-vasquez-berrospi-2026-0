#ifndef VARIABLES_H
#define VARIABLES_H

#include <string>
using namespace std;

/*
--------------------------------------------------
Archivo: variables.h
Propósito:
    Definir las constantes y estructuras utilizadas
    en el sistema de gestión de pedidos.
--------------------------------------------------
*/

// ===== CONSTANTES =====
const int MAX_PEDIDOS = 100;  // Cantidad máxima de pedidos permitidos
const int MAX_ITEMS = 10;     // Cantidad máxima de productos por pedido

// ===== ESTRUCTURA: Item =====
struct Item {
    string nombre;
    float precio;
    int cantidad;
};

// ===== ESTRUCTURA: Pedido =====
struct Pedido {
    Item* items;
    int numItems;
    bool activo;
};

#endif