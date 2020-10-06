#include <iostream>

using namespace std;

int MCD(int,int);

int main(){
    int mayor,menor;
    cout << "\n CALCUlDORA DEL MCD " <<endl;
    cout<<"Digite el numero mayor: ";cin>>mayor;
    cout<<"Digite el numero menor: ";cin>>menor;
    cout<<"El MCD de "<<mayor<<" y "<<menor<<" es: "<<MCD(mayor,menor);

    return 0;
}

int MCD(int mayor,int menor){
    int mcd = mayor%menor;

    if(mcd == 0){
        return menor;
    }
    else{
        mayor = menor;
        menor = mcd;
        return MCD(menor,mcd);
    }
}