#include <iostream>
#include <cstring>

using namespace std;

int Cadena(char*);

int main()
{
    char palabra[15],*puntero;
    puntero = palabra;
    cout<<"Digita una palabra:";cin>>puntero;
    cout<<"La cantidad de letras es: "<<Cadena(puntero);


    return 0;
}

int Cadena(char *puntero){
    int cantidad = strlen(puntero),cont=0;
    for(int i=0;i<cantidad;i++){
        switch (puntero[i])
        {
        case 'a': cont++;
        break;

        case 'e': cont++;
        break;

        case 'i': cont++;
        break;

        case 'o': cont++;
        break;

        case 'u': cont++;
        break;
        }
    }
    return cont;
}