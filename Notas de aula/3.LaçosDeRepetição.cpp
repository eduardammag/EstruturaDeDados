#include <iostream>
using std::cin; 
using std::cout; 
using std::endl;
using std::string;

int main()
{
    int icontador = 0; // Declara e inicializa a variável icontador com o valor 0
    
    // Loop while que continua enquanto icontador for menor ou igual a 5
    while (icontador <= 5)
    {
        cout << icontador << "\n"; // Imprime o valor de icontador seguido de uma nova linha
        icontador++; // Incrementa o valor de icontador
    }
    
    icontador = 42; // Atribui o valor 42 à variável icontador
    
    // Loop do-while que executa pelo menos uma vez e continua enquanto icontador for menor ou igual a 5
    do
    {
        cout << icontador << "\n"; // Imprime o valor de icontador seguido de uma nova linha
        icontador++; // Incrementa o valor de icontador
    }
    while (icontador <= 5); // Condição de continuação do loop do-while
    
    // Loop for aninhado que percorre as combinações de três números de 1 a 10
    for (int i = 1; i < 11; i++) // Loop externo de 1 a 10
    {
        for (int j = 1; j < 11; j++ ) // Loop interno de 1 a 10
        {
            for (int k = 1; k < 11; k++ ) // Loop interno de 1 a 10
                cout << "(" << i << "," << j << "," << k << ")" << "\n"; // Imprime uma tupla (i, j, k)
        }
    }
    
    //cout << i << "\n"; // A variável i não existe fora do escopo do loop for
    
    return 0; // Retorna 0 para indicar que o programa foi concluído com sucesso
}

// Observações:
// - Condições de uso do for: início, fim e atualização separados por ;
// - i++ é equivalente a i = i + 1 (incremento de i)
// - i-- é equivalente a i = i - 1 (decremento de i)

    