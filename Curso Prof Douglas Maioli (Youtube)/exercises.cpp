/*
Atividade_ED_25_03
Utilizando protótipos, notação Húngara e referências reescreva uma função matemática (pode ser abs ou pow):
- Uma função qualquer da biblioteca math
- Fatorial iterativo
- Progressão Aritmética
- Fibonacci Iterativo
- Cálculo do número de dígitos de um inteiro
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// QUESTÃO 1

float calcularRaizQuadrada(float& num);

int main() {
    float fNumero;
    cout << "Digite um número para calcular a raiz quadrada: ";
    cin >> fNumero;
    
    if (fNumero < 0) {
        cout << "Não é possível calcular a raiz quadrada de um número negativo." << endl;
    } else {
        cout << "A raiz quadrada de " << fNumero << " é aproximadamente " << calcularRaizQuadrada(fNumero) << endl;
    }
    
    return 0;
}

// Função para calcular a raiz quadrada
float calcularRaizQuadrada(float& fNum) {
    float fResultado = fNum / 2; // Aproximação inicial
    float fTemp;

    do {
        fTemp = fResultado;
        fResultado = (fTemp + (fNum / fTemp)) / 2;
    } while ((fTemp - fResultado) != 0);

    return fResultado;
}

///////////////////////////////////////////////////////////////////////////////////////////////


//QUESTÃO 2

int ifatorialIterativo(int inumero) {
  int iret = 1;
  while (inumero > 1) iret *= inumero--;
  return iret;
}

template <typename T>
void printVector(vector<T> &vec) {
  for (const auto &item : vec) {
    cout << item << ", ";
  }
  cout << endl;
}

int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printVector(vec);

  for (const auto &item : vec) {
    cout << ifatorialIterativo(item) << ", ";
  }
  cout << endl;

  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////


// QUESTÃO 3

int icalcularSomaPA(int iprimeiroTermo, int irazao, int iquantidade);

int main() {
    int iprimeiroTermo, irazao, iquantidade;

    cout << "Digite o primeiro termo da PA: ";
    cin >> iprimeiroTermo;

    cout << "Digite a razão da PA: ";
    cin >> irazao;

    cout << "Digite a quantidade de termos da PA: ";
    cin >> iquantidade;

    int iresultado = icalcularSomaPA(iprimeiroTermo, irazao, iquantidade);

    cout << "A soma dos " << iquantidade << " termos da PA é: " << iresultado << endl;

    return 0;
}

// Função para calcular a soma dos termos de uma PA
int icalcularSomaPA(int iprimeiroTermo, int irazao, int iquantidade) {
    int isoma = 0;
    int itermoAtual = iprimeiroTermo;

    for (int i = 0; i < iquantidade; i++) {
        isoma += itermoAtual;
        itermoAtual += irazao;
    }

    return isoma;
}

// Implementação da função com referências
int icalcularSomaPA(const int& iprimeiroTermo, const int& irazao, const int& iquantidade) {
    // Cálculo da soma da PA
    int soma = ((2 * iprimeiroTermo) + ((iquantidade - 1) * irazao)) * iquantidade / 2;
    return soma;
}

//////////////////////////////////////////////////////////////////////

//QUESTÃO 4

long int licalcularFibonacci(const int& n);

int main() {
    int iPosicao;
    
    // Sequência fibonacci: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55..
    cout << "Escolha a posição: ";
    cin >> iPosicao;
    cout << "Posição " << iPosicao << " da sequência de Fibonacci: " << licalcularFibonacci(iPosicao) << endl;

    return 0;
}

// Função para calcular o n-ésimo termo da sequência de Fibonacci
long int licalcularFibonacci(const int& n) {
    long int liTermoAnterior = 0, liTermoAtual = 1;

    if (n == 0) return liTermoAnterior;
    if (n == 1) return liTermoAtual;

    for (int i = 2; i <= n; i++) {
        long int liProximoTermo = liTermoAnterior + liTermoAtual;
        liTermoAnterior = liTermoAtual;
        liTermoAtual = liProximoTermo;
    }
    
    return liTermoAtual;
}

///////////////////////////////////////////////

QUESTÃO 5

// Protótipo da função com nome consistente
int calcularNumeroDigitos(const int& numero);

int main() {
    int iNumero;
    cout << "Digite um número inteiro: ";
    cin >> iNumero;

    int iNumDigitos = calcularNumeroDigitos(iNumero);
    cout << "O número de dígitos de " << iNumero << " é: " << iNumDigitos << endl;

    return 0;
}

// Função para calcular o número de dígitos de um inteiro
int calcularNumeroDigitos(const int& numero) {
    
    if (numero == 0) {
        return 1;
    }
    
    int iContador = 0;
    
    int iNum = numero;
    if (iNum < 0) {
        iNum = -iNum;
    }
    
    while (iNum != 0) {
        iContador++;
        iNum /= 10; 
    }
    
    return iContador;
}



