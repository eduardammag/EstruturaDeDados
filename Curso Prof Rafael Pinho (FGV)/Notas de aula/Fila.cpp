#include <iostream>
#include <cstdlib> //para usar o malloc

using std::cin;
using std::cout;
using std::string;
using std::endl;

// - Fila (Queue):
// Segue o princípio FIFO (First In, First Out), ou seja, o primeiro elemento adicionado à fila é o primeiro a ser removido.

// Ponteiro de um node que aponta para outro node 
typedef struct Node
{
    int iData;          // Dado armazenado no nó
    struct Node* next;  // Ponteiro para o próximo nó na sequência
} Node;

// Definição da estrutura de uma fila
typedef struct Queue
{
    struct Node* front; // Ponteiro para o primeiro nó na fila
    struct Node* rear;  // Ponteiro para o último nó na fila
} Queue;

// Função para criar um novo nó com um dado valor
Node* newNode(int iValue)
{
    Node* temp = (Node*)  malloc(sizeof(Node)); 
    temp-> iData = iValue;
    temp-> next = nullptr;
    
    return temp;
}

// Função para criar uma nova fila vazia
Queue* newQueue()
{
    Queue* temp = (Queue*)  malloc(sizeof(Queue)); // Alocação de memória para a fila
    temp-> front = nullptr;  // Inicialização do ponteiro para o primeiro nó como nulo
    temp-> rear = nullptr;   // Inicialização do ponteiro para o último nó como nulo
    
    return temp ;
}

// Função para adicionar um novo elemento ao final da fila
void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue); // Criação de um novo nó com o valor especificado
    
    // Se a fila estiver vazia, o novo nó é tanto o primeiro quanto o último nó
    if (queue-> front == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        // Caso contrário, o próximo do último nó se torna o novo nó e o último nó é atualizado
        queue-> rear-> next = temp;
        queue-> rear = temp;
    }
    
    return;
}

// Função para exibir o primeiro elemento da fila
void showFirstElement(Queue* const queue)
{
    // Se a fila não estiver vazia, mostra o primeiro elemento, caso contrário, mostra -1
    cout << "Primeiro elemento:" << ( (queue->front!= NULL) ? (queue->front) ->iData : -1)<< endl;
}

// Função para exibir o último elemento da fila
void showLastElement(Queue* const queue)
{
   // Se a fila não estiver vazia, mostra o último elemento, caso contrário, mostra -1
   cout << "Último elemento:" << ( (queue->rear!= NULL) ? (queue->rear) ->iData : -1)<< endl;
}

// Função para exibir todos os elementos da fila
void showElements(Queue* const queue)
{
   // Se a fila estiver vazia, mostra uma mensagem indicando isso e retorna
   if (queue->front == nullptr)
   {
       cout << "Fila vazia" << endl;
       return;
   }
   
   // Itera sobre todos os nós da fila e os exibe
   Node* current = queue-> front;
   
   while (current != nullptr)
   {
       cout << "Elemento:" << current->iData<< endl;
       current = current->next;
   }
}

// Função para remover o primeiro elemento da fila
void deQueue(Queue* const queue)
{
    // Verifica se a fila está vazia
    if (queue->front == nullptr)
   {
       cout << "Fila vazia" << endl;
       return;
   }
   
   // Salva o ponteiro para o primeiro nó em uma variável temporária
   Node* temp = queue-> front; // Variável que recebe o endereço do primeiro nó da fila
   
   cout<< "Elemento removido:"<< temp ->iData<< endl;
   
   // O novo primeiro nó da fila será o próximo do nó removido
   queue->front  = queue->front->next;
   
   // Se o nó removido era o único na fila, o último nó também precisa ser atualizado
   if (queue->front == nullptr) 
   {
       queue->rear = nullptr;
   }
   
   // Libera a memória do nó removido
   free(temp);
    
    return;
}

int main()
{
    // Cria uma nova fila
    Queue* queue_1 = newQueue();
    
    // Mostra o primeiro e o último elementos da fila (deve ser -1, indicando que a fila está vazia)
    showFirstElement(queue_1);
    showLastElement(queue_1);
    
    // Mostra todos os elementos da fila (deve mostrar "Fila vazia")
    showElements(queue_1);
    
    // Tenta remover um elemento de uma fila vazia (deve mostrar "Fila vazia")
    deQueue(queue_1);
    
    cout<< "============================================"<< endl;
    
    // Adiciona um elemento à fila
    enQueue(queue_1, 0);
    
    // Mostra o primeiro e o último elementos da fila (ambos devem ser 0)
    showFirstElement(queue_1);
    showLastElement(queue_1);
    
    cout<< "============================================"<< endl;
    
    // Adiciona vários elementos à fila
    enQueue(queue_1, 3);
    enQueue(queue_1, 7);
    enQueue(queue_1, 13);
    enQueue(queue_1, 42);
    
    cout<< "============================================"<< endl;
    
    // Mostra todos os elementos da fila
    showElements(queue_1);
    
    return 0;
}
