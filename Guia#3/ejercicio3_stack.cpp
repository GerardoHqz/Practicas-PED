#include <iostream>
#include <stack>

using namespace std;

void sum(stack<int>);

int main(){
    stack<int>pila;
    stack<int>Par;
    stack<int>Impar;
    bool status = true;
    int opcion = 0, dato = 0;

    cout<<"PROGAMA DE SUMAS DE NUMEROS PARES E IMPARES\n";
    cout<<"Digite numeros positivos cuando ya no quiera seguir presione cualquier tecla\n";
    
    do{
        cout<<"\n Digite un numero: ";cin>>dato;
        pila.push(dato);

    }while(dato != 0);

    sum(pila);

    return 0;
}

void sum(stack<int>pila){
    stack<int>clone = pila;
    int par = 0, Impar = 0;
    while(!clone.empty()){
        if(clone.top()% 2 == 0){
            par = par + clone.top();
            clone.pop();
        }
        else{
            Impar = Impar + clone.top();
            clone.pop();
        }
    }

    cout<<"La suma de los numeros pares es: "<<par<<endl;
    cout<<"La suma de los numeros impares es: "<<Impar;

}