#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main(){
    stack<char>FraseInvertida;
    string frase;

    cout<<"Digite una frase: ";getline(cin,frase);

    for(int i=0;i<frase.length();i++){
        FraseInvertida.push(frase[i]);
    }

    
    cout<<"Frase Invertida: \n";
    for(int i=0;i<frase.length();i++){
        cout<<FraseInvertida.top();
        FraseInvertida.pop();
    }

    return 0;
}