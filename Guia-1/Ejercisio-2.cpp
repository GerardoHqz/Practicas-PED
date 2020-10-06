#include <iostream>

using namespace std;

int main()
{
    int x,y,*puntero1,*puntero2;
    cout<<"Digite un valor: ";cin>>x;
    cout<<"Digite un valor: ";cin>>y;
    puntero1 = &x;
    puntero2 = &y;

    cout<<"Valor 1: "<<*puntero1<<endl;
    cout<<"Direccion: "<<puntero1<<endl;
    cout<<"Valor 2: "<<*puntero2<<endl;
    cout<<"Direccion: "<<puntero2;

    return 0;
}