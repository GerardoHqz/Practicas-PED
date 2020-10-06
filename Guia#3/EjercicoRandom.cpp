#include <iostream>
#include <string>

using namespace std;

struct nodo{
    string brand;
    string colour;
    int costo;
    nodo *siguiente;
};
typedef nodo *Pilas;

void inicializar(Pilas *);
bool Empty(Pilas *);
void push(Pilas *,string,string,int);
void pop(Pilas *);
void mostrar(Pilas *,string,string);



int main(){
    Pilas stack;
    string marca,color;
    inicializar(&stack);

    push(&stack,"Polo","Amarillo",25);
    push(&stack,"Polo","blanca",35);
    push(&stack,"Adidas","negra",15);
    push(&stack,"Puma","roja",12);
    push(&stack,"Lacoste","verde",40);

    cout<<"Ingrese la marca de la camisa que desea buscar: "; getline(cin,marca);
    cout<<"Ingrese el color de la camisa: ";getline(cin,color);

    mostrar(&stack,marca,color);



  return 0;
}

void inicializar(Pilas *stack){
    *stack = NULL;
}

bool Empty(Pilas *stack){
    return *stack == NULL;
}

void push(Pilas *stack,string marca,string color,int n){
    nodo *AuxNodo = new nodo();
    AuxNodo ->costo = n;
    AuxNodo ->brand = marca;
    AuxNodo->colour = color;
    AuxNodo->siguiente = *stack;
    *stack = AuxNodo;
}

void pop(Pilas *stack){
    if(!Empty(stack)){
        nodo *aux = *stack;
        *stack = (*stack)->siguiente;
        delete aux;
    }
    else{
        return;
    }
}

void mostrar(Pilas *stack,string marca,string color){
    nodo *clone = *stack;
    bool isEmpty = false,band = false;
    while(!isEmpty){
        if(!Empty(&clone)){
            if((clone->brand == marca) && (clone->colour == color)){
                cout<<"Datos de la prenda: \n";
                cout<<"Marca: "<<clone->brand<<endl;
                cout<<"Color: "<<clone->colour<<endl;
                cout<<"Precio: "<<clone->costo<<endl;
                band = true;
                break;
            }
            clone = clone->siguiente;
        }
        else{
            isEmpty = true;
        }
    }
    if(band == false){
        cout<<"Prenda de ropa no encontrada, pruebe respetando las mayusculas\n";
    }
}
