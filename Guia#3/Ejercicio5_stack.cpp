#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct books{
    string titulo;
    int numpages;
};

void Push(stack<books>&,string,int);
void CantPages(stack<books>&,string);

int main(){
    stack<books>Paginas;
    string title;

    Push(Paginas,"Libro 1",250);
    Push(Paginas,"Libro 2",350);
    Push(Paginas,"Libro 3",450);
    Push(Paginas,"Libro 4",550);
    Push(Paginas,"Libro 5",650);
    
    cout<<"Digite el titulo del libro: "; getline(cin,title);
    CantPages(Paginas,title);

    return 0;
}

void Push(stack<books>&Paginas,string title,int numpag){
    books Libros;
    Libros.numpages = numpag;
    Libros.titulo = title;
    Paginas.push(Libros);
}

void CantPages(stack<books>&Paginas,string title){
    while(!Paginas.empty()){
        if(Paginas.top().titulo == title){
            cout<<"El libro tiene "<<Paginas.top().numpages<<" paginas";
            break; 
        }
        else{
            Paginas.pop();
        }
    }
}