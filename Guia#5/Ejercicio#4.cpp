#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stdlib.h>

using namespace std;

//Definiendo la lista para los productos
struct Productos{
  string producto;
  float precio;
  Productos *next;
};
//Definiendo la estructura de la lista simple
struct Lista{
  Productos *inicio;
};

//Definiendo la cola de clientes
struct Clientes{
  string nombre;
  int dui;
  Lista *compras;
};

void initialize(Lista*);
bool empty(Lista*);
void insertar(Lista*,string,float);
void borrar(Lista*,string);
void cobrar(queue<Clientes>);

int main(){
  queue<Clientes>ListaCompras;
  Clientes clientes;
  Productos productos;
  Lista LaLista;
  initialize(&LaLista);

  string nombre,borrar;
  bool status = true,status2 = true;
  int opcion,opcion2;
  float precio, total = 0;

  do{
      system("cls");
      cout<<"***MENU**";
      cout<<"\n1) Agregar un Cliente";
      cout<<"\n2) Cobrar clientes";
      cout<<"\n3) Salir\n";
      cout<<"\nElija una opcion: "; cin>>opcion;

      switch(opcion){
        case 1:
          cin.ignore();
          cout<<"Nombre del cliente: "; getline(cin,clientes.nombre);
          cout<<"DUI del cliente: "; cin>>clientes.dui;
          while(status2){
            cout<<"\n***Lista de Productos***";
            cout<<"\n1.Agregar producto";
            cout<<"\n2.Eliminar producto";
            cout<<"\n2.Finalizar lista";
            cout<<"Elija una opcion: "; cin>>opcion2;
            
            switch(opcion2){
              case 1:
                cin.ignore();
                cout<<"Nombre del producto: "; getline(cin,nombre);
                cout<<"Precio: "; cin>>precio;
                insertar(&LaLista,nombre,precio);
                break;
              case 2:
                cout<<"\nNombre del producto: "; getline(cin,nombre);
                borrar(&LaLista,nombre);
                break;
              case 3:
                cout<<"\nFin de la lista de compras\n";
                status2 = false;
                break;
            }
          }
          system("pause");
          break;

        case 2:
          cobrar(ListaCompras);
          system("pause");
          break;

        case 3:
          cout<<"\nSalir del programa";
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

void initialize(Lista *listaCompras){
  listaCompras->inicio = NULL;
}

bool empty(Lista *listaCompras){
  return(listaCompras->inicio == NULL) ? true : false;
}

void insertar(Lista *listaCompras, string nombre, float precio){
  Productos *nuevo = new Productos();

  nuevo->producto = nombre;
  nuevo->precio = precio;
  nuevo->next = NULL;

  if(listaCompras->inicio == NULL){
    listaCompras->inicio = nuevo;
  }
  else{
    Productos *p = listaCompras->inicio;
    Productos *q = NULL;
    while(p){
      q = p;
      p = p->next;
    }
    q->next = nuevo;
  }
}

void borrar(Lista *listaCompras,string borrar){
  bool encontrado = true;

  if(empty(listaCompras)){
    cout<<"\nNo hay productos en la lista";
    return;    
  }
  else{
    Productos *p = listaCompras->inicio;
    Productos *q = NULL;
    while(p != NULL && p->producto != borrar){
      q = p;
      p = p->next;
    }
    
    if(p == NULL){
      cout<<"\nNo se ha encontrado el producto\n";
      return;
    }
    if(q == NULL){
      listaCompras->inicio = p->next;
    }
    else{
      q->next= q->next;
    }
    delete (p);
    cout<<"\nProducto eliminado!";
    cout<<endl;
  }
}

void cobrar(queue<Clientes>clientes){
  bool status = true;
  int pagos = 0,total = 0;
  cout<<"\nCobrando....\n";
  if(clientes.empty()){
    cout<<"\nNo hay clientes en la cola.";
    return;
  }
  else{
    while(!clientes.empty()){
      Clientes persona = clientes.front();
      cout<<"\nFactura de "<<persona.nombre;
      Productos *aux = persona.compras->inicio;
      while(aux){
        pagos += aux->precio;
        cout<<"* "<<aux->producto<<"   $"<<aux->precio<<endl;
        aux = aux->next;
      }
      total += pagos;
      clientes.pop();
    }
    cout<<"\nSe ha cobrado $"<<total<<" a los clientes"<<endl;
  }
}  