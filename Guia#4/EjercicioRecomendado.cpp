#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Persona{
    string platillo;
    float pago;
    Persona *siguiente;
};

struct Cola{
    Persona *front;
    Persona *back;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,string,float,int);
void pop(Cola*);

int main(){
    Cola queue;
    int opcion,tiempo=4;
    float paypal;
    string comidita;
    bool status = true;
    initialize(&queue);

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar Pedido.\n";
        cout<<"2.Despachar pedido\n";
        cout<<"3.Salir\n";
        cout<<"Elija opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\n***GERARDINI'S***";
                cout<<"\n1.Poshito en salsa $5";
                cout<<"\n2.Costishita entomatada $8.50";
                cout<<"\n3.Alitash con salsita $7.50";
                cout<<"\n4.Platanitus Salados $4";
                cout<<"\n5.Carne ashada  $5.25";
                cout<<"\nEscriba el nombre de su platillo: ";getline(cin,comidita);
                cout<<"Pagara: ";cin>>paypal;
                tiempo ++;
                push(&queue,comidita,paypal,tiempo);
                system("pause");
                break;
            case 2:
                pop(&queue);
                cout<<"\nPedido despachado\n";
                tiempo--;
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

void push(Cola *queue,string nombre,float cobros,int tiempo){
    float total=0;
    Persona *aux = new Persona;
    aux->platillo = nombre;
    aux->pago = cobros;
    aux->siguiente = NULL;

    if(queue->back == NULL){
        queue->front = aux;
        total += aux->pago;
    }
    else{
        queue->back->siguiente = aux;
        total += aux->pago;
    }
    queue->back = aux;
    cout<<"\nTiempo de espera "<<tiempo<<" minutos";
    cout<<"\nSe cobro $"<<total<<"\n";
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