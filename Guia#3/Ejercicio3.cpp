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
bool isPair(int);
void ParImpar(Pilas*,int,int);

int main(){
    Pilas stack;
    inicializar(&stack);
    int n,impares=0,pares=0;
    
    do{
        cout<<"Digite un numero: ";cin>>n;
        push(&stack,n);
    }while(n != 0);
    
    ParImpar(&stack,pares,impares);

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

bool isPair(int num) {
    if (num % 2 == 0) {
        return true;
    }else {
        return false;
    }
}

void ParImpar(Pilas *stack,int par ,int impar){
    if(Empty(stack)){
        cout<<"Mostrando suma de numeros pares: "<<par<<endl;
        cout<<"Mostrando suma de numeros impares: "<<impar;
        return;
    }
    else{
        if(isPair((*stack)->dato)){
            par += (*stack)->dato;
        }
        else{
            impar += (*stack)->dato;
        }
        pop(stack);
        ParImpar(stack,par,impar);
    }
}

