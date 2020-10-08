#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int num1;
    int num2;
    Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,int,int);
void pop(Cola*);
void ShowQueue(Cola*);

int main(){
    Nodo node;
    Cola cola;
    initialize(&cola);
    int opcion,num1,num2;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar par de numero a la cola.\n";
        cout<<"2.Mostrar pares de numeros.\n";
        cout<<"3.Salir.\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nIngrese un numero: ";cin>>num1;
                cout<<"Ingrese un numero: ";cin>>num2; 
                push(&cola,num1,num2);
                system("pause");
                break;
            case 2:
                ShowQueue(&cola);
                system("pause");
                break;
            case 3:
                cout<<"\nFin del programa\n";
                status = false ;   
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
    queue->frente = NULL;
    queue->final = NULL;
}

bool empty(Cola *queue){
    return(queue->frente == NULL) ? true:false;
}

void push(Cola *queue, int dato1,int dato2){
    Nodo *aux = new Nodo;
    aux->num1 = dato1;
    aux->num2 = dato2;
    aux->siguiente = NULL;

    if(queue->final == NULL){
        queue->frente = aux;
    }
    else{
        (queue->final)->siguiente = aux;
    }     
    queue->final = aux;
}

void pop(Cola *queue){
    if(empty(queue)){
        cout<<"Underflow!\n";
        return;
    }
    Nodo *aux = queue->frente;
    queue->frente = aux->siguiente;
    
    if(queue->frente == NULL){
        queue->final = NULL;
    }
    delete(aux);
}

void ShowQueue(Cola *queue){
    Nodo *aux = queue->frente;
    if(empty(queue)){
        cout<<"La cola esta vacia\n";
    }
    else{
        cout<<"\nMostrando pares:";
        while(aux){
            cout<<"("<<aux->num1<<","<<aux->num2<<")";
            aux = aux->siguiente;
        }
    }
    cout<<endl;
}