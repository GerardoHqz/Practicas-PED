#include <iostream>
#include <string.h>

using namespace std;

struct Libro{
    string titulo;
    int numPags;
    Libro *next;
};
typedef Libro *Pilas;

void inicializar(Pilas*);
bool Empty(Pilas*);
void push(Pilas*,string,int);
void pop(Pilas*);
void CantPags(Pilas*,string);
void mostrar(Pilas*);


int main(){
    Pilas stack;
    string titulo;
    inicializar(&stack);
    
    push(&stack, "Libro 1", 250);
    push(&stack, "Libro 2", 150);
    push(&stack, "Libro 3", 175);
    push(&stack, "Libro 4", 200);

    cout<<"Ingrese el libro del titulo a buscar: ";getline(cin,titulo);
    CantPags(&stack,titulo);


    return 0;
}

void inicializar(Pilas *stack){
    *stack = NULL;
}

bool Empty(Pilas *stack){
    return *stack == NULL;
}

void push(Pilas *stack,string title,int n){
    Libro *AuxNodo = new Libro();
    AuxNodo ->titulo = title;
    AuxNodo->numPags = n;
    AuxNodo->next = *stack;
    *stack = AuxNodo;
}

void pop(Pilas *stack){
    if(!Empty(stack)){
        Libro *aux = *stack;
        *stack = (*stack)->next;
        delete aux;
    }
    else{
        return;
    }
}

void CantPags(Pilas *stack,string title){
    if((*stack)->titulo == title){
        cout<<(*stack)->titulo<<" tiene "<<(*stack)->numPags<<" paginas\n";
        return;
    }
    else{
        pop(stack);
        CantPags(stack,title);
    }
}

void mostrar(Pilas *stack){
    Libro *clone = *stack;
    bool isEmpty = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            cout<<clone->titulo<<", tiene "<<clone->numPags<<" paginas\n";
            clone = clone->next;
        }
        else{
            isEmpty = true;
        }
    }
}
