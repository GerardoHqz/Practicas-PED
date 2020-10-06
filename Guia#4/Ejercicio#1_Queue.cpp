#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void ShowQueue (queue<int>);

int main(){
    queue<int>Cola;
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
                cout<<"\nIngrese un dato: ";cin>>dato;
                Cola.push(dato);
                cout<<"Pila actual: ";
                ShowQueue(Cola);
                system("pause");
                break;
            case 2:
                cout<<"\nSacando un dato...\n";
                Cola.pop();
                ShowQueue(Cola);
                system("pause");
                break;
            case 3:
                cout<<"\nMostrando cola\n";
                ShowQueue(Cola);
                system("pause");
                break;
            case 4:
                cout<<"Fin del programa";
                status = false ;   
                break;
            default:
                cout<<"\nOpcion no valida\n";
                break;                
        }

    }while(status);

    return 0;
}

void ShowQueue (queue<int>cola){
    queue<int>clone = cola;
    while(!clone.empty()){
        if(clone.empty()){
            cout<<"\nLa cola esta vacia\n";
        }
        else{
            cout<<clone.front()<<" ";
            clone.pop();
        }
    }
    cout<<endl;
}
