#include <iostream>
#include <cstring>
using namespace std;
int direccion(char *);
/*Escribir un programa en C++ que reciba una cadena de caracteres, luego escribir una
función que reciba la dirección de inicio de la cadena y devuelva el número de vocales que
hay en la cadena.*/

int main (){

    char cadena[20];
    char *puntero;
    
    cout<<"Ingrese la palabra deseada:";
    cin>>cadena;
    puntero = cadena;
    cout<<direccion(puntero);

    return 0;


   
}
int direccion(char *puntero )
{

    int  numero=0, cantidad = strlen(puntero);
    for (size_t i = 0; i < cantidad; i++)
    {
        switch (puntero[i])
        {
            case 'a': numero++; break;
            case 'e': numero++; break;
            case 'i': numero++; break;
            case 'o': numero++; break;
            case 'u': numero++; break;
           
        }
    }

    return numero;


}