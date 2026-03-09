#include "utils.h"
#include <iostream>
#include <conio.h>      // Para _getch(), lectura de caracteres sin mostrar en consola
#include <algorithm>    // Para std::transform
#include <stdexcept>    // Para std::invalid_argument

// ================= Colores =================
// Implementación de los métodos estáticos para cambiar el color del texto en consola.
// Los códigos ANSI (\033[XXm) son códigos de escape que la mayoría de consolas soportan.
void Utils::setColorRed()   { std::cout << "\033[31m"; }  // Rojo
void Utils::setColorGreen() { std::cout << "\033[32m"; }  // Verde
void Utils::setColorYellow(){ std::cout << "\033[33m"; }  // Amarillo
void Utils::resetColor()    { std::cout << "\033[0m";  }  // Resetea al color por defecto

// ================= Contraseña =================
// Método para leer una contraseña de forma segura desde la consola.
// Uso de _getch() permite capturar caracteres sin mostrarlos.
// Cada caracter ingresado se reemplaza por '*'.
std::string Utils::getPassword(const std::string& prompt) {
    std::string password; // Almacena la contraseña
    char ch;

    std::cout << prompt;  // Muestra el mensaje al usuario

    while ((ch = _getch()) != 13) { // 13 = ENTER
        if (ch == 8) { // 8 = BACKSPACE
            if (!password.empty()) {
                password.pop_back();       // Elimina el último caracter
                std::cout << "\b \b";     // Borra el '*' en consola
            }
        } else {
            password.push_back(ch);       // Añade caracter al password
            std::cout << "*";             // Muestra '*' en consola
        }
    }
    std::cout << std::endl;
    return password;                     // Devuelve la contraseña ingresada
}

// ================= Categoría =================
// Convierte un valor de Categoria a string para mostrarlo o guardarlo.
std::string Utils::categoriaToString(Categoria cat) {
    switch (cat) {
        case Categoria::BEBIDAS:       return "Bebidas";
        case Categoria::POLLO_ENTERO:  return "Pollo Entero";
        case Categoria::MEDIO_POLLO:   return "Medio Pollo";
        default:                        return "Desconocida";
    }
}

// Convierte un string a un valor de Categoria correspondiente.
// Esto permite leer categorías desde archivos o entradas del usuario.
Categoria Utils::stringToCategoria(const std::string& str) {
    std::string s = str;
    // Convierte todo a minúsculas para hacer la comparación insensible a mayúsculas/minúsculas
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);

    if (s == "bebidas")       return Categoria::BEBIDAS;
    if (s == "pollo entero")  return Categoria::POLLO_ENTERO;
    if (s == "medio pollo")   return Categoria::MEDIO_POLLO;

    // Si no coincide con ninguna categoría, lanza excepción
    throw std::invalid_argument("Categoría inválida");
}