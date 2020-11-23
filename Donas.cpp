#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


struct Producto{
    string nombre;
    float precio_unitario;

};

struct Pedido{
    string apellido;
    vector<Producto>lista_comida;
};

int main(){
    queue<Pedido>Donas;
    queue<Pedido>Platos;
    Pedido pedido;
    vector<Producto>lista;
    Producto producto;

    bool status = true,status2 = true,status3 = true;
    int opcion,opcion2,opcion3;
    float TotalCobros = 0;

    do{
        cout<<"\n*Caja Registradora*";
        cout<<"\n1) Atender pedidos de clientes";
        cout<<"\n2) Calcular ganancias por ventas de donas";
        cout<<"\n3) Calcular ganancias por venta de platos fuertes";
        cout<<"\n4) Salir\n";
        cout<<"\nElige una opcion: "; cin>>opcion;

        switch(opcion){
            case 1:
                cin.ignore();
                cout<<"Digite el apellido del cliente: "; getline(cin,pedido.apellido);
                do{
                    cout<<"\t*Ejecutar Pedido*\n";
                    cout<<"\t1) Ordenar Donas";
                    cout<<"\t2) Ordenar Plato Fuerte";
                    cout<<"\t3) Cobrar cola Donas";
                    cout<<"\t4) Cobrar cola Platos fuertes";
                    cout<<"\t5)Salir\n";
                    cout<<"\tElija una opcion: ";cin>>opcion2;
                    switch(opcion2){
                        case 1:
                            do{
                                cout<<"\n*MENU  DE  DONAS*";
                                cout<<"\n*Donas sencilla $1";    
                                cout<<"\n*Donas rellena de leche $1.25";
                                cout<<"\n*Donas especiales (moca,caramelo) $1.50";
                                cout<<"\n1) Ordenar";
                                cout<<"\n2) Fin y cobrar\n";
                                cout<<"\nDigite la opcion: "; cin>>opcion3;
                                switch(opcion3){
                                    case 1:
                                        cin.ignore();
                                        cout<<"\nDigite el nombre de la dona que quiere: "; getline(cin,producto.nombre);
                                        cout<<"Precio unitario: $"; cin>>producto.precio_unitario;
                                        lista.push_back(producto);
                                        Donas.push(pedido);
                                        break;
                                    case 2:
                                        cobrar();
                                        cout<<"\nTotal: $"<<TotalCobros;
                                        status3 = false;
                                        break;
                                    default:
                                        cout<<"\nOpcion no valida";
                                }
                            }while(status3);
                                
                        break;
                    }
                }while(status2);
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                status = false;
                break;

            default:
                cout<<"\nOpcion no valida";
                break;                
        }




    }while(status);

    return 0;
}

void cobrar(queue<Pedido>donas){
    float cobros = 0;
    while(!donas.empty()){
        cobros += donas.front().lista_comida.front().precio_unitario;
        donas.pop();
    }
    cout<<endl<<cobros;
}