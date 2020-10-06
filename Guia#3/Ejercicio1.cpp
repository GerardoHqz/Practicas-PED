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
int size(Pilas*);
void mostrar(Pilas*);

int main(){
    Pilas stack;
    int opcion=0,n=0;
    inicializar(&stack);
    cout << "\n" << "***** MENU DE PILAS *****" << endl;
    cout << "1. Ingresar elemento a la pila" << endl;
    cout << "2. Eliminar elemento de la pila" << endl;
    cout << "3. Cantidad de elementos en la pila" << endl;
    cout << "4. Salir del menu" << endl;

    do{
        cout<<"\nIngrese la opcion a ejecutar: ";cin>>opcion;

        switch (opcion){
        case 1:
            cout<<"Ingrese un elemento para agregar: ";cin>>n;
            push(&stack,n);
            cout<<"Pila actualizada: \n";
            mostrar(&stack);
            break;
        case 2:
            cout<<"Elemento elminado....\n";
            pop(&stack);
            cout<<"Pila actualizada\n";
            mostrar(&stack);

        case 3:
            cout<<"La cantidad de elementos en la pila son: "<<size(&stack);
            break;

        case 4:
            cout<<"El programa ha finalizado\n";
        
        default:
            cout<<"Opcion no valida\n";
            break;
        }

    }while(opcion != 4);

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

int size(Pilas *stack){
    nodo *clone = *stack;
    int cont = 0;
    bool isEmpty = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            cont++;
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
    return cont;
}

