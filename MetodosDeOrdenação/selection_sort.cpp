#include <iostream>
#include <cstdlib> //por vezes é necessário para o uso do malloc
#include <chrono> //para avaliar o desempenho do algoritmo
#include <ctime> //para gerar números aleatórios

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

// Definição de estrutura para os nós da lista duplamente encadeada
typedef struct Node
{
    int iPayload;   // Dados armazenados no nó
    Node* ptrNext;  // Ponteiro para o próximo nó na lista
    Node* ptrPrev;  // Ponteiro para o nó anterior na lista
} Node;

//Protótipos das funções
Node* createNode(int);
void displayList(Node*);
void insertEnd(Node**, int);
void deleteNode(Node**, Node*);
void deleteList(Node**);
void swapValue(int&, int&);
void selectionSort(Node*);
void optimizedSelectionSort(Node*);

int main()
{
    //testando se a função está ordenando corretamente
    Node* headAges = nullptr;

    //Inserindo elementos na lista de idades (ordenei a lista com o pior caso, ou seja, de forma decrescente)
    insertEnd(&headAges, 100);
    insertEnd(&headAges, 97);
    insertEnd(&headAges, 89);
    insertEnd(&headAges, 45);
    insertEnd(&headAges, 32);
    insertEnd(&headAges, 0);

    cout << "Lista de idades original: "; 
    displayList(headAges);  

    selectionSort(headAges);

    cout << "Lista de idades ordenada (Selection Sort): "; 
    displayList(headAges);

    deleteList(&headAges);

    cout << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headGrades = nullptr;

    //Inserindo elementos na lista de notas (coloquei a lista já ordenada para testar se bagunça ou imprime ela como está)
    insertEnd(&headGrades, -1);
    insertEnd(&headGrades, 0);
    insertEnd(&headGrades, 2);
    insertEnd(&headGrades, 3);
    insertEnd(&headGrades, 4); 

    cout << "Lista de notas original: "; 
    displayList(headGrades);  

    selectionSort(headGrades);

    cout << "Lista de notas ordenada (Selection Sort): "; 
    displayList(headGrades);

    deleteList(&headGrades);

    cout << "============================" << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headRandomNumbers = nullptr;

    //inserindo um exemplo de lista com valores em ordem aleatória
    insertEnd(&headRandomNumbers, -15);
    insertEnd(&headRandomNumbers, 27);
    insertEnd(&headRandomNumbers, 86);
    insertEnd(&headRandomNumbers, 3);
    insertEnd(&headRandomNumbers, 17);

    cout << "Lista de números aleatórios original: "; 
    displayList(headRandomNumbers);  

    selectionSort(headRandomNumbers);

    cout << "Lista de números aleatórios ordenada (Selection Sort): "; 
    displayList(headRandomNumbers);

    deleteList(&headRandomNumbers);

    cout << "============================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Definindo variáveis para fazer o tempo gasto em média com cada função ao ordenar as lista abaixo
    long long llTotalSelectionSortTime = 0;
    long long llTotalOptimizedSelectionSortTime = 0;
    const int iNumLists = 4;
    const int iListSize = 15000;
    
    //Gerando listas aleatórias com uma quantidade grande de elementos a fim de comparar o tempo gasto com a ordenação de cada lista
    Node* headList1 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = rand() % 100000; // Gera um número aleatório entre 0 e 99999
        insertEnd(&headList1, randomValue);
    }
    
    auto timeStart1 = high_resolution_clock::now();  //tempo antes de ordenar
    selectionSort(headList1);
    auto timeStop1 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    llTotalSelectionSortTime += timeDuration1.count();
    cout << "Tempo utilizado na ordenação da lista 1 (Selection Sort): " << timeDuration1.count() << " nanosegundos." << endl;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart2 = high_resolution_clock::now();  //tempo antes de ordenar
    optimizedSelectionSort(headList1);
    auto timeStop2 = high_resolution_clock::now();  //tempo depois de ordenar
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);
    llTotalOptimizedSelectionSortTime += timeDuration2.count();
    cout << "Tempo utilizado na ordenação da lista 1 (Optimized Selection Sort): " << timeDuration2.count() << " nanosegundos." << endl;
    cout << "============================" << endl;
    
    deleteList(&headList1);
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Node* headList2 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = rand() % 100000; // Gera um número aleatório entre 0 e 99999
        insertEnd(&headList2, randomValue);
    }
    
    auto timeStart3 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    selectionSort(headList2);
    auto timeStop3 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    llTotalSelectionSortTime += timeDuration3.count();
    cout << "Tempo utilizado na ordenação da lista 2 (Selection Sort): " << timeDuration3.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart4 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedSelectionSort(headList2);
    auto timeStop4 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4);
    llTotalOptimizedSelectionSortTime += timeDuration4.count();
    cout << "Tempo utilizado na ordenação da lista 2 (Optimized Selection Sort): " << timeDuration4.count() << " nanosegundos." << endl;
    cout << "============================" << endl;
    
    deleteList(&headList2);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList3 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = rand() % 100000; // Gera um número aleatório entre 0 e 99999
        insertEnd(&headList3, randomValue);
    }
    
    auto timeStart5 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    selectionSort(headList3);
    auto timeStop5 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration5 = duration_cast<nanoseconds>(timeStop5 - timeStart5);
    llTotalSelectionSortTime += timeDuration5.count();
    cout << "Tempo utilizado na ordenação da lista 3 (Selection Sort): " << timeDuration5.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart6 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedSelectionSort(headList3);
    auto timeStop6 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration6 = duration_cast<nanoseconds>(timeStop6 - timeStart6);
    llTotalOptimizedSelectionSortTime += timeDuration6.count();
    cout << "Tempo utilizado na ordenação da lista 3 (Optimized Selection Sort): " << timeDuration6.count() << " nanosegundos." << endl;
    cout << "============================" << endl;
    
    deleteList(&headList3);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Node* headList4 = nullptr;

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(nullptr));

    // Inserindo elementos nas listas duplamente encadeadas
    for (int i = 0; i < iListSize; ++i)
    {
        int randomValue = rand() % 100000; // Gera um número aleatório entre 0 e 99999
        insertEnd(&headList4, randomValue);
    }
    
    auto timeStart7 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    selectionSort(headList4);
    auto timeStop7 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration7 = duration_cast<nanoseconds>(timeStop7 - timeStart7);
    llTotalSelectionSortTime += timeDuration7.count();
    cout << "Tempo utilizado na ordenação da lista 4 (Selection Sort): " << timeDuration7.count() << " nanosegundos." << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto timeStart8 = high_resolution_clock::now();  //calcula o tempo antes de ordenar
    optimizedSelectionSort(headList4);
    auto timeStop8 = high_resolution_clock::now();  //calcula o tempo depois de ordenar
    
    auto timeDuration8 = duration_cast<nanoseconds>(timeStop8 - timeStart8);
    llTotalOptimizedSelectionSortTime += timeDuration8.count();
    cout << "Tempo utilizado na ordenação da lista 4 (Optimized Selection Sort): " << timeDuration8.count() << " nanosegundos." << endl;
    cout << "============================" << endl;
    
    deleteList(&headList4); 

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

    // Calculando a média dos tempos
    long long llAvgSelectionSortTime = llTotalSelectionSortTime / iNumLists;
    long long llAvgOptimizedSelectionSortTime = llTotalOptimizedSelectionSortTime / iNumLists;

    // Exibindo os resultados
    cout << "Média do tempo utilizado na ordenação com Selection Sort: " << llAvgSelectionSortTime << " nanosegundos." << endl;
    cout << "Média do tempo utilizado na ordenação com Optimized Selection Sort: " << llAvgOptimizedSelectionSortTime << " nanosegundos." << endl;

    return 0;
}

