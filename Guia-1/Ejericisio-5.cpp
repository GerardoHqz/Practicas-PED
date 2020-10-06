#include <iostream>

using namespace std;

int main()
{
    char palabra[] = "puntero", *puntero;
    puntero = palabra;
    
    // valor - posicion de memoria - la letra n
    cout<<*puntero<<" "<<&puntero<<" "<< *(puntero + 2) <<endl;
    //Desplazar 3 posiciones
    puntero = puntero + 3;
    //Imprimir la letra t
    cout<<*puntero<<" ";
    //Moverse a la siguiente letra
    puntero = puntero + 1;
    //Imprimir la letra e
    cout<<*puntero<<" ";
    //Moverse a la siguiente letra
    puntero = puntero + 1;
    //Imprimir la letra r
    cout<<*puntero<<" ";
    //Moverse a la siguiente letra
    puntero = puntero + 1;
    //Imprimir la letra o
    cout<<*puntero<<" ";

    return 0;
}