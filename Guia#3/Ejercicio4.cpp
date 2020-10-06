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
void inverso(Pilas*,Pilas*);

int main(){
    Pilas stack,inversa;
    int n;
    inicializar(&stack);
    inicializar(&inversa);

    do{
        cout<<"Digite un numero: ";cin>>n;
        push(&stack,n);
    }while(n != 0);

    cout<<"Mostrando pila original: \n";
    mostrar(&stack);

    inverso(&stack,&inversa);

    cout<<"\nPila invertida: \n";
    mostrar(&inversa);

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
            cout<<clone->dato<<" , ";
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
}

void inverso(Pilas *stack,Pilas *inversa){
    if(Empty(stack)){
        return;
    }
    else{
        int aux = (*stack)->dato;
        pop(stack);
        push(inversa,aux);

        inverso(stack,inversa);
    }
}