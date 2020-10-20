#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definiendo estructura Producto que va a contener el vector
struct Producto {
    string nombre;
    string tipo;
    float precio;
    struct Producto *sig;
};

//Definiendo estructura ListaSimple que contiene puntero de tipo Producto
struct ListaSimple {
    Producto *inicio;
};
typedef struct ListaSimple Lista;

//Definiendo estructura Cliente que va a contener la Cola
struct Cliente {
    string nombre;
    int dui;
    Lista productos;
};

//Función que inicializa la lista
void inicializar(Lista *listaProductos) {
    listaProductos->inicio = NULL;
}

//Función que verfica si la lista está vacía
bool estaVacia(Lista *listaProductos) {
    return (listaProductos->inicio == NULL) ? true : false;
}

//Función para insertar un nuevo producto al inicio de la lista
void insertarInicio(Lista *listaProductos, string nombre, string tipo, float precio) {
    //Reservando espacio necesario para un registro Producto
    Producto *nuevo = new Producto;

    //Asignando los valores a todos los parametros del registro
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->precio = precio;

    //Dado que este nuevo producto se va a insertar al inicio, su puntero siguiente debe igualarse al puntero inicio de la lista
    nuevo->sig = listaProductos->inicio;

    //Se modifica el puntero inicio de la lista al nuevo producto para tener la lista enlazada con el nuevo agregado al principio
    listaProductos->inicio = nuevo;
}

void insertarFinal(Lista *listaProductos, string nombre, string tipo, float precio) {
    //Reservando espacio necesario para un registro Producto
    Producto *nuevo = new Producto;

    //Asignando los valores a todos los parametros del registro
    nuevo->nombre = nombre;
    nuevo->tipo = tipo;
    nuevo->precio = precio;

    //Dado que este nuevo producto se va a insertar al final, su puntero siguiente debe estar vacío
    nuevo->sig = NULL;

    //Verificamos si el puntero inicio de la lista contiene un elemento
    if(listaProductos->inicio == NULL) {
        //Si no contiene nada, el nuevo producto se le asigna al inicio, y de igual manera se convierte en el final de la lista
        listaProductos->inicio = nuevo;
    }else {
        //Crear un puntero producto auxiliar que almacene todo lo del puntero inicio de la lista
        Producto *p = listaProductos->inicio;
        //Crear un puntero producto auxiliar que se inicializa como NULL
        Producto *q = NULL;
        //Recorremos la lista por medio del auxiliar p
        while(p) {
            //El puntero auxiliar q toma todo el contenido del puntero auxiliar p
            q = p;
            //Utilizamos el puntero p para movernos en la lista
            p = p->sig;
        }
        //Una vez finalizado el recorrido de la lista, el contenido en q es el ultimo elemento existente en la lista
        //Por lo que asignamos el nuevo producto en el puntero sig de q
        q->sig = nuevo;
    }
}

//Función para borrar un producto por su nombre
void borrarPorNombre(Lista *listaProductos, string nombre) {
    //Bandera booleana para verificar si se ha encontrado el producto
    bool encontrado = false;

    //Verificación de que la lista de productos esté vacía o no
    if(estaVacia(listaProductos)) {
        cout << "No hay productos en la lista" << endl;
        return;
    }else {

        //Creación de un puntero producto auxiliar para recorrer la lista
        Producto *p = listaProductos->inicio;
        Producto *q = NULL;

        //Recorrer la lista por medio de un while, se detiene cuando el puntero p contiene el nombre deseado
        while(p != NULL && p->nombre != nombre) {
            q = p;
            p = p->sig;
        }

        if(p == NULL) {
            cout << "No se ha encontrado ningún producto" << endl;
            return;
        }

        //Verificación de los estados de los punteros luego del recorrido con el while
        if(q == NULL) {
            listaProductos->inicio = p->sig;
        }else {
            //Dado que q se encuentra un elemento atrás de p, y el elemento que se va a borrar es el que apunta p
            //q->sig debe saltarse el elemento que está referenciado en p y apuntar al siguiente de éste
            //Así se puede borrar el elemento sin desenlazar la lista
            q->sig = p->sig;
        }

        delete(p);

        cout << "Se ha borrado el producto deseado" << endl; 
    }
}

