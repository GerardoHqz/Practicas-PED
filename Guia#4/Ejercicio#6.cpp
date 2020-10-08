#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

struct Cola{
    Nodo *front;
    Nodo *back;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,int);
void pop(Cola*);
void ShowQueue(Cola*);


int main(){
    Cola queue,impar,par;
    int opcion,dato,num;
    bool status = true;
    initialize(&queue);
    initialize(&impar);
    initialize(&par);


    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar numeros\n";
        cout<<"2.Verificar y separar numeros\n";
        cout<<"3.Mostrando cola de impares\n";
        cout<<"4.Mostrando cola de pares\n";
        cout<<"5.Salir\n";
        cout<<"Elija opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"\nDigite un numero: ";cin>>dato;
                push(&queue,dato);
                system("pause");
                break;

            case 2:
                cout<<"\nSe han seprado los numeros por pares e impares\n";
                if(empty(&queue)){
                    cout<<"Underflow!\n";
                }
                else{
                    while(!empty(&queue)){
                        if((queue.front)->dato%2 == 0){
                            num = queue.front->dato; 
                            push(&par,num);
                            pop(&queue);
                        }
                        else{
                            num = queue.front->dato; 
                            push(&impar,num);
                            pop(&queue);
                        }
                    }
                }
                system("pause");
                break;

            case 3:
                cout<<"\nMostrando cola de numeros impares: ";
                ShowQueue(&impar);
                system("pause");
                break;

            case 4:
                cout<<"\nMostrando cola de numeros pares: ";
                ShowQueue(&par);
                system("pause");
                break;

            case 5:
                cout<<"\nFin del programa.\n";
                status = false;
                break;
            default:
                cout<<"\nOpcion no valida\n";
                system("pause");
                break;        
        }
    }while(status);

    return 0;
}

void initialize(Cola *queue){
    queue->back = NULL;
    queue->front = NULL;
}

bool empty(Cola *queue){
    return(queue->back == NULL) ? true:false;
}

void push(Cola *queue,int numero){
    Nodo *aux = new Nodo;
    aux->dato = numero;
    aux->siguiente = NULL;

    if(queue->back == NULL){
        queue->front = aux;
    }
    else{
        queue->back->siguiente = aux;
    }
    queue->back = aux;
}

void pop(Cola *queue){
    if(empty(queue)){
        cout<<"Unferflow!\n";
        return;
    }
    Nodo *aux = queue->front;
    queue->front = aux->siguiente;

    if(queue->front == NULL){
        queue->back = NULL;
    }
    delete (aux);
}

void ShowQueue(Cola *queue){
    Nodo *aux = queue->front;
    if(empty(queue)){
        cout<<"La cola esta vacia\n";
    }
    else{
        while(aux){
            cout<<aux->dato<<"  ";
            aux = aux->siguiente;
        }
    }
    cout<<endl;
}