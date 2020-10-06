#include <iostream>
#include <string>

using namespace std;

struct Estudiante{
  string nombre;
  string apellido;
  float *notas;
  float promedio;
};

void Promedio(Estudiante *);
void Mayor(Estudiante*);

int n,notas;
int main()
{
  cout<<"Registro Estudiantil\n";
  cout<<"Cuantos alumnos registrara: ";cin>>n;
  cout<<"Cuantas notas tienen los alumnos: ";cin>>notas;
  Estudiante Alumnos[n];
  Estudiante *ptr = Alumnos; 
  for(int i=0;i<n;i++){
    cin.ignore();
    cout<<"Alumno "<<i+1<<endl;
    cout<<"Nombre: "; getline(cin, ptr->nombre);
    cout<<"apellido: "; getline(cin, ptr->apellido);
    Promedio(ptr);
    ptr++;
  }
  cout<<"Datos del Estudiante con mayor promedio\n";
  ptr = &Alumnos[0];
  Mayor(ptr);

  return 0;
}

void Promedio(Estudiante *Alumnos){
  float promedio=0;
  for(int i=0; i<notas; i++){
    cout<<"Digite nota "<<i+1<<": "; cin>>Alumnos->notas[i];
    promedio = promedio + Alumnos->notas[i];
  }
  promedio = promedio / notas;
  Alumnos->promedio = promedio;
}

void Mayor(Estudiante *Alumnos){
  int mayor=0;
  string nganador,aganador;
  for(int i=0; i<n; i++){
    if(Alumnos->promedio > mayor){
      mayor = Alumnos->promedio;
      nganador = Alumnos->nombre;
      aganador = Alumnos->apellido;
    }
    Alumnos++;
  }
  cout<<"Nombre: "<<nganador<<endl;
  cout<<"Apellido: "<<aganador<<endl;
  cout<<"Promedio: "<<mayor;
}