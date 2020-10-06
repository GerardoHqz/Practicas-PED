#include <iostream>
#include <stack>

using namespace std;

void showstack(stack<int>);

int main(){
    stack<int>Par;
    stack<int>Impar;
    int n;
    cout<<"De que tamanio desea sus arreglos: ";cin>>n;
    int a[n],b[n],mult[n];

    cout<<"\nLlenando el arreglo 1.\n";
    for(int i=0;i<n;i++){
        cout<<"Digite el dato "<<i+1<<": ";cin>>a[i];
    }

    cout<<"\nLlenando el arreglo 2.\n";
    for(int i=0;i<n;i++){
        cout<<"Digite el dato "<<i+1<<": ";cin>>b[i];
    }

    cout<<"\nmultiplicando el arreglo 1 y 2.\n";
    for(int i=0;i<n;i++){
        mult[i] = a[i] * b[i];
    }

    for (int i=0; i<n; i++){
        if(mult[i] % 2 == 0){
            Par.push(mult[i]);
        }
        else{
            Impar.push(mult[i]);
        }
    }

    cout<<"\nPila con numeros pares: ";
    showstack(Par);

    cout<<"\nPila con numeros impares: ";
    showstack(Impar);

    return 0;
}
void showstack(stack<int>pila){
    stack<int>clone = pila;
    while(!clone.empty()){
        cout<<clone.top()<<" ";
        clone.pop();
    }
}