#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Categoria.h" // Incluimos Categoria.h para poder usar el tipo enumerado Categoria

// ================================
// Clase Utils
// ================================
// La clase Utils se usa como una **clase de utilidades estáticas**. 
// No necesita instanciar objetos, ya que todos sus métodos son 'static'.
// Funciona como un conjunto de herramientas auxiliares para:
// 1. Manejo de colores en la consola.
// 2. Lectura de contraseñas de forma segura.
// 3. Conversión entre el tipo Categoria y su representación en string.
class Utils {
public:
    // ================= Colores =================
    // Métodos para cambiar el color de texto en la consola.
    // Se usan para mejorar la visualización de mensajes según el contexto.
    
    // Cambia el color del texto a rojo
    static void setColorRed();

    // Cambia el color del texto a verde
    static void setColorGreen();

    // Cambia el color del texto a amarillo
    static void setColorYellow();

    // Resetea el color del texto al color por defecto de la consola
    static void resetColor();

    // ================= Contraseña =================
    // Método para pedir al usuario una contraseña de manera segura.
    // Recibe un mensaje de prompt y devuelve la contraseña ingresada como string.
    static std::string getPassword(const std::string& prompt);

    // ================= Categoría =================
    // Métodos para convertir entre el tipo enumerado Categoria y strings.
    
    // Convierte un valor de Categoria a su representación en string.
    static std::string categoriaToString(Categoria cat);

    // Convierte un string a su correspondiente valor de Categoria.
    // Esto permite, por ejemplo, leer categorías desde un archivo o entrada del usuario.
    static Categoria stringToCategoria(const std::string& str);
};

#endif