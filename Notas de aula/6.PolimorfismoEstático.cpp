/* O polimorfismo estático, também conhecido como sobrecarga de função, ocorre em tempo de compilação e é resolvido pelo compilador. 
Ele permite que várias funções com o mesmo nome operem de maneira diferente, dependendo dos tipos e/ou do número de argumentos passados para elas.
Por exemplo, considere uma função area que calcula a área de diferentes formas geométricas:
*/

#include <iostream>

using std::cout;
using std::endl;

// Função para calcular a área do quadrado
float area(float lado) {
    return lado * lado;
}

// Função para calcular a área do retângulo
float area(float comprimento, float largura) {
    return comprimento * largura;
}

int main() {
    cout << "Área do quadrado com lado 5: " << area(5.0) << endl;
    cout << "Área do retângulo com comprimento 4 e largura 6: " << area(4.0, 6.0) << endl;

    return 0;
}


/*  Neste exemplo, temos três funções chamadas area, cada uma com uma assinatura diferente (número e/ou tipo de parâmetros). 
Dependendo do tipo e número de argumentos passados, o compilador decide qual versão da função area deve ser chamada. 
Isso é polimorfismo estático, pois a seleção da função ocorre em tempo de compilação e é baseada nas assinaturas das funções.


Em C++, você não pode ter várias funções com o mesmo nome e a mesma lista de parâmetros. 
Você só pode ter sobrecargas de função se as assinaturas forem diferentes.
*/
