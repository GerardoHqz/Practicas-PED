#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int dato;
    nodo *izq;
    nodo *der;
};
typedef struct nodo *ABB;

ABB CrearNodo(int);
void AsignarNodo(ABB,int);
void PreOrder(ABB);
void InOrder(ABB);
void PostOrder(ABB);
int AlturArbol(ABB);
int CalcularNodos(ABB);
int SumaDeNodos(ABB);

int main(){
    ABB arbol;
    bool status = true,status2 = true;
    int opcion,opcion2,raiz,dato;

    do{
        system("cls");
        cout<<"\n*****MENU*****\n";
        cout << "1. Crear arbol\n";
        cout << "2. Ingresar nodo al arbol\n";
        cout << "3. Mostrar árbol\n";
        cout << "4. Mostrar la cantidad de niveles del árbol\n";
        cout << "5. Mostrar la cantidad de nodos del árbol\n";
        cout << "6. Mostrar la suma de los valores de todos los nodos del árbol\n";
        cout << "7. Salir del programa\n";
        cout << "Ingrese una opcion: "; cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"\nIngrese la riaz del nodo: "; cin>>raiz;
                CrearNodo(raiz);
                system("pause");
                break;
            case 2:
                cout<<"\nIngrese un dato: "; cin>>dato;
                AsignarNodo(arbol,dato);
                system("pause");
                break;
            case 3:
                do{
                    cout<<"\nFORMAS DE MOSTRAR EL ARBOL\n";
                    cout<<"1. Pre orden\n";
                    cout<<"2. In orden\n";
                    cout<<"3. Post Orden\n";
                    cout<<"4. Regresar\n";
                    cout<<"Elija una opcion: "; cin>>opcion2;

                    switch(opcion2){
                        case 1:
                            PreOrder(arbol);
                            cout<<endl;
                            break;
                        case 2:
                            InOrder(arbol);
                            cout<<endl;
                            break;
                        case 3:
                            PostOrder(arbol);
                            cout<<endl;
                            break;
                        case 4:
                            status2 = false;
                            break;
                        default:
                            cout<<"\nOpcion no valida\n";
                            break;
                    }
                }while(status2); 
                break;
            case 4:
                cout<<"\nEl arbol tiene una altura de "<<AlturArbol(arbol)<<" nodos";
                system("pause");
                break;
            case 5:
                cout<<"\nEl arbol tiene: "<<CalcularNodos<<" nodos";
                system("pause");
                break;
            case 6:
                cout<<"La suma de los datos de los nodos es: "<<SumaDeNodos(arbol)<<" nodos";
                system("pause");
                break;
            case 7:
                status = false;
                cout<<"\nFin del programa\n";
                system("pause");
                break;      
            default:
                cout<<"\nOpcion no valida\n";
                break;
        }
    }while(status);


    return 0;
}

ABB CrearNodo(int valor){
    ABB hijo = new nodo();
    hijo->dato = valor;
    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void AsignarNodo(ABB arbol,int valor){
    ABB temporal = arbol;

    while(true){
        if(temporal->dato == valor){
            cout<<"\nEl dato ya existe\n";
            break;
        }
        else if(temporal->dato > valor){
            if(temporal->izq == NULL){
                temporal->izq = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->izq;
                break;
            }
        }
        else{
            if(temporal->der == NULL){
                temporal->der = CrearNodo(valor);
                break;
            }
            else{
                temporal = temporal->der;
            }
        }
    }
}

void PreOrder(ABB arbol){
    if(arbol != NULL){
        cout<< arbol->dato << " ";
        PreOrder(arbol->izq);
        PreOrder(arbol->der);
    }
}

void InOrder(ABB arbol){
    if(arbol != NULL){
        InOrder(arbol->izq);
        cout<<arbol->dato<<" ";
        InOrder(arbol->der);
    }
}

void PostOrder(ABB arbol){
    if(arbol != NULL){
        PostOrder(arbol->izq);
        PostOrder(arbol->der);
        cout<<arbol->dato<<"";
    }
}

int AlturArbol(ABB arbol){
    int alturaIzq = 0, alturaDer = 0;
    if(arbol == NULL){
        return 0;
    }
    else{
        alturaIzq = AlturArbol(arbol->izq);
        alturaDer = AlturArbol(arbol->der);
        
        int altura = max(alturaIzq,alturaDer)+1;

        return altura;
    }
}

int CalcularNodos(ABB arbol){
    if(arbol != NULL){
        int nodos = 1;

        if(arbol->izq != NULL){
            nodos += CalcularNodos(arbol->izq);
        }
        if(arbol->der != NULL){
            nodos += CalcularNodos(arbol->der);
        }
        return nodos;
    }
    else{
        return 0;
    }
}

int SumaDeNodos(ABB arbol){
    if(arbol != NULL){
        int suma = arbol->dato;

        if(arbol->izq != NULL){
            suma += SumaDeNodos(arbol->izq);
        }
        if(arbol->der != NULL){
            suma += SumaDeNodos(arbol->der);
        }
        return suma;
    }
    else{
        return 0;
    }
}
