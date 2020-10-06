#include <iostream>

using namespace std;

void Pedir_Lista(int,int vector[100]);
void Valor_Maximo(int,int vector[100]);

int main()
{
    int tamano,vector[100];
    Pedir_Lista(tamano,vector);

    return 0;
}

void Pedir_Lista(int tamano,int vector[100]){
    int max=0, *puntero;
    cout<<"Cuantos numeros desea alegrar a la lista: ";cin>>tamano;
    for(int i=0;i<tamano;i++){
        cout<<"Digite un valor: ";cin>>vector[i];
        if(vector[i] > max){
            max = vector[i];
        }
    }
    puntero = &max;
    cout<<"El numero mayor de la lista es: "<<*puntero;
}
