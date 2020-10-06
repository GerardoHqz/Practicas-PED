#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int dato;
    nodo *siguiente;
};
typedef nodo *Pilas;

void inicializar(Pilas*);
bool Empty(Pilas*);
void push(Pilas*,int);
void pop(Pilas*);
void mostrar(Pilas*);

int main(){
    Pilas par,impar;
    int opcion=0,n=0,tam=0;
    inicializar(&par);
    inicializar(&impar);

    cout<<"Ingrese el tamaño de sus arreglos: ";cin>>tam;

    int vector1[tam],vector2[tam],mult[tam];

    cout<<"Ingresando datos del arreglo 1.\n";
    for(int i=0;i<tam;i++){
        cout<<"Digite el elemento "<<i+1<<" :";cin>>vector1[i];
    }

    cout<<"endl;";

    cout<<"Ingresando datos del arreglo 2.\n";
    for(int i=0;i<tam;i++){
        cout<<"Digite el elemento "<<i+1<<" :";cin>>vector2[i];
    }

    cout<<"\nMultiplicando datos del arreglo 1 y 2.\n";
    for(int i=0;i<tam;i++){
        mult[i] = vector1[i] * vector2[i];
    }

    cout<<"Separando en pilas por numero par e impar....\n";
    for(int i=0;i<tam;i++){
        if(mult[i] % 2 == 0){
            push(&par,mult[i]);
        }
        else{
            push(&impar,mult[i]);
        }
        
    }

    cout<<"\nPila con numeros pares: ";
    mostrar(&par);

    cout<<"\nPila con numeros impares: ";
    mostrar(&impar);

    return 0;
}

void inicializar(Pilas *stack){
    *stack = NULL;
}

bool Empty(Pilas *stack){
    return *stack == NULL;
}

void push(Pilas *stack,int n){
    nodo *AuxNodo = new nodo();
    AuxNodo ->dato = n;
    AuxNodo->siguiente = *stack;
    *stack = AuxNodo;
}

void pop(Pilas *stack){
    if(!Empty(stack)){
        nodo *aux = *stack;
        *stack = (*stack)->siguiente;
        delete aux;
    }
    else{
        return;
    }
}

void mostrar(Pilas *stack){
    nodo *clone = *stack;
    bool isEmpty = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            cout<<clone->dato<<"  ";
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
}