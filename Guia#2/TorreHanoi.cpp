#include <iostream>

using namespace std; 

void Hanoi(int,int,int,int);

int main(){
    int n,inicio=1,torreaux=2,fin=3;
    cout<<"Cuantos discos tendra la torre de hanoi: ";cin>>n;
    Hanoi(n,inicio,torreaux,fin);

    return 0;
}

void Hanoi(int n, int inicio, int aux, int fin){

  if (n == 1){
    cout << "El disco " << n << " se mueve de " << inicio << " -> " << fin << endl; 
    return;
  }

  Hanoi(n - 1, inicio, fin, aux);
  cout << "El disco " << n << " se mueve de " << inicio << " -> " << fin << endl;
  Hanoi(n - 1, aux, inicio, fin);

}