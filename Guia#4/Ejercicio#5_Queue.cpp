#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string>

using namespace std;

struct Alumnos{
    string nombre;
    string apellido;
    float nota;
};

void search(queue<Alumnos>,string);

int main(){
    queue<Alumnos>cola;
    Alumnos alumnos;
    string nombre;
    int opcion;
    bool status = true;

    do{
        system("cls");
        cout<<"***MENU***\n";
        cout<<"1.Ingresar datos de alumno\n";
        cout<<"2.Buscar alumno en especifico\n";
        cout<<"3.Salir\n";
        cout<<"Elija una opcion: ";cin>>opcion;

        switch(opcion){
            case 1:
            cin.ignore();
                cout<<"Digite nombre del alumno: ";getline(cin,alumnos.nombre);
                cout<<"Digite apellido del alumno: ";getline(cin,alumnos.apellido);
                cout<<"Digite la nota del alumno: ";cin>>alumnos.nota;
                system("pause");
                break;
            case 2:
                cin.ignore();
                cout<<"Nombre del alumno a buscar: ";getline(cin,nombre);
                search(cola,nombre);
                system("pause");
                break;
            case 3:
                cout<<"\nFin del programa\n";
                status = false;
                system("pause");    
                break;
            default:
                cout<<"\nOpcion no valida\n";
                system("pause");
                break;    
        }
    }while(status);

    return 0;
}

void search(queue<Alumnos>cola,string nombre){
    queue<Alumnos>clone = cola;
    bool status = false;
    while(!clone.empty()){
        if(clone.empty()){
            cout<<"\nLa cola de alumnos esta vacia\n";
        }
        else{
            if(clone.front().nombre == nombre){
                cout<<"\nEl estudiante si existe\n";
                cout<<"Nombre: "<<clone.front().nombre<<endl;
                cout<<"Apellido: "<<clone.front().apellido<<endl;
                cout<<"Nota: "<<clone.front().nota<<endl;
                clone.pop();
                status = true;
                break;
            }
            else{
                clone.pop();
            }
        }
    }
    if(status == false){
        cout<<"\nAlumno no encontrado\n";
    }
    cout<<endl;

}
