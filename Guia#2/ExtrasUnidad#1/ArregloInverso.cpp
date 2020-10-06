#include <iostream>
using namespace std;

int main (){
    int n;
    cout<<"Digite la longitud del arreglo: ";
    cin>>n;
    int arreglo[n];
    for (int i = 0; i < n; i++){
        cout<<i+1<<" Digite un numero: ";
        cin>>arreglo[i];
    }

    cout<<"Arreglo inverso: \n";
    for(int i=0; i<n;i++){
        cout<<arreglo[n-i-1]<<endl;
    }

    return 0;
}