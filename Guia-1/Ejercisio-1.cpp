#include <iostream>

using namespace std;

int main()
{
   int n=25,*puntero;
   cout<<"Numero "<<n<<" en el sistema\n";
   *puntero=n;
   cout<<"Porque que numero desea cambiar el numero: "; cin>>*puntero;
   cout<<"Nuevo numero: "<<*puntero;

    return 0;
}

