#include <iostream>
using namespace std;
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



