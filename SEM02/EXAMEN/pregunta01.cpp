#include <iostream>
using namespace std;
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
bool primo(int x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return 0;
    return 1;
}
bool masImpares(int x){
    x=abs(x);
    int p=0,i=0;
    if(x==0) p++;
    while(x){
        ((x%10)%2==0)?p++:i++;
        x/=10;
    }
    return i>p;
}
int main(){
    int N,n,max,min,cp=0,sp=0,cpp=0,may;
    bool ok=0;
    cout<<"Ingrese cant de numeros que ingresara: ";
    cin>>N;
    for(int k=1;k<=N;k++){
        cout<<"Ingrese numero "<<k<<": ";
        cin>>n;
        if(k==1) max=min=n;
        else max=n>max?n:max, min=n<min?n:min;
        if(primo(n)) cp++;
        if(n>0 && n%2==0) sp+=n, cpp++;
        if(masImpares(n) && (!ok || n>may))
            may=n, ok=1;
    }
    cout<<"\nMaximo: "<<max<<"\nMinimo: "<<min<<endl;
    cout<<"Primos: ";
    cp?cout<<cp:cout<<"NO EXISTE";
    cout<<endl;
    cout<<"Promedio pares positivos: ";
    cpp?cout<<(float)sp/cpp:cout<<"NO EXISTE";
    cout<<endl;
    cout<<"Mayor con mas digitos impares que pares: ";
    ok?cout<<may:cout<<"NO EXISTE";
    return 0;
}



<<<<<<< HEAD
=======
=======
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
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
