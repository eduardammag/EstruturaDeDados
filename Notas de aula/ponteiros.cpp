#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int square(int*);
int somaVetor(const int[], const size_t);

int main()
{
    int* ptrInt = nullptr; // pode usar NULL ou =0
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço do PTR: " << &ptrInt << endl;
    cout << "=========================" << endl;
    
    int iNumMagico = 42;
    cout << "Endereço de iNumMagico: " << &iNumMagico << "\n" <<  endl;
    
    ptrInt = &iNumMagico;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço do PTR: " << &ptrInt << endl;
    cout << "Conteúdo de iNumMagico: " << *ptrInt << endl;
    cout << "=========================" << endl;
    
    int iNumSagrado = 7;
    cout << "Endereço de iNumSagrado: " << &iNumSagrado << "\n" <<  endl;
    
    ptrInt = &iNumSagrado;
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço do PTR: " << &ptrInt << endl;
    cout << "Conteúdo de iNumSagrado: " << *ptrInt << endl;
    cout << "=========================" << endl;
    
    int iNum1 = 42;
    int iNum2 = 666;
    
    int* const ptrNum1 = &iNum1;
    // ptrNum1 = &iNum2; da erropois o ponteiro é constante
    // Altera o apontado
    *ptrNum1 = 7; // isso pode pois a contante é o ponteiro e não a variável que ele aponta, o ponteiro não pode mudar o lugar que ele aponta
    // a variável iNum1 não passa a ser constante mas o ponteiro que foi construido como se fosse constante então ele não vai permitir mudar de valor através do ponteiro
    // ele passa a tratar a iNum1 como constate mas não altera
    
    // Ponteiro para interio constante
    const int* ptrNum2 = &iNum1;
    ptrNum2 = &iNum2; // o constante agr aé a variável apontada
    // ele passa a tratar o iNum2 como constante também, mesmo ela originalmente não é uma constante
    
    // *ptrNum2 = 7; da erro pois a variável é constante, não pode mudar o dado armazenado
    
    // Ponteiro para constante para inteiro constante
    const int* const ptrNum3 = &iNum1;
    // ptrNum3 = &iNum2;
    // =========================================================================
    
    cout << "Quadrado: " << square(&iNum1) << endl;
    
    
    cout << "=========================" << endl;
    
    
    //int arriValores[3] = {0,1,2};
    
    // cout << "somaVetor: " << somaVetor(arriValores, 3) << endl;
    
    
    cout << "=========================" << endl;
    
    
    int arriValores[5] = {0, 7, 13, 42, 666};
    cout << "Endereço de [0]: " << arriValores << endl;
    
    int* ptrArrayValores1 = arriValores;
    cout << "PTR1: " << ptrArrayValores1 << endl;
    
    int* ptrArrayValores2 = &arriValores[0];
    cout << "PTR2: " << ptrArrayValores2 << endl;
    
    cout << "=========================" << endl;
    
    cout << "Valor de ptrArrayValores1[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[0]: " << ptrArrayValores1 << endl;
    
    // anda para o próximo elemento
    ptrArrayValores1++;
    cout << "Valor de ptrArrayValores1[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[1]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1+=2;
    cout << "Valor de ptrArrayValores1[3]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[3]: " << ptrArrayValores1 << endl;
    
    ptrArrayValores1-=2;
    cout << "Valor de ptrArrayValores1[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[1]: " << ptrArrayValores1 << endl;
    
    cout << "Subtração de Ponteiros: " << ptrArrayValores1 - ptrArrayValores2 << endl;
    
    
    return 0;
}

int square(int* ptrNum)
{
    return *ptrNum * *ptrNum;
}

int somaVetor(const int* valores, const size_t tamVetor)
{
    return -1;
}
