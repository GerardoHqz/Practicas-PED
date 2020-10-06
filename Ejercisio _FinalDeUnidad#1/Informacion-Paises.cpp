#include <iostream>
#include <string>
#include <string.h>

using namespace std;

struct Paises{
    string nombre;
    string capital;
    float habitantes;
    float promedio;
}Informacion[5];

void Continente(Paises *);
void Habitantes(Paises *);
void Proemdio(Paises *);

int main()
{
    Paises Informacion[5];
    string nombre,capital;
    float habitantes=0,promedio=0;
    int cont=0;

    for(int i=0;i<5;i++){
        cout<<"Pais "<<i+1<<endl;
        cout<<"Nombre del pais: "; getline(cin, Informacion[i].nombre);
        cout<<"Nombre de capital: "; getline(cin, Informacion[i].capital);
        cout<<"Numero de habitantes: "; cin>>Informacion[i].habitantes;
        cout<<"Promedio de edades: "; cin>>Informacion[i].promedio;
        cout<<endl;
        cin.ignore();
    }
    Continente(Informacion);
    Habitantes(Informacion);
    Proemdio(Informacion);

    return 0;
}

void Continente(Paises *Informacion){
    float suma = 0;
    for(int i=0; i<5; i++){
        suma += Informacion -> habitantes;
        Informacion++;
    }
    cout<<"El continente tiene una poblacion de  "<<suma<<" habitantes.\n";
}

void Habitantes(Paises *Informacion){
    float mayor = 0;
    string n;
    for(int i=0; i<5; i++){
        if(Informacion->habitantes > mayor){
            mayor = Informacion->habitantes;
            n = Informacion->nombre;
        }
        else{
            Informacion++;
        }
    }
    cout<<"El pais con mas habitantes es "<<n<<" con "<<mayor<<" de habitantes.\n";
}

void Proemdio(Paises *Informacion){
    float promedio = 0;
    for(int i=0; i<5; i++){
        promedio = Informacion -> habitantes + promedio;
        Informacion++;
    }
    promedio = promedio / 5;
    cout<<"El continente tiene una poblacion promedio de  "<<promedio<<" años.\n";
}