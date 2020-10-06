#include <iostream>

using namespace std;

void Ventas(int *);

int main(){

    int FIL=2,COL=5,matriz[FIL][COL];
    cout<<"PROGRAMA PARA SALIR BIEN CON KAREN\n";
    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            cout<<"Unidades vendidas la semana "<<i+1<<" dia "<<j+1<<": ";
            cin>>matriz[i][j];
        }
        cout<<endl<<endl;
    }
    Ventas(*matriz);

    return 0;
}
void Ventas(int *matriz){
    int suma=0,filas=2,colum=5,mayor=0,posx=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<colum;j++){
            suma = suma + *(matriz+i*colum+j);
            if(suma > mayor){
                mayor=suma;
                posx=i+1;
            }
        }
        cout<<"La semana "<<i+1<<" se vendieron: "<<suma<<" unidades\n";
        suma = 0;
    }
    
    cout<<"La semana que mas vendio fue la "<<posx<<" con "<<mayor<<" unidades";
}