#include <iostream>
#include <string>
using namespace std;

// PARTE : STRUCT
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int stock;
};

const int N = 5; 
Producto productos[N];
bool productosRegistrados = false;

int main() {
    int opcion;

    do {
        cout << "\n===== MENU TIENDA =====\n";
        cout << "1. Registrar productos\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto por codigo\n";
        cout << "4. Buscar producto por nombre\n";
        cout << "5. Mostrar producto con mayor stock\n";
        cout << "6. Mostrar producto mas caro\n";
        cout << "7. Calcular valor total del inventario\n";
        cout << "8. Salir\n";

        while (true) {
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Error: debe ingresar un numero.\n";
            } else {
                cin.ignore(1000,'\n'); 
                break;
            }
        }

        switch (opcion) {
            // REGISTRAR PRODUCTOS
            case 1:
                for (int i = 0; i < N; i++) {
                    cout << "\nRegistro del producto " << i + 1 << endl;

                    //  Codigo seguro
                    while (true) {
                        cout << "Codigo: ";
                        cin >> productos[i].codigo;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Error: debe ingresar un numero.\n";
                        } else {
                            cin.ignore(1000,'\n');
                            break;
                        }
                    }

                    //  Nombre 
                    cout << "Nombre: ";
                    getline(cin, productos[i].nombre);

                    // Precio seguro 
                    while (true) {
                        cout << "Precio: ";
                        cin >> productos[i].precio;
                        if (cin.fail() || productos[i].precio <= 0) {
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Error: debe ingresar un numero mayor a 0.\n";
                        } else {
                            cin.ignore(1000,'\n');
                            break;
                        }
                    }

                    //  Stock seguro 
                    while (true) {
                        cout << "Stock: ";
                        cin >> productos[i].stock;
                        if (cin.fail() || productos[i].stock < 0) {
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Error: debe ingresar un numero 0 o mayor.\n";
                        } else {
                            cin.ignore(1000,'\n');
                            break;
                        }
                    }
                }
                productosRegistrados = true;
                cout << "\nProductos registrados correctamente.\n";
                break;

            // MOSTRAR PRODUCTOS
            case 2:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    cout << "\nCodigo\tNombre\t\tPrecio\tStock\n";
                    cout << "-------------------------------------\n";
                    for (int i = 0; i < N; i++) {
                        cout << productos[i].codigo << "\t"
                             << productos[i].nombre << "\t\t"
                             << productos[i].precio << "\t"
                             << productos[i].stock << endl;
                    }
                }
                break;

            // BUSCAR POR CODIGO
            case 3:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    int codigoBuscado;
                    while (true) {
                        cout << "Ingrese el codigo a buscar: ";
                        cin >> codigoBuscado;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Error: debe ingresar un numero.\n";
                        } else {
                            cin.ignore(1000,'\n');
                            break;
                        }
                    }

                    bool encontrado = false;
                    for (int i = 0; i < N; i++) {
                        if (productos[i].codigo == codigoBuscado) {
                            cout << "\nProducto encontrado:\n";
                            cout << "Codigo: " << productos[i].codigo << endl;
                            cout << "Nombre: " << productos[i].nombre << endl;
                            cout << "Precio: " << productos[i].precio << endl;
                            cout << "Stock: " << productos[i].stock << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "No encontrado.\n";
                }
                break;

            // BUSCAR POR NOMBRE
            case 4:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    string nombreBuscado;
                    cout << "Ingrese el nombre a buscar: ";
                    getline(cin, nombreBuscado);

                    bool encontrado = false;
                    for (int i = 0; i < N; i++) {
                        if (productos[i].nombre == nombreBuscado) {
                            cout << "\nProducto encontrado:\n";
                            cout << "Codigo: " << productos[i].codigo << endl;
                            cout << "Nombre: " << productos[i].nombre << endl;
                            cout << "Precio: " << productos[i].precio << endl;
                            cout << "Stock: " << productos[i].stock << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) cout << "No encontrado.\n";
                }
                break;

            // PRODUCTO CON MAYOR STOCK
            case 5:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    int posMayorStock = 0;
                    for (int i = 1; i < N; i++) {
                        if (productos[i].stock > productos[posMayorStock].stock)
                            posMayorStock = i;
                    }
                    cout << "\nProducto con mayor stock:\n";
                    cout << "Codigo: " << productos[posMayorStock].codigo << endl;
                    cout << "Nombre: " << productos[posMayorStock].nombre << endl;
                    cout << "Precio: " << productos[posMayorStock].precio << endl;
                    cout << "Stock: " << productos[posMayorStock].stock << endl;
                }
                break;

            // PRODUCTO MAS CARO
            case 6:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    int posMasCaro = 0;
                    for (int i = 1; i < N; i++) {
                        if (productos[i].precio > productos[posMasCaro].precio)
                            posMasCaro = i;
                    }
                    cout << "\nProducto mas caro:\n";
                    cout << "Codigo: " << productos[posMasCaro].codigo << endl;
                    cout << "Nombre: " << productos[posMasCaro].nombre << endl;
                    cout << "Precio: " << productos[posMasCaro].precio << endl;
                    cout << "Stock: " << productos[posMasCaro].stock << endl;
                }
                break;

            // VALOR TOTAL DEL INVENTARIO
            case 7:
                if (!productosRegistrados) {
                    cout << "No hay productos registrados.\n";
                } else {
                    float total = 0;
                    for (int i = 0; i < N; i++)
                        total += productos[i].precio * productos[i].stock;

                    cout << "\nValor total del inventario: S/ " << total << endl;
                }
                break;

            case 8:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 8);

    return 0;
}
