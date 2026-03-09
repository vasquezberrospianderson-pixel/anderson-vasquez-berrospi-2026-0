#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;


// EXCEPCIÓN PERSONALIZADA

class CuentaNoEncontrada : public runtime_error {
public:
    CuentaNoEncontrada(const string& mensaje)
        : runtime_error(mensaje) {}
};


// CLASE CUENTA BANCARIA

class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    double saldo;

public:
    CuentaBancaria(int numero, const string& nombre, double saldoInicial = 0)
        : numeroCuenta(numero), titular(nombre), saldo(saldoInicial) {}

    void depositar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a depositar debe ser positivo.");
        }
        saldo += monto;
    }

    void retirar(double monto) {
        if (monto <= 0) {
            throw invalid_argument("El monto a retirar debe ser positivo.");
        }
        if (monto > saldo) {
            throw runtime_error("Saldo insuficiente.");
        }
        saldo -= monto;
    }

    double consultarSaldo() const {
        return saldo;
    }

    int getNumeroCuenta() const {
        return numeroCuenta;
    }

    void mostrar() const {
        cout << "Cuenta: " << numeroCuenta
             << " | Titular: " << titular
             << " | Saldo: " << saldo << endl;
    }
};


// CLASE BANCO

class Banco {
private:
    vector<CuentaBancaria> cuentas;

public:
    void agregarCuenta(int numero, const string& titular) {
        cuentas.emplace_back(numero, titular);
    }

    CuentaBancaria& buscarCuenta(int numero) {
        for (auto& cuenta : cuentas) {
            if (cuenta.getNumeroCuenta() == numero) {
                return cuenta;
            }
        }
        throw CuentaNoEncontrada("La cuenta no existe.");
    }

    void mostrarCuentas() const {
        if (cuentas.empty()) {
            cout << "No hay cuentas registradas.\n";
            return;
        }
        for (const auto& cuenta : cuentas) {
            cuenta.mostrar();
        }
    }
};


// FUNCIÓN PRINCIPAL 

int main() {
    Banco banco;
    int opcion;

    while (true) {
        try {
            cout << "\n--- SISTEMA BANCARIO ---\n";
            cout << "1. Crear cuenta\n";
            cout << "2. Depositar dinero\n";
            cout << "3. Retirar dinero\n";
            cout << "4. Consultar saldo\n";
            cout << "5. Mostrar todas las cuentas\n";
            cout << "6. Salir\n";
            cout << "Seleccione una opcion: ";

            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Entrada invalida. Debe ingresar un numero.");
            }

            if (opcion < 1 || opcion > 6) {
                throw out_of_range("Opcion fuera del menu.");
            }

            if (opcion == 6) {
                cout << "Saliendo del sistema...\n";
                break;
            }

            int numeroCuenta;
            double monto;
            string titular;

            switch (opcion) {
            case 1:
                cout << "Numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Titular: ";
                cin >> titular;
                banco.agregarCuenta(numeroCuenta, titular);
                cout << "Cuenta creada correctamente.\n";
                break;

            case 2:
                cout << "Numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Monto a depositar: ";
                cin >> monto;
                banco.buscarCuenta(numeroCuenta).depositar(monto);
                cout << "Deposito realizado.\n";
                break;

            case 3:
                cout << "Numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Monto a retirar: ";
                cin >> monto;
                banco.buscarCuenta(numeroCuenta).retirar(monto);
                cout << "Retiro realizado.\n";
                break;

            case 4:
                cout << "Numero de cuenta: ";
                cin >> numeroCuenta;
                cout << "Saldo: "
                     << banco.buscarCuenta(numeroCuenta).consultarSaldo()
                     << endl;
                break;

            case 5:
                banco.mostrarCuentas();
                break;
            }
        }
        catch (const out_of_range& e) {
            cout << "Error de rango: " << e.what() << endl;
        }
        catch (const CuentaNoEncontrada& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error de argumento: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error de ejecucion: " << e.what() << endl;
        }
        catch (const exception& e) {
            cout << "Error general: " << e.what() << endl;
        }
    }

    return 0;
}