#include<iostream>
using namespace std;

bool Encontrar_Dato(int [],int, int , int );
int busquedaBinaria(int [],int, int, int);

int main(){
	int arreglo[]={1,3,4,5,17,18,31,33};
	int dato,low=0,high=8;
	
	cout<<"elemento a buscar: ";
	cin>>dato;
	
	if(Encontrar_Dato(arreglo,dato,0,9)==true){
		cout<<"elemento encontrado en la posicion "<<busquedaBinariaRecursiva(arreglo,dato,low,high)+1;
	}else{
		cout<<"elemento no encontrado";
	}

	return 0;
}

bool Encontrar_Dato(int arreglo[],int dato, int inf, int sup){
	int medio;
	medio=(inf+sup)/2;
	
	if(dato==arreglo[medio]){
		return true;
	}
	if(inf==sup){
		return false;
	}
	else{
		if(dato<arreglo[medio]){
			return Encontrar_Dato(arreglo,dato,inf,medio);
		}
		else{
			return Encontrar_Dato(arreglo,dato,medio+1,sup);
		}
	}
}
int busquedaBinariaRecursiva(int arreglo[], int dato, int low, int high){
    if (low > high){
        return-1;
    } 

    int indiceDeLaMitad = (low + high) / 2;

    int valorQueEstaEnElMedio = arreglo[indiceDeLaMitad];
    if (dato == valorQueEstaEnElMedio){
        return indiceDeLaMitad;
    }
    
    if (dato < valorQueEstaEnElMedio){
        // Entonces está hacia la izquierda
        high = indiceDeLaMitad - 1;
    }else{
        // Está hacia la derecha
        low = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(arreglo, dato, low, high);
}