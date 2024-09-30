/*
    Desafio 6:
    Crie um Algoritmo em C++, em que o usuário informa os gastos com alimentação de 5 famílias,
    calcula a média de gastos e diz de cada família se seu gasto é abaixo da média, acima da média ou na média.

    Desafio 7:
    Crie um Algoritmo em C++, em que o usuário informa a dimensão de uma matriz, 
    e os elementos de duas matrizes (ambas com a mesma dimensão) e o Algoritmo mostra a soma entre estas duas matrizes.

    Desafio 8:
    Crie um Algoritmo em C++, em que o usuário informa o tamanho de um vetor, e seus elementos. 
    O Algoritmo deve imprimir este vetor e, logo após, perguntar ao usuário se ele quer imprimir outro vetor. 
    Utilize o delete após a impressão do vetor.

    Desafio 9:
    Crie um Algoritmo em C++ utilizando apenas ponteiros, em que o usuário informa a idade de duas pessoas, 
    e o Algoritmo informa a média destas duas idades.

    Desafio 10:
    Crie um Algoritmo em C++, que tenha uma função que recebe dois ponteiros e troca o valor de referência entre os dois.
*/

#include <iostream>
using namespace std;

// Função para o Desafio 6
void desafio6() {
    const int numFamilias = 5;
    double gastos[numFamilias], media = 0;

    // Coleta dos gastos das famílias
    cout << "Desafio 6: Informe os gastos com alimentacao de 5 familias:\n";
    for (int i = 0; i < numFamilias; i++) {
        cout << "Gastos da familia " << i + 1 << ": ";
        cin >> gastos[i];
        media += gastos[i];
    }

    // Calcula a média dos gastos
    media /= numFamilias;
    cout << "Media de gastos: " << media << endl;

    // Compara os gastos de cada família com a média
    for (int i = 0; i < numFamilias; i++) {
        cout << "Familia " << i + 1 << ": ";
        if (gastos[i] < media)
            cout << "abaixo da media." << endl;
        else if (gastos[i] > media)
            cout << "acima da media." << endl;
        else
            cout << "na media." << endl;
    }
}

// Função para o Desafio 7
void desafio7() {
    int linhas, colunas;
    cout << "\nDesafio 7: Informe a dimensao das matrizes (linhas e colunas): ";
    cin >> linhas >> colunas;

    // Alocação dinâmica das matrizes
    int** matriz1 = new int*[linhas];
    int** matriz2 = new int*[linhas];
    int** soma = new int*[linhas];

    for (int i = 0; i < linhas; i++) {
        matriz1[i] = new int[colunas];
        matriz2[i] = new int[colunas];
        soma[i] = new int[colunas];
    }

    // Coleta dos elementos das duas matrizes
    cout << "Informe os elementos da primeira matriz:\n";
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> matriz1[i][j];
        }
    }

    cout << "Informe os elementos da segunda matriz:\n";
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> matriz2[i][j];
        }
    }

    // Calcula a soma das duas matrizes
    cout << "Soma das matrizes:\n";
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
            cout << soma[i][j] << " ";
        }
        cout << endl;
    }

    // Libera a memória alocada
    for (int i = 0; i < linhas; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] soma[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] soma;
}

// Função para o Desafio 8
void desafio8() {
    int tamanho;
    char opcao;

    do {
        cout << "\nDesafio 8: Informe o tamanho do vetor: ";
        cin >> tamanho;

        // Alocação dinâmica do vetor
        int* vetor = new int[tamanho];

        // Coleta dos elementos do vetor
        cout << "Informe os elementos do vetor:\n";
        for (int i = 0; i < tamanho; i++) {
            cin >> vetor[i];
        }

        // Imprime o vetor
        cout << "Vetor informado: ";
        for (int i = 0; i < tamanho; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;

        // Libera a memória alocada
        delete[] vetor;

        // Pergunta se o usuário quer imprimir outro vetor
        cout << "Deseja imprimir outro vetor? (s/n): ";
        cin >> opcao;
    } while (opcao == 's' || opcao == 'S');
}

// Função para o Desafio 9
void desafio9() {
    int idade1, idade2;
    int* pIdade1 = &idade1;
    int* pIdade2 = &idade2;

    cout << "\nDesafio 9: Informe a idade de duas pessoas:\n";
    cout << "Idade da primeira pessoa: ";
    cin >> *pIdade1;
    cout << "Idade da segunda pessoa: ";
    cin >> *pIdade2;

    // Calcula e exibe a média das idades
    double media = (*pIdade1 + *pIdade2) / 2.0;
    cout << "Media das idades: " << media << endl;
}

// Função auxiliar para o Desafio 10 - Troca de valores entre dois ponteiros
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para o Desafio 10
void desafio10() {
    int x, y;
    cout << "\nDesafio 10: Informe dois valores para troca:\n";
    cout << "Primeiro valor: ";
    cin >> x;
    cout << "Segundo valor: ";
    cin >> y;

    // Exibe os valores antes da troca
    cout << "Antes da troca: x = " << x << ", y = " << y << endl;

    // Chama a função de troca
    troca(&x, &y);

    // Exibe os valores após a troca
    cout << "Depois da troca: x = " << x << ", y = " << y << endl;
}

// Função principal
int main() {
    desafio6();
    desafio7();
    desafio8();
    desafio9();
    desafio10();
    return 0;
}
