#include <iostream>

using namespace std;

float mediana(int*,int);

int main(){
    int  n,A[n];
    cout<<"De cuantos numeros quiere su arreglo: ";cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Digite un numero: ";cin>>A[i];
    }
    int *p = A;
    mediana(p,n);

    return 0;
}
float mediana(int *p,int n){
float mediana=0;
   for (int i=0;i<n;i++){
       if(n%2 != 0){
           mediana = p[i/2];
       } 
       else{   
           mediana = p[i/2] + p[(i/2)+1];
           mediana = mediana/2;
       }
   }
   cout<<"La mediana es: "<<mediana;
}