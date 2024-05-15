//LISTA, pilha e fila
//Torre de Hanoi com pilha
//Lista circular: o ultimo elemento aponta para o primeiro
//Lista duplamente encadeada: todo nó aponta para o anterior e para o próximo (buble sort)

//LISTA DUPLAMENTE ENCADEADA:

/*
Uma lista duplamente encadeada é uma estrutura de dados linear na qual cada elemento é um nó que contém dois ponteiros, 
um apontando para o próximo nó na lista (usualmente chamado de "next" ou "próximo"),
 e outro apontando para o nó anterior (usualmente chamado de "prev" ou "anterior").

Cada nó em uma lista duplamente encadeada armazena uma informação (ou dados) e ponteiros para os nós anteriores e seguintes. 
A principal característica da lista duplamente encadeada é a sua capacidade de percorrer a lista tanto para frente quanto para trás de forma eficiente,
já que cada nó mantém referências tanto para o próximo quanto para o anterior.*/


#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Definição de estrutura para os nós da lista duplamente encadeada
typedef struct Node
{
    int iPayload;   // Dados armazenados no nó
    Node* ptrNext;  // Ponteiro para o próximo nó na lista
    Node* ptrPrev;  // Ponteiro para o nó anterior na lista
} Node;

// Protótipos das funções
// Cria um novo nó com os dados fornecidos
Node* createNode(int);

// Insere um novo nó no início da lista
void insertFront(Node**, int);

// Insere um novo nó no final da lista
void insertEnd(Node**, int);

// Insere um novo nó após um nó existente na lista
void insertAfter(Node*, int);

// Remove um nó específico da lista
void deleteNode(Node**, Node*);

// Exibe os elementos da lista
void displayList(Node*);

// Insere um novo nó antes de um nó específico
void insertBefore(Node* ptrLocation, int iPayload);

// Procura um nó com um valor específico e retorna um ponteiro para esse nó
Node* searchNodeByValue(Node** head, int value);

// Remove o primeiro nó encontrado com um valor específico
void deleteNodeByValue(Node** head, int value);

int main()
{
    Node* head = nullptr;

    // Testando a inserção no final da lista
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);

    cout << "==============" << endl;

    // Testando a inserção no início da lista
    insertFront(&head, -1);
    insertFront(&head, -3);
    insertFront(&head, -7);
    displayList(head);

    cout << "==============" << endl;

    // Testando a inserção após um nó específico
    Node* locationNode = searchNodeByValue(&head, 3);
    if (locationNode != nullptr)
        insertAfter(locationNode, 2);
    displayList(head);

    cout << "==============" << endl;

    // Testando a inserção antes de um nó específico
    Node* locationNode2 = searchNodeByValue(&head, 7);
    if (locationNode2 != nullptr)
        insertBefore(locationNode2, 5);
    displayList(head);

    cout << "==============" << endl;

    // Testando a exclusão de um nó específico por valor
    deleteNodeByValue(&head, 2);
    deleteNodeByValue(&head, -3);
    deleteNodeByValue(&head, 10);
    displayList(head);

    cout << "==============" << endl;

    // Testando a exclusão de um nó específico por ponteiro
    Node* nodeToDelete = searchNodeByValue(&head, 13);
    deleteNode(&head, nodeToDelete);
    displayList(head);

    return 0;
}


// Função para criar um novo nó com os dados fornecidos
Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    temp->iPayload = iPayload;                 // Define o payload do novo nó
    temp->ptrNext = nullptr;                   // Inicializa o ponteiro para o próximo nó como nulo
    temp->ptrPrev = nullptr;                   // Inicializa o ponteiro para o nó anterior como nulo
    
    return temp;                               // Retorna o endereço do novo nó
}

// Função para exibir os elementos da lista
void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; // Sai da função se a lista estiver vazia
    }
    
    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return; // Sai da função se o nó não for o primeiro na lista
    }
    
    Node* temp = node;
    cout << "Payload: ";
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    cout << endl;
}

// Função para inserir um novo nó no início da lista
void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);  // Cria um novo nó com os dados fornecidos
    
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;  // Atualiza o ponteiro para o nó anterior do nó atual na cabeça da lista
        newNode->ptrNext = (*head);  // Atualiza o ponteiro para o próximo nó do novo nó
        (*head) = newNode;           // Atualiza a cabeça da lista para o novo nó
        return;
    }
    
    (*head) = newNode;  // Se a lista estiver vazia, o novo nó torna-se a cabeça da lista
}

