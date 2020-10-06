#include<iostream>

using namespace std;

void Llenar_Arreglo(int *,int);
void mostrar(int *, int );

int main(){

  int n;
  cout<<"De cuantos numeros quiere el arreglo: ";cin>>n;
  int arreglo[n];
  int *puntero = arreglo;
  Llenar_Arreglo(puntero,n);
  mostrar(puntero,n);

  return 0;
}
void Llenar_Arreglo(int *puntero,int n){
  if(n == 0){
    return;
  }
  else{
    cout<<"Digite un numero: ";cin>>*puntero;
    puntero++;
    Llenar_Arreglo(puntero,(n-1));
  }
}
void mostrar(int *puntero, int n){
  if(n == 0){
    return;
  }
  cout << *puntero<<" ";
  puntero ++;
  mostrar(puntero,n-1);
}
