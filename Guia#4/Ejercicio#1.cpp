#include <iostream>

using namespace std;



struct Nodo{
    int elemento;
    Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,int);
void pop(Cola*);
void ShowQueue(Cola*);

int main(){
    Nodo node;
    Cola cola;
    initialize(&cola);
    int dato,opcion;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar elemento a la cola\n";
        cout<<"2.Sacar elemento de la cola\n";
        cout<<"3.Mostrar elementos de la cola\n";
        cout<<"4.Salir\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nIngrese un dato: ";cin>>dato;
                push(&cola,dato);
                cout<<"Pila actual: ";
                ShowQueue(&cola);
                system("pause");
                break;
            case 2:
                cout<<"\nSacando un dato...\n";
                pop(&cola);
                ShowQueue(&cola);
                system("pause");
                break;
            case 3:
                cout<<"\nMostrando cola\n";
                ShowQueue(&cola);
                system("pause");
                break;
            case 4:
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

void push(Cola *queue, int dato){
    Nodo *aux = new Nodo;
    aux->elemento = dato;
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
        while(aux){
            cout<<aux->elemento<<" ";
            aux = aux->siguiente;
        }
    }
    cout<<endl;
}

