#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    string apellido;
    int pago;
};

void paypal(queue<Persona>);

int main(){
    Persona person;
    queue<Persona>Cola;
    int opcion;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar cliente\n";
        cout<<"2.Cobrar\n";
        cout<<"3.Salir\n";
        cout<<"Que operacion dese: ";cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"\nNombre del cliente: ";getline(cin,person.nombre);
                cout<<"Apellido del cliente: ";getline(cin,person.apellido);
                cout<<"Pago del cliente: "; cin>>person.pago;
                Cola.push(person);
                system("pause");
                break;
            case 2:
                paypal(Cola);
                system("pause");
                break;
            case 3:
                cout<<"\nFin del programa";
                status = false;
                break;
            default:
                cout<<"\nOpcion no valida\n";
                break;    

        }
    }while(status);

    return 0;
}

void paypal(queue<Persona>cola){
    bool status = true;
    int pagos = 0,cont1=0;
    cout<<"\nCobrando...\n";
    while(!cola.empty()){
        cont1++;
        pagos += cola.front().pago;
        cola.pop();
    }
    cout<<"Se ha cobrado un total de: $"<<pagos<<" a "<<cont1<<" clientes."<<endl;
}