// Função para criar um novo nó com um inteiro fornecido
Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp -> iPayload = iPayload;
    temp -> ptrNext = nullptr;
    temp -> ptrPrev = nullptr;
    
    return temp;
}

// Função para exibir os elementos da lista
void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return; // Sai da função se a lista estiver vazia
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return; // Sai da função se o nó não for o primeiro na lista
       
    }
    
    Node* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp -> iPayload<< " ";
        temp = temp -> ptrNext;
    }
    
    cout << endl;
}

// Função para inserir um novo nó no final da lista
void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);  // Cria um novo nó com o inteiro fornecido
    
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    
    // Percorre a lista até o fim
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;   // O novo nó aponta para o último nó da lista
    temp->ptrNext = newNode;   // O último nó da lista aponta para o novo nó
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

void deleteList(Node** head)
{
    Node* current = *head;
    Node* next;

    while (current != nullptr)
    {
        next = current->ptrNext;
        free(current);
        current = next;
    }

    *head = nullptr; // Atualiza a cabeça da lista para nullptr
}

//função para trocar dois valores
void swapValue(int& iValue_1, int& iValue_2)
{
    int iTemp = iValue_1;
    iValue_1 = iValue_2;
    iValue_2 = iTemp;
}

// Função para ordenar uma lista duplamente encadeada usando o método Selection Sort
void selectionSort(Node* head) 
{
    Node* current = head;
    while (current != nullptr) 
    {
        Node* innerCurrent = current->ptrNext;
        while (innerCurrent != nullptr) 
        {
            if (current->iPayload > innerCurrent->iPayload) 
            {
                swapValue(current->iPayload, innerCurrent->iPayload);
            }
            innerCurrent = innerCurrent->ptrNext;
        }
        current = current->ptrNext;
    }
}

// Função para ordenar uma lista duplamente encadeada usando o método Selection Sort de forma otimizada
void optimizedSelectionSort(Node* head) 
{
    Node* current = head;

    while (current != nullptr) 
    {
        Node* minNode = current;
        Node* innerCurrent = current->ptrNext;

        while (innerCurrent != nullptr) 
        {
            if (minNode->iPayload > innerCurrent->iPayload) 
            {
                minNode = innerCurrent;
            }
            innerCurrent = innerCurrent->ptrNext;
        }
        if (minNode != current) 
        {
            swapValue(current->iPayload, minNode->iPayload);
        }
        current = current->ptrNext;
    }
}