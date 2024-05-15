#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::string;
using std::endl;

// Pilha (Stack):
// Uma estrutura de dados que segue o princípio LIFO (Last In, First Out).
// Isso significa que o último elemento adicionado à pilha é o primeiro a ser removido.

// Fila (Queue):
// Uma estrutura de dados que segue o princípio FIFO (First In, First Out).
// Isso significa que o primeiro elemento adicionado à fila é o primeiro a ser removido.

// Node:
// Um nó é uma estrutura de dados básica usada em listas encadeadas e em outras estruturas de dados.
// No contexto deste código, um nó é uma estrutura que contém um valor de dados (iData) e um ponteiro para o próximo nó na sequência.

// Ponteiro de um node que aponta para outro node 

//temp é um ponteiro temporário dentro da função, mas o que muda é o constantemente é o current 


//1.Definindo a estrutura de um nó
typedef struct Node
{
    int iData;            //O meu tipo de dado do nó
    struct Node* ptrNext; //O ponteiro aponta para o próximo elemento da pilha
} Node;

//Como já definimos o Node, podemos chamá-lo agora só por 'Node*' e não por 'struct Node*'

//2.Definindo a estrutura de uma pilha
typedef struct Stack
{
    Node* ptrTop; //O ponteiro aponta para o topo da pilha
} Stack;

//3. Assinaturas de funções que serão definidas e chamadas mais tarde

// RetornoDaFunção* NomeDaFunção(EntradaDaFunção);

//3.1 Função para criar um novo nó com um valor dado
Node* newNode(int);

//3.2 Função para criar uma nova pilha vazia
Stack* newStack();

//3.3 Função para exibir o elemento no topo da pilha
void showTopElement(Stack* const);

//3.4 Função para exibir todos os elementos da pilha
void showElements(Stack* const);

//3.5 Função para adicionar um novo elemento ao topo da pilha
void push(Stack* const, int);

//3.6 Função para remover o elemento do topo da pilha
void pop(Stack* const);

//4 Int main


int main()
{
   //Criando uma pilha vazia
   Stack*stack = newStack();
   
   //Testando a remoção de um elemento de uma pilha vazia
   cout<<"---"<< endl;
   pop(stack);
   cout << "---" << endl;
   
   //Mostrar o elemento do topo da pilha(deve ser -1)
   showTopElement(stack);
   
   //Mostrando os elementos(não sai nada, pois a lista está vazia)
   void showElements(Stack* const);
   
   //Adicionando alguns elementos à pilha
   push(stack,0);
   push(stack,3);
   push(stack,7);
   push(stack,10);
   showTopElement(stack);
   showElements(stack);
   cout<< "---"<< endl;
   pop(stack);
   showTopElement(stack);
   
   return 0;
   
}

//5.Função para criar um novo nó com um dado valor 
Node* newNode(int iValue)
{
    // Aloca memória para um novo nó 
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->iData = iValue;

    temp->ptrNext = nullptr; 
        return temp;
}



//6.Função para criar uma nova pilha vazia 
Stack* newStack()
{   
    // Aloca memória para uma nova pilha
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp-> ptrTop = nullptr; //Aponta pra nada porque não tem elemento
    
    return temp;
}

//7.Função para exibir o elemento no topo da pilha

void showTopElement(Stack* const stack)
{
    // Usa operador ternário para verificar se a pilha está vazia
    // Se ptrTop não for nullptr, imprime o valor do elemento no topo da pilha
    // Caso contrário, imprime -1 para indicar que a pilha está vazia
    cout << "Topo da pilha:" << ((stack -> ptrTop != nullptr) ? (stack -> ptrTop)->iData: -1) << endl;
}

//8. Função para exibir todos os elementos da pilha
void showElements(Stack* const stack)
{
    // Verifica se a pilha está vazia
    if (stack->ptrTop == nullptr)
    {
        // Se a pilha estiver vazia, imprime uma mensagem indicando isso
        cout << "Pilha vazia" << endl;
        
        // Retorna imediatamente, já que não há elementos para mostrar
        return;
    }
    
    // Define um ponteiro para percorrer os elementos da pilha, começando do topo
    Node* current = stack->ptrTop;
    
    // Loop para percorrer todos os elementos da pilha
    while (current != nullptr)
    {
        // Imprime o valor do elemento atual
        cout << "elemento:" << current->iData << endl;
        
        // Move para o próximo elemento na pilha
        current = current->ptrNext;
    }
    
}

//9. Função para adicionar um novo elemento ao topo da pilha
void push(Stack* const stack, int iValue)
{
    // Cria um novo nó com o valor fornecido
    Node* temp = newNode(iValue);
    
    // Define o ponteiro do novo nó para apontar para o nó que está atualmente no topo da pilha
    temp->ptrNext = stack->ptrTop;
    
    // Atualiza o ponteiro do topo da pilha para apontar para o novo nó, que agora está no topo
    stack->ptrTop = temp;
    
    // Retorna, indicando que a operação de adição foi concluída
    return;
}


//10. Função para remover o elemento do topo da pilha
void pop(Stack* const stack)
{
    // Verifica se a pilha está vazia
    if (stack->ptrTop == nullptr)
    {
        // Se a pilha estiver vazia, imprime uma mensagem indicando isso
        cout << "Pilha vazia" << endl;
        
        // Retorna imediatamente, pois não há elementos para remover
        return;
    }
    
    // Imprime o valor do elemento removido (o elemento do topo da pilha)
    cout << "Elemento removido:" << stack->ptrTop->iData << endl;
    
    // Salva o endereço do nó do topo da pilha em uma variável temporária
    Node* temp = stack->ptrTop;
    
    // Atualiza o ponteiro para o topo da pilha para apontar para o próximo nó
    stack->ptrTop = stack->ptrTop->ptrNext;
    
    // Libera a memória alocada para o nó removido
    free(temp);
    
    // Retorna, indicando que a operação de remoção foi concluída
    return;
}








































