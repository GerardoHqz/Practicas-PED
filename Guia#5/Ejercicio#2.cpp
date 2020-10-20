#include <iostream>
#include <stdlib.h>

using namespace std;

struct Numero{
    int dato;
    Numero *next;
};

struct Lista{
  Numero *inicio;
};


void inicializar(Lista*);
bool empty(Lista*);
void insertarInicio(Lista*,int);
void mostrar(Lista*);
void mostrarPar(Lista*);
void mostrarImpar(Lista*);

int main(){
    Lista numeros;
    inicializar(&numeros);
    int opcion,opcion2,dato;
    bool status = true;

    do{
        system("cls");
        cout<<"*MENU*";
        cout<<"\n1.Ingresar elemento a la lista";
        cout<<"\n2.Mostrar todos los elementos";
        cout<<"\n3.Mostrar solo elemntos pares";
        cout<<"\n4.Mostrar solo elementos impares";
        cout<<"\n5.Salir\n";
        cout<<"\nElija una opcion: "; cin>>opcion;

        switch(opcion){
            case 1: 
                cout<<"\n1.Insertar al inicio";
                cout<<"\n2.Insertar al final";
                cout<<"\nSeleccion opcion: ";cin>>opcion2;
                switch(opcion2){
                    case 1:
                        cout<<"\nDigite un numero: "; cin>>dato;
                        insertarInicio(&numeros,dato);
                        system("pause");
                        break;
                    case 2: 
                        cout<<"\nDigite un numero: "; cin>>dato;
                        insertarFinal(&numeros,dato);
                        system("pause");
                        break;
                    default:
                        cout<<"\nOpcion no valida";
                        system("pause");
                        break;
                }
                
            case 2:
                cout<<"\nMostrnado lista numeros: ";
                mostrar(&numeros);
                system("pause");
                break;
            case 3:
                cout<<"\nMostrando lista de numeros pares: ";
                mostrarPar(&numeros);
                system("pause");
                break;
            case 4:
                cout<<"\nMostrando lista de numeros impares: ";
                mostrarImpar(&numeros);
                system("pause");
                break;
            case 5:
                cout<<"\nFin del programa";
                status = false;
                break;
            default:
                cout<<"\nOpcion no valida";
                system("pause");
                break;        
        }

    }while(status);

    return 0;
}

void inicializar(Lista *listaNumeros) {
    listaNumeros->inicio = NULL;
}

//Función que verfica si la lista está vacía
bool empty(Lista *listaNumeros) {
    return (listaNumeros->inicio == NULL) ? true : false;
}

void insertarInicio(Lista *listaNumeros,int dato) {
    //Reservando espacio necesario para un registro Estudiante
    Numero *nuevo = new Numero();

    //Asignando los valores a todos los parametros del registro
    nuevo->dato = dato;

    //Dado que este nuevo estudiante se va a insertar al inicio, su puntero siguiente debe igualarse al puntero inicio de la lista
    nuevo->next = listaNumeros->inicio;

    //Se modifica el puntero inicio de la lista al nuevo estudiante para tener la lista enlazada con el nuevo agregado al principio
    listaNumeros->inicio = nuevo;
}

void insertarFinal(Lista *listaNumeros,int dato) {
    //Reservando espacio necesario para un registro Estudiante
    Numero *nuevo = new Numero;

    //Asignando los valores a todos los parametros del registro
    nuevo->dato = dato;

    //Dado que este nuevo estudiante se va a insertar al final, su puntero siguiente debe estar vacío
    nuevo->next = NULL;

    //Verificamos si el puntero inicio de la lista contiene un elemento
    if(listaNumeros->inicio == NULL) {
        //Si no contiene nada, el nuevo estudiante se le asigna al inicio, y de igual manera se convierte en el final de la lista
        listaNumeros->inicio = nuevo;
    }else {
        //Crear un puntero estudiante auxiliar que almacene todo lo del puntero inicio de la lista
        Numero *p = listaNumeros->inicio;
        //Crear un puntero estudiante auxiliar que se inicializa como NULL
        Numero *q = NULL;
        //Recorremos la lista por medio del auxiliar p
        while(p) {
            //El puntero auxiliar q toma todo el contenido del puntero auxiliar p
            q = p;
            //Utilizamos el puntero p para movernos en la lista
            p = p->next;
        }
        //Una vez finalizado el recorrido de la lista, el contenido en q es el ultimo elemento existente en la lista
        //Por lo que asignamos el nuevo estudiante en el puntero sig de q
        q->next = nuevo;
    }
}

void mostrar(Lista *ListaNumeros){
    Numero *aux = ListaNumeros->inicio;

    if(empty(ListaNumeros)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux != NULL){
            cout << aux->dato << " -> ";
            aux = aux->next;
        }
    }
    cout<<endl;
}

void mostrarPar(Lista *ListaNumeros){
    Numero *aux = ListaNumeros->inicio;

    if(empty(ListaNumeros)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux != NULL){
            if(aux->dato%2 == 0){
                cout<<aux->dato<<"->";
                aux = aux->next;
            }
            else{
                aux = aux->next;
            }
        }
    }
    cout<<endl;
}

void mostrarImpar(Lista *ListaNumeros){
    Numero *aux = ListaNumeros->inicio;

    if(empty(ListaNumeros)){
        cout<<"\nLa lista esta vacia";
    }
    else{
        while(aux != NULL){
            if(aux->dato%2 == 0){
                aux = aux->next;
            }
            else{
                cout<<aux->dato<<"->";
                aux = aux->next;
            }
            
        }
    }
    cout<<endl;
}