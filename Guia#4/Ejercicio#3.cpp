#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
    char elemento;
    Nodo* siguiente;
};

struct Cola{
    Nodo* frente;
    Nodo* final;
};

void initialize(Cola*);
bool empty(Cola*);
void push(Cola*,char);
void pop(Cola*);
void ShowQueue(Cola*);
void search(Cola*,char);

int main(){
    Nodo node;
    Cola cola;
    initialize(&cola);
    int opcion;
    char caracter,buscar;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar caracter a la cola\n";
        cout<<"2.Buscar caracter en la cola\n";
        cout<<"3.Salir\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nIngrese un dato: ";cin>>caracter;
                push(&cola,caracter);
                cout<<"Pila actual: ";
                ShowQueue(&cola);
                system("pause");
                break;
            case 2:
                cout<<"\nCaracter especifico a buscar: ";cin>>buscar;
                search(&cola,buscar);
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

void push(Cola *queue, char dato){
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

void search(Cola *cola,char dato){
    int cont=0;
    bool status = false;

    while(!empty(cola)){
        if(cola->frente->elemento == dato){
            cout<<"\nElemento encontrado en la posicion "<<cont<<endl;
            status = true;
            cout<<"\nVaciando cola....\n";
            while(!empty(cola)){
                pop(cola);
            }
            break;
        }
    }

    if(status == false){
        cout<<"\nElemento no encontrado, verifique la cola: \n";
        ShowQueue(cola);
    }
}