// Função para inserir um novo nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);  // Cria um novo nó com os dados fornecidos
    
    if (*head == nullptr)
    {
        (*head) = newNode;  // Se a lista estiver vazia, o novo nó torna-se a cabeça da lista
        return;
    }
    
    Node* temp = (*head);
    
    // Percorre a lista até o fim
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;   // O novo nó aponta para o último nó da lista
    temp->ptrNext = newNode;   // O último nó da lista aponta para o novo nó
}

// Função para inserir um novo nó após um nó específico na lista
void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    
    Node* newNode = createNode(iPayload);  // Cria um novo nó com os dados fornecidos
    
    // Corrige os ponteiros do novo nó e do nó posterior ao nó de localização
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;
    
    // Corrige o ponteiro do nó de localização para apontar para o novo nó
    ptrLocation->ptrNext = newNode;
    
    // Corrige o ponteiro do nó posterior ao novo nó para apontar para o novo nó
    if (newNode->ptrNext != nullptr)
        newNode->ptrNext->ptrPrev = newNode;
}

// Função para remover um nó específico da lista
void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }
    
    // Se o nó a ser removido for o primeiro nó da lista, atualiza a cabeça da lista
    if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;
    
    // Se o nó a ser removido não for o último nó da lista, atualiza o ponteiro do nó posterior ao nó a ser removido
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    // Se o nó a ser removido não for o primeiro nó da lista, atualiza o ponteiro do nó anterior ao nó a ser removido
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    free(ptrDelete);  // Libera a memória alocada para o nó a ser removido
}

// Função para inserir um novo nó antes de um nó específico
void insertBefore(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }

    Node* newNode = createNode(iPayload);  // Cria um novo nó com os dados fornecidos

    // Corrige os ponteiros do novo nó e do nó anterior ao nó de localização
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;

    // Corrige o ponteiro do nó de localização para apontar para o novo nó
    ptrLocation->ptrPrev = newNode;

    // Corrige o ponteiro do nó anterior ao novo nó para apontar para o novo nó
    if (newNode->ptrPrev != nullptr)
        newNode->ptrPrev->ptrNext = newNode;
}


//Função para procurar um nó com um valor específico e retornar um ponteiro para esse nó
Node* searchNodeByValue(Node** head, int value)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia. Nenhum nó encontrado." << endl;
        return nullptr;
    }

    Node* temp = *head;

    // Percorre a lista até encontrar um nó com o valor desejado
    while (temp != nullptr)
    {
        if (temp->iPayload == value)
        {
            cout << "Nó com o valor " << value << " encontrado." << endl;
            return temp;
        }
        temp = temp->ptrNext;
    }

    cout << "Nenhum nó com o valor " << value << " encontrado." << endl;
    return nullptr;
}

// Função para remover o primeiro nó encontrado com um valor específico
void deleteNodeByValue(Node** head, int value)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia. Nenhum nó para remover." << endl;
        return;
    }

    Node* temp = *head;

    // Percorre a lista até encontrar um nó com o valor desejado
    while (temp != nullptr)
    {
        if (temp->iPayload == value)
        {
            // Se o nó a ser removido for o primeiro nó da lista, atualiza a cabeça da lista
            if (*head == temp) 
                *head = temp->ptrNext;

            // Se o nó a ser removido não for o último nó da lista, atualiza o ponteiro do nó posterior ao nó a ser removido
            if (temp->ptrNext != nullptr) 
                temp->ptrNext->ptrPrev = temp->ptrPrev;

            // Se o nó a ser removido não for o primeiro nó da lista, atualiza o ponteiro do nó anterior ao nó a ser removido
            if (temp->ptrPrev != nullptr) 
                temp->ptrPrev->ptrNext = temp->ptrNext;

            free(temp);  // Libera a memória alocada para o nó a ser removido
            cout << "Nó com o valor " << value << " removido." << endl;
            return;
        }
        temp = temp->ptrNext;
    }

    cout << "Nenhum nó com o valor " << value << " encontrado para remover." << endl;
}
