#include <iostream>
#include <string>

using namespace std;

struct Estudiantes{
    string nombre;
    string apellido;
    string estado = "Indefinido";
    float notas [];
};

void pedir_datos();
float NotasyPromedio(int);
string Mayor(float);
Estudiantes Alumno1;


int main(){
    int n;
    pedir_datos();
    cout<<"Cuntas notas registara: ";cin>>n;
    float promedio = NotasyPromedio(n);
    string estado = Mayor(promedio);

    cout<<"DATOS DEL ESTUDIANTE.\n";
    cout<<"Nombre: "<<Alumno1.nombre<<endl;
    cout<<"Apellido: "<<Alumno1.apellido<<endl;
    cout<<"Estado: "<<estado<<endl;
    cout<<"Promedio: "<<promedio<<endl;




    return 0;
}

void pedir_datos(){
    cout<<"Nombres del estudiante: "; getline(cin,Alumno1.nombre);
    cout<<"Apellidos del estudiante: "; getline(cin,Alumno1.apellido);
}

float NotasyPromedio(int n){
    float promedio=0,suma=0;
    for(int i=0;i<n;i++){
        cout<<"Digita la nota "<<i+1<<": "; cin>>Alumno1.notas[i];
        suma += Alumno1.notas[i];
    }
    promedio = suma / n;

    return promedio;
}

string Mayor(float promedio){
    if(promedio > 6){
        return "Aprobado";
    }
    else{
        return "Reprobado";
    }
}