#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    int promedio;
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
void search(Cola*,string);


int main(){
    Cola queue;
    string nombre,Alumbuscar;
    int opcion,nota;
    bool status = true;
    initialize(&queue);

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar estudiantes\n";
        cout<<"2.Verificar estudiante presente\n";
        cout<<"3.Salir\n";
        cout<<"Elija opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nDigite el nombre del estudiante: ";getline(cin,nombre);
                cout<<"Digite el promedio del estudiante: ";cin>>nota;
                push(&queue,nombre,nota);
                system("pause");
                break;
            case 2:
                cout<<"\nAlumno a buscar:"; cin>>Alumbuscar;
                search(&queue,Alumbuscar);
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
    aux->promedio = paid;
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

void search(Cola *queue,string Alumbuscar){
    bool status = false;
    if(empty(queue)){
        cout<<"No hay clientes en la cola.\n";
        return;
    }
    else{
        while(!empty(queue)){
            if(queue->front->nombre == Alumbuscar){
                cout<<"\nEl alumno si existe!\n";
                cout<<"Nombre: "<<queue->front->nombre<<endl;
                cout<<"Promedio: "<<queue->front->promedio<<endl;
                status = true;
                pop(queue);
                break;
            }
            else{
                pop(queue);
            }
        }
    }
}