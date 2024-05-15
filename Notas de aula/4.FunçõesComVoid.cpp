#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// função antes da main ou assinatura/protótipo da função antes e definição depois da main
// void é um vazio da linguagem, indica explicitamente que a função não retorna um valor específico, ela apenas executa alguma operação

void FrasePreferida()
{
    
// a função não tem parâmetro, nem retorno, ela é vazia 
// sai a frase no console, mas nada é guardado na memória
    
    cout << "Eu sou estudante de Ciência de Dados da FGV!" << endl;
}


void MontaFrase(char chArtigo, string strPalavra)
{
    
//o retorno é vazio    
    
    cout << "Eu admiro " << chArtigo << " " << strPalavra << "!" << endl;
}

void MontaFrasePadrão(char chArtigo = 'a', string strPalavra= "Eduarda Mesquita")
{
     cout << "Eu admiro " << chArtigo << " " << strPalavra << "!" << endl;
}

int potenciacao(int iBase, int iExpoente)
{
    return pow(iBase,iExpoente); 
    //pow= potenciacao
}


float modulo(float iValor)
{
    return fabs(iValor);
    //abs:  função para tirar módulo de int
    //fabs: função para tirar módulo de float
}


//Função para imprimir os elementos de um vetor de inteiros
void ImprimindoElementos(int arriNumeros[], int iTamanhoVetor)
{
  //Itera sobre o vetor e imprime cada elemento
  
  //for(condição de incialização do loop; condição de continuação do loop(enquanto for verdadeira, o loop continuará); operador de incremento)
    for (int i=0; i < iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl; 
        //Imprime o elemento atual seguido de uma quebra de linha
    }
    
}

// Definição a função TrocaNumeros 
void TrocaNumeros(int& a, int& b) {
    // Recebe 2 referências para inteiros a e b
    int temp = a;
    a = b;
    b = temp;
    //Utiliza uma variável temporária para armazenar o valor de a antes da troca, garantindo que o valor original não seja perdido.
    //Em seguida, atribui o valor de b a a e finalmente, atribui o valor temporário armazenado em temp a b. 
}


int main()
{
    
    FrasePreferida();
    MontaFrase('a', "Fernanda Vasconcelos");
    // '' p/ caracteres e " " para string
    
    //MontaFrase("a", 'Fernanda Vasconcelos'); ERRO
    //MontaFrase("a", "Fernanda Vasconcelos"); ERRO
    //MontaFrase('a', 'Fernanda Vasconcelos'); ERRO
    
    MontaFrasePadrão();
    MontaFrasePadrão('a', "minha mãe");
    MontaFrasePadrão('a', "Shakira");
    MontaFrasePadrão('a'); // funciona com um só argumento, é um argumento de posição (?)
    // MontaFrasePadrão("Paula Eduarda"); ERRO
    MontaFrasePadrão('a', "Mariana Fernandes");
    
    
    potenciacao(2,1); //calcula, mas não imprime, precisa do cout
    cout << "2 elevado a 3 é: " << potenciacao(2,3) << endl;
    cout << "5 elevado a 6 é: " << potenciacao(5,6) << endl;

    
    cout << "O módulo de 13 é: " << modulo(13) << endl;
    cout << "O módulo de -13 é: " << modulo(-13) << endl;
    cout << "O módulo de 13.7 é: " << modulo(13.7) << endl;
    cout << "O módulo de -13.7 é: " << modulo(13.7) << endl;


    int arriVetorTeste[7] = {1,7,13,42,56,678,987};
    int iTamanhoVetorTeste = sizeof(arriVetorTeste)/sizeof(arriVetorTeste[0]);
    ImprimindoElementos(arriVetorTeste, iTamanhoVetorTeste);

    // sizeof(arr): num de bytes ocupados pelo array arr. Inclui espaços adicionais de alinhamento ou padding.
    // sizeof(arr[0]): num de bytes ocupados pelo tipo de dado do 1° elemento do array arr. 
    //Como o tipo de dado dos elementos do array é o mesmo, essa expressão retornará o número de bytes ocupados por um único elemento do array.
    //Ao dividir o sizeof(arr)/(arr[0]), estamos calculando quantos elementos há no array arr. 


    int a = 5, b = 10;
    cout << "Antes da troca: a = " << a << ", b = " << b << endl;
    // Chama a função trocar para trocar os valores de a e b
    TrocaNumeros(a, b);
    cout << "Depois da troca: a = " << a << ", b = " << b << endl;

}




