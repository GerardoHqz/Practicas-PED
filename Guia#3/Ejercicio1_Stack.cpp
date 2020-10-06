#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int>);

int main(){
    stack<int>Pila;

    int opc = 0,dato;
    bool band = true;

    cout<<"***MENU***\n";
    cout<<"1.Agregar dato\n";
    cout<<"2.Sacar dato\n";
    cout<<"3.Salir\n";

    do{
        cout<<endl<<"\nElija una opcion: ";cin>>opc;
        cout<<endl;
        switch (opc){
        case 1: 
            cout<<"Digite un numero: ";cin>>dato;
            Pila.push(dato);
            cout<<"Pila Actual: ";
            if(!Pila.empty()){
                stack<int>clone = Pila;
                for(int i=0;i<Pila.size();i++){
                    cout<<clone.top()<<"->";
                    clone.pop();
                }
            }
            
            break;

        case 2:
            cout<<"Sacando el numero: "<<Pila.top()<<endl;
            Pila.pop();
            cout<<"Pila Actual: ";
            if(!Pila.empty()){
                stack<int>clone = Pila;
                for(int i=0;i<Pila.size();i++){
                    cout<<clone.top()<<"->";
                    clone.pop();
                }
            }
            else{
                cout<<"La pila esta vacia\n";
            }
            break;

        case 3:
            cout<<"Fin del programa";    
            band = false;
            default:
            break;
        }

    }while(band == true);

    return 0;
}

void showstack(stack<int>pila){
    stack<int>clone = pila;
    while(!clone.empty()){
        cout<<clone.top()<<" ";
        clone.pop();
    }
}