#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Node:
// Um nó é uma estrutura de dados básica usada em listas encadeadas e em outras estruturas de dados.
// No contexto deste código, um nó é uma estrutura que contém um valor de dados (iData) e um ponteiro para o próximo nó na sequência.

// LinkedList:
// Uma lista encadeada é uma estrutura de dados na qual os elementos são armazenados em nós, onde cada nó contém um valor de dados e um ponteiro para o próximo nó na sequência.
// Nesta implementação, a lista encadeada é representada pelo ponteiro para o primeiro nó (ptrFirst).

typedef struct Node
{
    int iData;          // Dado armazenado no nó
    Node* ptrNext;      // Ponteiro para o próximo nó na sequência
} Node;
 
typedef struct LinkedList
{
    Node* ptrFirst;     // Ponteiro para o primeiro nó na lista
} LinkedList;
 
LinkedList* newLinkedList();                 // Função para criar uma nova lista encadeada
Node* newNode(int);                           // Função para criar um novo nó com um dado valor
void showFirstElement(LinkedList* const);     // Função para exibir o primeiro elemento da lista
void showLastElement(LinkedList* const);      // Função para exibir o último elemento da lista
void showElements(LinkedList* const);         // Função para exibir todos os elementos da lista
void addElement(LinkedList* const, int);      // Função para adicionar um novo elemento à lista
void removeElement(LinkedList* const, int);   // Função para remover um elemento da lista

////////////////////////////////////////////////////////////////////////////////

int main()
{
    // Cria uma nova lista encadeada
    LinkedList* linkedList = newLinkedList();
    
    // Mostra o primeiro e o último elementos da lista (deve indicar que a lista está vazia)
    showFirstElement(linkedList);
    showLastElement(linkedList);
    
    // Mostra todos os elementos da lista (deve indicar que a lista está vazia)
    showElements(linkedList);
    
    // Tenta remover um elemento de uma lista vazia (deve indicar que a lista está vazia)
    removeElement(linkedList, 666);
    
    cout << "=========================================================" << endl;
    
    // Adiciona um elemento à lista
    addElement(linkedList, 0);
    
    // Mostra o primeiro e o último elementos da lista (ambos devem ser 0)
    showFirstElement(linkedList);
    showLastElement(linkedList);
    
    cout << "=========================================================" << endl;
    
    // Adiciona vários elementos à lista
    addElement(linkedList, 3);
    addElement(linkedList, 7);
    addElement(linkedList, 10);
    addElement(linkedList, 13);
    addElement(linkedList, 42);
    
    cout << "=========================================================" << endl;
    
    // Mostra todos os elementos da lista
    showElements(linkedList);
    
    cout << "=========================================================" << endl;
    
    // Remove alguns elementos da lista
    removeElement(linkedList, 0);
    removeElement(linkedList, 3);
    
    // Mostra o primeiro e o último elementos da lista após a remoção
    showFirstElement(linkedList);
    showLastElement(linkedList);
    
    // Tenta remover um elemento que não está na lista
    removeElement(linkedList, 666);

    cout << "=========================================================" << endl;
    
    // Remove os elementos restantes da lista
    removeElement(linkedList, 10);
    removeElement(linkedList, 13);
    removeElement(linkedList, 42);
    
    // Mostra o primeiro e o último elementos da lista após a remoção
    showFirstElement(linkedList);
    showLastElement(linkedList);
    
    cout << "=========================================================" << endl;
    
    // Tenta remover um elemento de uma lista vazia
    removeElement(linkedList, 7);
    
    // Mostra o primeiro e o último elementos da lista após a tentativa de remoção
    showFirstElement(linkedList);
    showLastElement(linkedList);
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

// Função para criar uma nova lista encadeada
LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));  // Alocação de memória para a lista
    temp->ptrFirst = nullptr;                                     // Inicialização do ponteiro para o primeiro nó como nulo

    return temp;
}

// Função para criar um novo nó com um dado valor
Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));    // Alocação de memória para o nó
    temp->iData = iValue;                         // Atribuição do valor ao nó
    temp->ptrNext = nullptr;                      // Inicialização do ponteiro para o próximo nó como nulo
    
    return temp;
}

// Função para exibir o primeiro elemento da lista
void showFirstElement(LinkedList* const linkedList)
{
    // Verifica se a lista está vazia
    if (linkedList == nullptr || linkedList -> ptrFirst == nullptr)
    {
        cout << "showFirstElement: Lista vazia" << endl;
    }
    else
    {
        cout << "Primeiro da lista: " << linkedList -> ptrFirst -> iData << endl;
    }
}

// Função para exibir o último elemento da lista
void showLastElement(LinkedList* const linkedList)
{
    // Verifica se a lista está vazia
    if (linkedList == nullptr || linkedList -> ptrFirst == nullptr)
    {
        cout << "showLastElement: Lista vazia" << endl;
    }
    else
    {
        Node* lastNode = linkedList -> ptrFirst;
        
        // Percorre a lista até o último nó
        while (lastNode -> ptrNext != nullptr)
        {
            lastNode = lastNode -> ptrNext;
        }
        
        cout << "Último da lista: " << lastNode -> iData << endl;
    }
}

// Função para exibir todos os elementos da lista
void showElements(LinkedList* const linkedList)
{
    // Verifica se a lista está vazia
    if (linkedList == nullptr || linkedList -> ptrFirst == nullptr)
    {
        cout << "showElements: Lista vazia" << endl;
    }
    else
    {
        Node* current = linkedList -> ptrFirst;
        
        cout << "Elementos da lista:";
        
        // Percorre a lista e exibe os elementos
        while (current != nullptr)
        {
            cout << " " << current -> iData;
            current = current -> ptrNext;
        }
        
        cout << endl;
    }
}

// Função para adicionar um novo elemento à lista
void addElement(LinkedList* const linkedList, int iValue)
{
    // Cria um novo nó com o valor especificado
    Node* temp = newNode(iValue);
    
    // Verifica se a lista existe
    if (linkedList == nullptr)
    {
        cout << "Lista não existente";
    }
    // Verifica se a lista está vazia
    else if (linkedList -> ptrFirst == nullptr)
    {
        linkedList -> ptrFirst = temp;
    }
    else
    {
        Node* lastNode = linkedList -> ptrFirst;
        
        // Percorre a lista até o último nó
        while (lastNode -> ptrNext != nullptr)
        {
            lastNode = lastNode -> ptrNext;
        }
        
        // Insere o novo nó após o último nó existente
        lastNode -> ptrNext = temp;
    }
}

// Função para remover um elemento da lista
void removeElement(LinkedList* const linkedList, int iValue)
{
    // Caso especial: lista vazia ou inexistente
    if (linkedList == nullptr || linkedList -> ptrFirst == nullptr)
    {
        cout << "removeElement: Lista vazia" << endl;
        return;
    }
    
    Node* current = linkedList -> ptrFirst;
    Node* previous = nullptr;
    
    // Caso especial: o primeiro nó é o escolhido para remoção
    if (current -> iData == iValue)
    {
        linkedList -> ptrFirst = linkedList -> ptrFirst -> ptrNext;
        free(current);
        return;
    }
    
    // Percorre a lista até encontrar o elemento ou o final da lista
    while (current != nullptr && current -> iData != iValue)
    {
        previous = current;
        current = current -> ptrNext;
    }
    
    // Caso especial: elemento não encontrado
    if (current == nullptr)
    {
        cout << iValue << ": Elemento não encontrado" << endl;
        return;
    }
    
    // Repara a lista após a remoção
    previous -> ptrNext = current -> ptrNext;
    free(current);
}
