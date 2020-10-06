#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int>);
void invert(stack<int>);


int main(){
    stack<int>pila;
    bool status = true;
    int dato;

    cout<<"POGRAMA QUE INVIERTA PILAS NUMERICAS\n";
    cout<<"Cuando desee parar presione 0 o culquier caracter\n";

    do{

        cout<<"Digite un numero: ";cin>>dato;
        if(dato == 0){
            status = false;
        }
        pila.push(dato);

    }while(status);

    cout<<"Pila Recibida: \n";
    showstack(pila);
    cout<<endl;

    cout<<"Pila invertida: \n"; 
    invert(pila);  
 
    return 0;
}

void showstack(stack<int>pila){
    stack<int>clone = pila;
    while(!clone.empty()){
        cout<<clone.top()<<" ";
        clone.pop();
    }
}

void invert(stack<int>pila){
    stack<int>clone;
    int dato = 0;
    while(!pila.empty()){
        dato = pila.top();
        clone.push(dato);
        pila.pop();
    }

    while(!clone.empty()){
        cout<<clone.top()<<" ";
        clone.pop();
    }
}
