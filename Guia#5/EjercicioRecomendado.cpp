#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Articulos{
    string nombre;
    float precio;
    float peso;
    bool caducidad;
};

vector<Articulos>bodega;

bool compNombre(Articulos a, Articulos b){
    return a.nombre < b.nombre;
}
bool compPeso(Articulos a, Articulos b){
    return a.peso < b.peso;
}
bool compPrecio(Articulos a, Articulos b){
    return a.precio < b.precio;
}

void agregar();
void buscar();
void eliminar();
void ordenar();
void caducidad();
void gramos();
void precio();
void mostrar();

int main(){
    int opcion;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Agregar producto";
        cout<<"\n2.Buscar producto";
        cout<<"\n3.Eliminar producto";
        cout<<"\n4.Ordenar productos";
        cout<<"\n5.Productos con caducidad";
        cout<<"\n6.Prodcutos con mas de 300gr";
        cout<<"\n7.Prodcutos de mas $50";
        cout<<"\n8.Mostrar inventario";
        cout<<"\n9.Salir.";
        cout<<"\nElija una opcion: ";cin>>opcion;
        cin.ignore();

        switch(opcion){
            case 1:
                agregar();
                system("pause");
                break;
            case 2:
                buscar();
                system("pause");
                break;
            case 3:
                eliminar();
                system("pause");
                break; 
            case 4:
                ordenar();
                system("pause");
                break;
            case 5:
                caducidad();
                system("pause");
                break;
            case 6: 
                gramos();
                system("pause");
                break;
            case 7:
                precio();
                system("pause");
                break;
            case 8:
                mostrar();
                system("pause");
                break;
            case 9:
                cout<<"\nFin del programa";
                status = false;
                break;           
        }
    }while(status);

    return 0;
}

void agregar(){
    Articulos productos;
    string opcion;
    cout<<"\nNombre del prodcuto: ";getline(cin,productos.nombre);
    cout<<"Precio del producto: ";cin>>productos.precio,cin.ignore();
    cout<<"Peso del producto: ";cin>>productos.peso,cin.ignore();
    cout<<"Tiene caducidad: "; getline(cin,opcion);
    if(opcion == "si" || opcion == "Si"){
        productos.caducidad = true;
    }
    else{
        productos.caducidad = false;
    }
    bodega.insert(bodega.end(),productos);
    cout<<"\nProducto agregado!\n";
}

void buscar(){
    string nombre;
    bool existe = false;
    cout<<"Producto a buscar: "; getline(cin,nombre);
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].nombre == nombre){
            existe = true;
            break;
        }
    }

    if(existe){
        cout<<"\nProducto encontrado!";
    }
    else{
        cout<<"\nProducto no encontrado!";
    }
}

void eliminar(){
    string unNombre;
    cout << "Nombre del articulo que buscar: ";
    getline(cin, unNombre);
    
    for(auto iter = bodega.begin(); iter != bodega.end(); ++iter){
        if(iter->nombre == unNombre){
            iter = bodega.erase(iter);
            cout << "Articulo eliminado exitosamente.\n";
            break;
        }
    }
}

void ordenar(){
    int opcion = 0;
    cout << "Criterio de ordenamiento:\n";
    cout << "1) Alfabetico\n";
    cout << "2) Peso\n3)Precio\n";
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    
    if(opcion == 1)
        sort(bodega.begin(), bodega.end(), compNombre);
    else if(opcion == 2)
        sort(bodega.begin(), bodega.end(), compPeso);
    else if(opcion == 3)
        sort(bodega.begin(), bodega.end(), compPrecio);
        
    cout << "Bodega ordenada exitosamente\n";
}

void caducidad(){
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].caducidad == true){
            cout<<"\nProducto: "<<bodega[i].nombre;
            cout<<"\nPeso: "<<bodega[i].peso;
            cout<<"\nPrecio: "<<bodega[i].precio;
            cout<<endl;
        }
    }
}

void gramos(){
    cout<<"\nProductos que pesan mas de 300 gramos: ";
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].peso >= 300){
            cout<<"\nProducto: "<<bodega[i].nombre;
            cout<<"\nPeso: "<<bodega[i].peso;
            cout<<"\nPrecio: "<<bodega[i].precio;
            cout<<endl;
        }
    }
}

void precio(){
    cout<<"\nProductos que valen mas de $50 dolares: ";
    for (int i = 0; i < bodega.size(); i++) {
        if(bodega[i].precio >= 50){
            cout<<"\nProducto: "<<bodega[i].nombre;
            cout<<"\nPeso: "<<bodega[i].peso;
            cout<<"\nPrecio: "<<bodega[i].precio;
            cout<<endl;
        }
    }
}

void mostrar(){
    cout<<"\nMostrando lista de productos: ";
    for(int i=0;i<bodega.size();i++){
        cout<<"\nProducto: "<<bodega[i].nombre;
        cout<<"\nPeso: "<<bodega[i].peso;
        cout<<"\nPrecio: "<<bodega[i].precio;
        cout<<"\nCaduce: "<<bodega[i].caducidad;
        cout<<endl;
    }
}