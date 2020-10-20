#include <iostream>
#include <string>

using namespace std;

struct Persona{
    int carnet;
    string nombre;
    string apellido;
    int edad;
    int telefono;
    string email;
};

// Funciones propias de las personas ----------------

Persona solicitarDato(){
    Persona p;
    
    //---Solicitar ISBN, Titulo y Autor---
    cout <<"Carnet: "; cin >> p.carnet,cin.ignore();
    cout <<"Nombre: "; getline(cin, p.nombre);
    cout <<"Apellido: "; getline(cin, p.apellido);
    cout<<"Edad: "; cin>>p.edad,cin.ignore();
    cout<<"Telefono: "; cin>>p.telefono;
    cout<<"Correo: "; getline(cin,p.email),cin.ignore();
    
    //---Devolver libro ya poblado---
    return p;
}

void mostrarDato(Persona p){
    cout<<"\nCarnet: "<<p.carnet;
    cout<<"\nNombre: "<<p.nombre;
    cout<<"\nApellido: "<<p.apellido;
    cout<<"\nEdad: "<<p.edad;
    cout<<"\nTelefono: "<<p.telefono;
    cout<<"\nCorreo: "<<p.email;
    cout<<endl;
}

bool comparar(Persona a, Persona b){
    return (a.carnet == b.carnet) && (a.nombre==b.nombre) &&
        (a.apellido==b.apellido) && (a.edad==b.edad) && 
        (a.telefono==b.telefono) && (a.email==b.email);
}

// Definicion de la lista simplemente enlazada ----------------
typedef Persona T;
const T noValido = {-1,{""},{""},-1,-1,""};

struct Nodo{
    T dato;
    struct Nodo *sig;
};
Nodo *pInicio;

// Prototipos de funciones de la lista ----------------
void insertarInicio(T p);
void insertarFinal(T p);
void insertarDespuesDe(T p);
void insertarAntesDe(T p);
void agregar();
void mostrar();
void eliminar();
void buscar();
void vaciar(Nodo** nodoInicio);

// Programa principal ----------------
int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout <<"**MENU**";
        cout<<"\n1) Agregar Persona";
        cout<<"\n2) Eliminar una persona";
        cout<<"\n3) Actualizar datos de una persona";
        cout<<"\n4) Mostrar todas las personas";
        cout<<"\n5) Salir";
        cout<<"\nDigite una opcion: ";cin>>opcion;

        switch(opcion){
            case 1: agregar(); break;
            case 2: eliminar(); break;
            case 3: buscar(); break;
            case 5: continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);

    return 0;
}

// Implementacion de funciones de la lista ----------------

void insertarInicio(T p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(T p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void insertarDespuesDe(T p) {
    cout << "Dato de referencia: ";
    T ref = solicitarDato();
    
    Nodo *s = pInicio;
    
    while(s != NULL && !comparar(s->dato, ref))
        s = s->sig;
    if(s == NULL){
        cout << "Dato de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s->sig;
    
    s->sig = nuevo;
    cout << "Dato insertado con exito" << endl;
}

void insertarAntesDe(T p) {
    cout << "Dato de referencia: ";
    T ref = solicitarDato();
    
    Nodo *s = pInicio, *q = NULL;
    
    while(s != NULL && !comparar(s->dato, ref)){
        q = s;
        s = s->sig;
    }
    if(s == NULL){
        cout << "Dato de referencia NO existe" << endl;
        return;
    }
    
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = s;
    
    if(q == NULL)
        pInicio = nuevo;
    else
        q->sig = nuevo;
    cout << "Dato insertado con exito" << endl;
}

void agregar(){
    T p = solicitarDato();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n";
        cout << "\t2) Al final\n";
        cout << "\t3) Despues de\n";
        cout << "\t4) Antes de\n";
        cout << "\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p); continuar = false; break;
            case 2: insertarFinal(p); continuar = false; break;
            case 3: insertarDespuesDe(p); continuar = false; break;
            case 4: insertarAntesDe(p); continuar = false; break;
            default: cout << "Opcion erronea!" << endl; break;
        }
    }while(continuar);
}

void mostrar() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarDato(s->dato);
        s = s->sig;
    }
}

void eliminar(){
    cout << "Dato a eliminar: ";
    T ref = solicitarDato();
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && !comparar(p->dato, ref)){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "Dato a borrar NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Dato borrado!" << endl;
}

void buscar() {
    cout << "Dato a buscar: ";
    T ref = solicitarDato();
    
    Nodo *s = pInicio;

    while(s != NULL && !comparar(s->dato, ref))
        s = s->sig;
    
    //Si s!=NULL entonces el elemento SI se encuentra
    //Si s==NULL entonces el elemento NO se encuentra
    if(s != NULL)
        cout << "El dato SI se encuentra" << endl;
    else
        cout << "El dato NO se encuentra" << endl;
}

void vaciar(Nodo** nodoInicio){
    Nodo* current = *nodoInicio;
    Nodo* next;
    
    while(current != NULL){
        next = current->sig;
        delete(current);
        current = next;
    }
    *nodoInicio = NULL;
}