#include <iostream>
using namespace std;
int main(){
    int a,b;
cout<<"ingrese el 1 numero: ";
cin>>a;
cout<<"ingrese el 2 numero: ";
cin>>b;
if (a>b){
    cout<<"el primer numero ingresado es mayor que el segundo."<<endl;
}  else if (a < b){
    cout<<"el segundo numero ingrresado es mayor que el primer numero."<<endl;
} else{
    cout<<"ambos numeros son iguales."<<endl;
}
    return 0;
}