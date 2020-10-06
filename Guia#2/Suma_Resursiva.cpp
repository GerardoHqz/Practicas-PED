#include <iostream>

using namespace std;

int suma(int n);

int main(){
    int n;
    cout<<"Hasta que numero desea sumar: ";cin>>n;
    cout<<"La suma es: "<<suma(n);

    return 0;
}

int suma(int n){
    if(n==1){
        return 1;
    }
    else{
        return(n+suma(n-1));
    }
}