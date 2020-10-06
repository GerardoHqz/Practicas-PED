#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

struct Pares{
    int num1;
    int num2;
};

void ShowQueue (queue<Pares>);

int main(){
    queue<Pares>cola;
    Pares numeritos;
    int opcion;
    bool status = true;
    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar pares de numeros\n";
        cout<<"2.Mostrar pares\n";
        cout<<"3.Salir\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Digite el primer numero: ";cin>>numeritos.num1;
                cout<<"Digite el segundo numero: ";cin>>numeritos.num2;
                cola.push(numeritos);
                system("pause");
                break;
            case 2:
                ShowQueue(cola);
                system("pause");
                break;    
            case 3:
                cout<<"\nFin del programa.";
                status = false;
                break;
            default:
                cout<<"\nOpcion no valda\n";
                break;        
        }
    }while(status);




    return 0;
}

void ShowQueue (queue<Pares>cola){
    queue<Pares>clone = cola;
    while(!clone.empty()){
        if(clone.empty()){
            cout<<"\nLa cola esta vacia\n";
        }
        else{
            cout<<"("<<clone.front().num1<<","<<clone.front().num2<<")";
            clone.pop();
        }
    }
    cout<<endl;
}