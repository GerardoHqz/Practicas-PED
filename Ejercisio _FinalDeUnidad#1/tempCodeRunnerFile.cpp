#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Paises{
    string nombre;
    string capital;
    float habitantes;
    int promedio;
}Informacion[5];

void Continente(Paises *);

int main()
{
    Paises Informacion[5];
    string nombre,capital;
    float habitantes=0;
    int promedio=0,cont=0;

    for(int i=0;i<5;i++){
        cin.ignore();
        cout<<"Nombre del pais: "; getline(cin, Informacion[i].nombre);
        cout<<"Nombre de capital: "; getline(cin, Informacion[i].capital);
        cout<<"Numero de habitantes: "; cin>>Informacion[i].habitantes;
        cout<<"Promedio de edades: "; cin>>Informacion[i].promedio;
    }
    Continente(Informacion);

    return 0;
}
void Continente(Paises *Informacion){
    float mayor = 0;
    for(int i=0; i<5; i++){
        if(Informacion[i].habitantes > mayor){
            mayor = Informacion[i].habitantes;
        }
    }
    cout<<"El pais con mas poblacion es "<<Informacion->habitantes;
}