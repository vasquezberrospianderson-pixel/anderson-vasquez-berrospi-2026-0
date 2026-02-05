#include<iostream>
using namespace std;
int main () {
    int x=10;
    int a= (++x) + 2;
    cout<<a<<endl;

    int b= (x++) + 2;
    cout<<b<<endl;
    return 0;
}