//Función para cobrarle a los clientes
float cobrar(queue<Cliente> *colaClientes, float pago) {
    //Verificación que haya clientes en la cola
    if(colaClientes->empty()) {
        cout << "No se ha realizado ningún cobro, no hab►1a clientes en la cola" << endl;
        return 0;
    }else {
        //Recorrer la cola por medio de un while, cuya condición sea que la cola NO esté vacía
        while(!colaClientes->empty()) {
            //Asignar el cliente que se encuentra al frente de la cola a la variable cliente
            Cliente cliente = colaClientes->front();

            cout << "Factura de " << cliente.nombre << "\t" << "\t" << "DUI: " << cliente.dui << endl;
            //Recorrer la lista de los productos del cliente actuales con un while

            //Se crea un producto auxiliar para recorrer la lista de productos del cliente actual
            Producto *aux = cliente.productos.inicio;
            while(aux) {
                pago += aux->precio;

                cout << aux->nombre << ": $" << aux->precio << endl;

                aux = aux->sig;
            }

            //Eliminar el cliente al frente de la cola porque ya fue atendido, y avanzar en la cola
            colaClientes->pop();
        }
        return pago;
    }
}


int main() {
    //Creando e inicializando la cola de clientes
    queue<Cliente> colaClientes;

    //Creando bandera booleana para iterar el while
    bool status = true;

    //Creando bandera booleana para iterar el segundo while
    bool status2 = true;

    //Menu por medio de while, verificando variable status por cada iteración
    while(status) {
        //Imprimiendo en consola las opciones del menú
        cout << "********** MENU **********" << endl;
        cout << "1. Ingresar un cliente a la cola" << endl;
        cout << "2. Cobrar a los clientes que hay en la cola" << endl;
        cout << "3. Salir del programa" << endl;

        //Creación de variable entera que servirá para ejecutar una opción del menú
        int option;

        //Pidiéndole al usuario que ingrese la opción por medio de consola
        cout << "\n" << "Ingrese la opción del menú que desea ejecutar: ";
        cin >> option;
        cin.ignore();

        //Creación de variable tipo cliente
        Cliente cliente;

        //Creando e inicializando una nueva lista de productos
        Lista listaProductos;
        inicializar(&listaProductos);

        //Creando variable string para llenar los datos de un producto
        string nombre, tipo;

        //Creando variable float para llenar los datos de un producto
        float precio;

        //Creación de variable entera para la sumatoria de los precios de los productos
        int totalPagado = 0;

        //Case para verificar la opción ingresada
        switch (option){
            case 1:
                //Caso en el que se añade un libro a la pila previamente creada

                //Pidiéndole al usuario que ingrese los datos del clientes
                cout << "Ingrese el nombre del cliente" << endl;
                getline(cin, cliente.nombre);

                cout << "Ingrese el dui del cliente" << endl;
                cin >> cliente.dui;

                //Volvemos a declarar true status2 para que se ejecute el menú secundario por cada iteración
                status2 = true;

                //While ocupado para la inserción o eliminación de productos en la lista del cliente
                while(status2) {
                    //Menú secundario para ingresar productos o eliminar
                    cout << "*** Productos del cliente ***" << endl;
                    cout << "1. Agregar nuevo producto" << endl;
                    cout << "2. Eliminar producto por nombre" << endl;
                    cout << "3. Finalizar listado de productos" << endl;

                    //Declaración de variable para ingresar opción en el segundo menú
                    int option2;

                    //Pidiéndole al usuario que ingrese la opción a ejecutar del menú
                    cout << "Ingrese la opción que desea ejecutar" << endl;
                    cin >> option2;
                    cin.ignore();

                    switch(option2) {
                        case 1:
                            //Caso en el que se ingresa un nuevo producto

                            //Pidiéndole al usuario los datos para un producto
                            cout << "Ingrese el nombre del producto" << endl;
                            getline(cin, nombre);

                            cout << "Ingrese el tipo del producto" << endl;
                            getline(cin, tipo);

                            cout << "Ingrese el precio del producto" << endl;
                            cin >> precio;

                            //Agregando un producto a la lista
                            insertarFinal(&listaProductos, nombre, tipo, precio);
                            break;
                        case 2:
                            //Caso en el que se borra un producto por su nombre

                            //Pidiéndole al usuario el nombre del producto que desea borrar
                            cout << "Ingrese el nombre del producto que desea borrar" << endl;
                            getline(cin, nombre);

                            //Mandar a llamar a la función para borrar por el nombre
                            borrarPorNombre(&listaProductos, nombre);
                            break;
                        case 3:
                            status2 = false;
                            break;
                        default:
                            cout << "Opción no válida" << endl;
                            break;
                    }
                }
                
                //Agregando la lista de productos al cliente
                cliente.productos = listaProductos;

                //Agregando el cliente a la cola
                colaClientes.push(cliente);

                //Borrando la lista de productos, para reutilizarla para el siguiente cliente
                
                break;
            case 2:
                //Caso en el que se le cobra a los clientes que hay en cola

                totalPagado = cobrar(&colaClientes, 0);

                cout << "Se ha cobrado un total de $" << totalPagado << " a los clientes en cola" << endl;
                break;
            case 3:
                status = false;
                cout << "Fin del programa." << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }|
    }
    return 0;
}
