#include <iostream> // Biblioteca para entrada e saída padrão
#include <chrono> // Biblioteca para medição de tempo

using std::cout; // Utilizando o espaço de nomes std para cout
using std::cin; // Utilizando o espaço de nomes std para cin
using std::endl; // Utilizando o espaço de nomes std para endl
using std::string; // Utilizando o espaço de nomes std para string

using std::chrono::high_resolution_clock; 
using std::chrono::duration_cast; 
using std::chrono::nanoseconds; 

// Função para trocar o valor de duas variáveis inteiras por referência
void swapValue(int&, int&);

// Função para imprimir um array de inteiros
void printArray(int[], int);

// Função para ordenar um array de inteiros utilizando o algoritmo Bubble Sort
void bubblesort(int[], int);

// Função otimizada para ordenar um array de inteiros utilizando o algoritmo Bubble Sort
void optimizedBubblesort(int[], int);

int main()
{
    // Array de números de exemplo
    int arriNumbers_1[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    int iArraySize = 10; // Tamanho do array

    cout << "Array original: ";
    printArray(arriNumbers_1, iArraySize); // Imprime o array original

    // Inicia a contagem do tempo
    auto timeStart = high_resolution_clock::now();
    bubblesort(arriNumbers_1, iArraySize); // Ordena o array
    // Para a contagem do tempo
    auto timeStop = high_resolution_clock::now();

    cout << "Array ordenado: ";
    printArray(arriNumbers_1, iArraySize); // Imprime o array ordenado

    // Calcula o tempo utilizado e o imprime
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "==================" << endl;

    // Segundo conjunto de números de exemplo
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13, 137};
    iArraySize = 10; // Atualiza o tamanho do array

    cout << "Array original: ";
    printArray(arriNumbers_2, iArraySize); // Imprime o array original

    // Inicia a contagem do tempo
    timeStart = high_resolution_clock::now();
    optimizedBubblesort(arriNumbers_2, iArraySize); // Ordena o array de forma otimizada
    // Para a contagem do tempo
    timeStop = high_resolution_clock::now();

    cout << "Array ordenado: ";
    printArray(arriNumbers_2, iArraySize); // Imprime o array ordenado

    // Calcula o tempo utilizado e o imprime
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "==================" << endl;

    return 0;
}

// Função para trocar o valor de duas variáveis inteiras por referência
void swapValue(int& iValue_1, int& iValue_2)
{
    int iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}

// Função para imprimir um array de inteiros
void printArray(int arriNumbers[], int iLength)
{
    for (int i = 0; i < iLength; i++) cout << arriNumbers[i] << " "; // Itera sobre o array e imprime cada elemento
    cout << endl; // Imprime uma nova linha
}

// Função para ordenar um array de inteiros utilizando o algoritmo Bubble Sort
void bubblesort(int arriNumbers[], int iLength)
{
    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
        for (int iInnerLoop = 0; iInnerLoop < iLength - 1; iInnerLoop++)
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]); // Troca os elementos se estiverem fora de ordem
}

// Função otimizada para ordenar um array de inteiros utilizando o algoritmo Bubble Sort
void optimizedBubblesort(int arriNumbers[], int iLength)
{
    bool bUnordered = false; // Indica se o array está ordenado ou não

    for (int iOuterLoop = 0; iOuterLoop < iLength - 1; iOuterLoop++)
    {
        bUnordered = false;

        for (int iInnerLoop = 0; iInnerLoop < iLength - 1 - iOuterLoop; iInnerLoop++)
        {
            if (arriNumbers[iInnerLoop] > arriNumbers[iInnerLoop + 1])
            {
                swapValue(arriNumbers[iInnerLoop], arriNumbers[iInnerLoop + 1]); // Troca os elementos se estiverem fora de ordem
                bUnordered = true; // Define que houve uma troca, indicando que o array ainda não está completamente ordenado
            }
        }

        if (bUnordered == false) break; // Se não houve trocas, o array está ordenado e a iteração pode ser interrompida
    }
}
