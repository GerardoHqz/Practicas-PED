#include <iostream>
#include <cstring>

using namespace std;

int Caracter(char*,char);

int main()
{
    char palabra[15],*puntero,n;
    puntero = palabra; 

    cout<<"Digita una palabra: ";cin>>puntero;
    cout<<"Que caracter desea buscar: ";cin>>n;
    cout<<"Caracter encontrado en la posicion: "<<Caracter(puntero,n);

    return 0;
}
int Caracter(char *puntero,char n){
    int cantidad = strlen(puntero);
    int cont=0;

    for(int i=0;i<cantidad;i++){
        if(*puntero== n){
            i = cantidad;
        }
        puntero = puntero + 1;
        cont++;
    }
    return cont;
}