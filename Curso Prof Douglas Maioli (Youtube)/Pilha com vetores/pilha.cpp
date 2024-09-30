#include <iostream>
#include "pilha.h"

using namespace std;

    pilha::pilha() //construtora
    {
        tamanho=0;
        estrutura = new TipoItem[max_itens];
    }


    pilha::~pilha() //destrutora
    {
        delete [] estrutura;
    }


    bool pilha::estacheia()
    {
        return (tamanho == max_itens);
    }


    bool pilha::estavazia()
    {
        return (tamanho == 0);
    }


    void pilha::inserir(TipoItem item) //push
    {
        if (estacheia()){
            cout << "A pilha esta cheia! \n";
            cout << "Nao podemos inserir este elemento! \n";
        } else {
            estrutura[tamanho] = item;
            tamanho++;
        }
    }



    TipoItem pilha::remover() //pop
    {
        if (estavazia()){
            cout << "A pilha esta vazia! \n";
            cout << "Não tem elemento a ser removido! \n";
        } else{
            tamanho--;
            return estrutura[tamanho -1];
        }

    }




    void pilha::imprimir()
    {
        cout << "Pilha: [";
        for (int i=0 ; i<tamanho ; i++){
            cout << estrutura[i] << " ";
        }
        cout << "]\n";

    }



    int pilha::qualtamanho() //comprimento
    {
        return tamanho;

    }