#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    int pago;
    Persona *siguiente;
};

struct Cola{
    Persona *front;
    Persona *back;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,string,int);
void pop(Cola*);
int cobrar(Cola*,int);


int main(){
    Cola queue;
    string nombre;
    int opcion,pago,cobros=0,paguitos=0;
    bool status = true;
    initialize(&queue);

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar Cliente\n";
        cout<<"2.Cobrar\n";
        cout<<"3.Salir\n";
        cout<<"Elija opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nDigite el nombre del cliente: ";getline(cin,nombre);
                cout<<"Digite el monto a cobrar: ";cin>>pago;
                cout<<"Cliente ingresado a la cola!\n";
                system("pause");
                push(&queue,nombre,pago);
                break;
            case 2:
                paguitos += cobrar(&queue,cobros);
                cout<<"\nSe ha cobrado $"<<paguitos<<" a los clientes\n";
                system("pause");
                break;
            case 3:
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

void push(Cola *queue,string nombre,int paid){
    Persona *aux = new Persona;
    aux->nombre = nombre;
    aux->pago = paid;
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
    Persona *aux = queue->front;
    queue->front = aux->siguiente;

    if(queue->front == NULL){
        queue->back = NULL;
    }
    delete (aux);
}

int cobrar(Cola *queue,int cobros){
    if(empty(queue)){
        cout<<"No hay clientes en la cola.\n";
        return 0;
    }
    else{
        while(!empty(queue)){
            cobros += queue->front->pago;
            cout<<"\nCobro realizado...\n";
            pop(queue);
        }
        return cobros; 
    }
}
