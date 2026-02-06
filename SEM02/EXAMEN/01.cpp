#include <iostream>
using namespace std;
int main () {
    int opcion, units;
    float unitPrice, ingreso;
    int transactionCode;
    float ingresoNeto = 0;
    float mayorIng = 0;
    float menorIng = 0;
    float sumaVentas = 0;
    int ventasValidas = 0;
    int devoluciones = 0;
    int transInvalidas = 0;
    int diaCerrado = 0; 
    int salir = 0;
    while (salir == 0) {
        cout << "Elija una opcion" << endl;
        cout << "1: Registrar transaccion" << endl;
        cout << "2: Reporte de ventas del dia" << endl;
        cout << "3: Reporte por transaccion (A / B / C / D)" << endl;
        cout << "4: Cerrar dia" << endl;
        cout << "5: Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                if (diaCerrado == 1) {
                    cout << "NO SE PUEDEN REGISTRAR MAS TRANSACCIONES. DIA CERRADO." << endl;
                } else {
                    cout << "Ingrese units: ";
                    cin >> units;
                    cout << "Ingrese unitPrice: ";
                    cin >> unitPrice;
                    cout << "Ingrese transactionCode: ";
                    cin >> transactionCode;
                    if (units != 0 && unitPrice > 0) {
                        ingreso = units * unitPrice;
                        ingresoNeto += ingreso;
                        if (ventasValidas + devoluciones == 0) {
                            mayorIng = ingreso;
                            menorIng = ingreso;
                        } else {
                            if (ingreso > mayorIng) mayorIng = ingreso;
                            if (ingreso < menorIng) menorIng = ingreso;
                        }
                        if (units > 0) {
                            ventasValidas++;
                            sumaVentas += ingreso;
                        } else {
                            devoluciones++;
                        }
                        int codeAbs = transactionCode;
                        if (codeAbs < 0) codeAbs = -codeAbs;
                        int suma = 0;
                        int temp = codeAbs;
                        int digitos = 0;
                        if (temp == 0) {
                            digitos = 1;
                        } else {
                            while (temp > 0) {
                                suma += temp % 10;
                                temp /= 10;
                                digitos++;
                            }
                        }
                        if (suma % 2 == 0 && suma % 4 == 0)
                            cout << "A" << endl;
                        else if (suma % 2 != 0 && suma % 6 == 0)
                            cout << "B" << endl;
                        else if (digitos == 3)
                            cout << "C" << endl;
                        else
                            cout << "D" << endl;
                    } else {
                        cout << "Transaccion invalida" << endl;
                        transInvalidas++;
                    }
                }
                break;
            case 2:
                cout << "INGRESO_NETO=" << ingresoNeto << endl;
                cout << "VENTAS_VALIDAS=" << ventasValidas << endl;
                cout << "DEVOLUCIONES=" << devoluciones << endl;
                cout << "TRANS_INVALIDAS=" << transInvalidas << endl;
                cout << "MAYOR_ING=" << mayorIng << endl;
                cout << "MENOR_ING=" << menorIng << endl;
                if (ventasValidas > 0)
                    cout << "PROM_VENTA=" << (sumaVentas / ventasValidas) << endl;
                else
                    cout << "PROM_VENTA=NO EXISTE" << endl;
                break;
            case 3:
                cout << "El reporte por transaccion se muestra al registrar cada transaccion valida" << endl;
                break;
            case 4:
                diaCerrado = 1;
                cout << "Dia cerrado." << endl;
                break;
            case 5:
                salir = 1;
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
    return 0;
}