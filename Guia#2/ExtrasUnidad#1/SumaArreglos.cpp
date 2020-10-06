#include <iostream>

using namespace std;

int main(){
    int A[]={1,1,1,1,1,1}, B[]={2,2,2,2,2,2}, C[12],aux[12];

    for(int i=0;i<5;i++){
        C[i] = A[i];
    }
    for(int i=0;i<5;i++){
        C[i+5] = B[i];
    }
    
    for(int i=0;i<10;i++){
        cout<<C[i]<<" ";
    }

    return 0;
}