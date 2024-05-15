#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Referência é uma segunda forma se você acessar uma variável que já existe.
// Não existe referência vazia.

// Exemplos de referência como retorno, parâmetro e criação de referência.

// Protótipo da função para trocar dois inteiros.
void troca(int&, int&);

// Função que retorna uma referência para um elemento em um vetor.
int& trocaElemento(int, int[]);

int main()
{
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl; 
    cout << "Valor do inteiro: " << iValor << ". Endereço do inteiro: " << &iValor << endl;
    cout << "==========================" << endl;
    
    // int& irefValor declarada mas não inicializada
    int& irefValor = iValor;
    string& strrefNome = strNome; 
    
    cout << "Valor da Ref. String: " << strrefNome << ". Endereço da Ref. String: " << &strrefNome << endl; 
    // tem mesmo endereço que a variável original
    cout << "Valor do Ref. inteiro: " << irefValor << ". Endereço do Ref. inteiro: " << &irefValor << endl;
    cout << "==========================" << endl;
    
    strrefNome = "C. Camacho"; // muda também a variável original
    irefValor = iValorFuturo; // só atribui o valor, Referênciacontinua apontando para ivalor mas com outro dado armazenado
    // REFERÊNCIAS NÃO SÃO RESETÁVEIS
    
    cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl; 
    cout << "Valor do inteiro: " << iValor << ". Endereço do inteiro: " << &iValor << endl;
    cout << "==========================" << endl;
    
    int iNum1 = 7;
    int iNum2 = 42;
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    troca(iNum1, iNum2);
    
    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;
    
    cout << "==========================" << endl;
    
    int arriVetor[5] = {0, 7, 13, 42, 666};
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] =" << arriVetor[i] << endl;
    }
    
    cout << "==========================" << endl;
    
    // Para isso funcionar tem que retornar uma referência 
    trocaElemento(3, arriVetor) = 111;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] =" << arriVetor[i] << endl;
    }
    
    
    
    return 0;
}

void troca(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
 }
 
int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}


// é tipo quando vc quer tirar a ultima coluna e colocar inplace = true

// se eu tiver a referenciado e somar com 3 esse a, na memoria de a, agora vai ter a+3 
