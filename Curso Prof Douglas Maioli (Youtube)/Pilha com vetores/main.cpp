#include <iostream>
#include "pilha.h"

using namespace std;

int main(){
    pilha pilha1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de pilha:\n";

    do {
        cout << "Digite 0 para parar o programa\n";
        cout << "Digite 1 para inserir um elemento\n";
        cout << "Digite 2 para remover um elemento\n";
        cout << "Digite 3 para imprimir a pilha\n";
        cout << "Digite 4 para verificar o tamanho da pilha\n";
        cout << "Digite 5 para verificar se a pilha esta cheia\n";
        cout << "Digite 6 para verificar se a pilha esta vazia\n";
        cin >> opcao; 

        if(opcao==1){
            cout << "Digite o elemento a ser inserido: \n";
            cin >> item;
            pilha1.inserir(item);
        } else if(opcao==2){
            cout << "Elemento Removido: " << item << endl;
            item = pilha1.remover();
        } else if(opcao==3){
            pilha1.imprimir();
        } else if(opcao==4){
            cout << "A pilha e composta de " << pilha1.qualtamanho() << " elemento(s)!\n";
        } else if(opcao==5){
            cout << "A pilha esta cheia? " << pilha1.estacheia() << endl;
        } else if(opcao==6){
            cout << "A pilha esta vazia?" <<  pilha1.estavazia() << endl;
        }
    }while(opcao !=0);

    cout << "Programa encerrado!";
    
    return 0;
}