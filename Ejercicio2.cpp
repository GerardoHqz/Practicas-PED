#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *BT;

BT crearNodo(int valor) {
    BT hijo = new Nodo;
    hijo->dato = valor;
    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void insertarNodo(BT arbol, int valor) {
    BT temp = arbol;
    if(temp == NULL) {
        temp = crearNodo(valor);
    }
    while(temp) {
        if(temp->izq == NULL && temp->der == NULL) {
            cout << "El nodo actual no tiene hijos, se puede insertar a la izquierda o a la derecha" << endl;
            bool submenu = true;
            while(submenu){
                cout << "\n" << "Ingrese donde desea insertar el nodo" << endl;
                cout << "1. Rama izquierda" << endl;
                cout << "2. Rama derecha" << endl;
                int opcion;
                cout << "Ingrese la opción del menú" << endl;
                cin >> opcion;
                switch (opcion) {
                    case 1:
                        temp->izq = crearNodo(valor);
                        submenu = false;
                        break;
                    case 2:
                        temp->der = crearNodo(valor);
                        submenu = false;
                        break;
                    default:
                        cout << "Esta no es una opción válida del menú" << endl;
                        break;
                }
            }
        }else if(temp->izq != NULL) {
            
        }
        
    }
}

void preOrder(BT arbol) {
    if(arbol != NULL) {
        cout << arbol->dato << " ";
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(BT arbol) {
    if(arbol != NULL) {
        inOrder(arbol->izq);
        cout << arbol->dato << " ";
        inOrder(arbol->der);
    }
}

void postOrder(BT arbol) {
    if(arbol != NULL) {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        cout << arbol->dato << endl;
    }
}

int main() {
    BT arbol;
    int valor;
    cout << "***** INICIO DEL PROGRAMA *****" << endl;
    cout << "Ingrese la raíz del árbol binario: " << endl;
    cin >> valor;
    arbol = crearNodo(valor);
    bool menu = true, submenu = true;
    int opcion, opcionSub;
    while(menu) {
        cout << "***** ARBOL BINARIO *****" << endl;
        cout << "1. Insertar un nodo al árbol" << endl;
        cout << "2. Mostrar árbol binario" << endl;
        cout << "3. Verificar si es un BST o no" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Ingrese el valor del nodo que desea insertar: ";
            cin >> valor;
            insertarNodo(arbol, valor);
            break;
        case 2:
            while(submenu) {
                cout << "*** Mostrar árbol binario ***" << endl;
                cout << "1. Mostrar PreOrder" << endl;
                cout << "2. Mostrar InOrder" << endl;
                cout << "3. Mostrar PostOrder" << endl;
                cout << "4. Regresar al menú principal" << endl;
                cout << "\n" << "Ingrese la opción del menú que desea ejecturar" << endl;
                cin >> opcionSub;
                switch (opcionSub) {
                    case 1:
                        preOrder(arbol);
                        break;
                    case 2:
                        inOrder(arbol);
                        break;
                    case 3:
                        postOrder(arbol);
                        break;
                    case 4:
                        cout << "Regresando al menú principal" << endl;
                        submenu = false;
                        break;
                    default:
                        break;
                }
            }
            submenu = true;
            break;
        case 3:
            cout << "Aún no hay funcionalidad" << endl;
            break;
        case 4:
            cout << "Saliendo del programa" << endl;
            menu = false;
            break;
        default:
            cout << "Esta no es una opción válida del menú" << endl;
            break;
        }
    }
}
