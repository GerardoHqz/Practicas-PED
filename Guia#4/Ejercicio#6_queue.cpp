#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

void ShowQueue(queue<int>);

int main(){
    queue<int>cola;
    queue<int>par;
    queue<int>impar;
    int opcion,num,dato=0;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar entero.\n";
        cout<<"2.Verificar numeros.\n";
        cout<<"3.Mostrar cola de pares.\n";
        cout<<"4.Mostrar cola de impares\n";
        cout<<"5.Salir\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"\nDigite un entero: ";cin>>num;
                cola.push(num);
                system("pause");
                break;

            case 2:
            cout<<"\nVerificando y seprando por par e impar\n";
                while(!cola.empty()){
                    if(cola.front()%2 == 0){
                        dato = cola.front();
                        cola.pop();
                        par.push(dato);
                    }
                    else{
                        dato = cola.front();
                        impar.push(dato);
                        cola.pop();
                    }
                }
                system("pause");
                break;

            case 3:
                cout<<"\nMostrando cola de pares: ";
                ShowQueue(par);
                system("pause");
                break;

            case 4:
                cout<<"\nMostrando cola de impares: ";
                ShowQueue(impar);
                system("pause");
                break;

            case 5:
                cout<<"\nFin del programa.\n";
                system("pause");
                status = false;
                break;

            default:
                cout<<"opcion no valida\n";
                system("pause");
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
