#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void busqueda(queue<char>,char);
void ShowQueue (queue<char>);

int main(){
    queue<char>Cola;
    char dato,elemento;
    int opcion;
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
                cout<<"Digite un caracter: ";cin>>dato;
                Cola.push(dato);
                system("pause");
                break;
            case 2:
                cout<<"Caracter a buscar: ";cin>>elemento;
                busqueda(Cola,elemento);
                system("Pause");
                break;
            case 3:
                cout<<"\nFin del programa";
                status = false;
                break;
            default:
                cout<<"\nOpcion no valida\n";        
        }
    }while(status);

    return 0;
}

void busqueda(queue<char>cola,char elemento){
    queue<char>clone = cola;
    int cont=1;
    bool status = false;

    while(!clone.empty()){
        if(clone.front() == elemento){
            cout<<"\nElemento encontrado en la posicion "<<cont<<"\n";
            clone.pop();
            status = true;
            cout<<"\nVaciando cola....\n";
            while(!cola.empty()){
                cola.pop();
            }
            break;
        }
        else{
            cont++;
            clone.pop();
        }
    }

    if(status == false){
        cout<<"\nElemento no encontrado,verifique la cola: \n";
        ShowQueue(cola);
    }
}

void ShowQueue (queue<char>cola){
    queue<char>clone = cola;
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