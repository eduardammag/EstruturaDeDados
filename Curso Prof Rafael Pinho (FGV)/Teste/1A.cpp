#include <iostream>

struct Node {
    int songID;
    Node* next;
    Node* prev;
    
    Node(int id) : songID(id), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;
    Node* current;
    
public:
    CircularDoublyLinkedList() : head(nullptr), current(nullptr) {}
    
    // Função para criar a lista a partir de um array de IDs
    void createList(int ids[], int size) {
        if (size == 0) return;
        
        head = new Node(ids[0]);
        Node* last = head;
        
        for (int i = 1; i < size; ++i) {
            Node* newNode = new Node(ids[i]);
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
        
        last->next = head;
        head->prev = last;
        current = head;
    }
    
    // Função que retorna o ID atual e avança a lista
    int getCurrentAndAdvance() {
        if (!current) return -1;  // Retorna -1 se a lista estiver vazia
        int id = current->songID;
        current = current->next;
        return id;
    }
    
    // Função que retorna o ID atual e retrocede a lista
    int getCurrentAndRewind() {
        if (!current) return -1;  // Retorna -1 se a lista estiver vazia
        int id = current->songID;
        current = current->prev;
        return id;
    }
    
    // Função para imprimir a lista (para fins de depuração)
    void printList() {
        if (!head) return;
        
        Node* temp = head;
        do {
            std::cout << temp->songID << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
    
    // Destrutor para liberar a memória
    ~CircularDoublyLinkedList() {
        if (!head) return;
        
        Node* temp = head;
        do {
            Node* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
        
        head = nullptr;
        current = nullptr;
    }
};

int main() {
    CircularDoublyLinkedList playlist;
    int songIDs[] = {101, 102, 103, 104, 105};
    
    playlist.createList(songIDs, 5);
    playlist.printList();
    
    std::cout << "Current ID: " << playlist.getCurrentAndAdvance() << std::endl;
    std::cout << "Current ID: " << playlist.getCurrentAndAdvance() << std::endl;
    std::cout << "Current ID: " << playlist.getCurrentAndRewind() << std::endl;
    std::cout << "Current ID: " << playlist.getCurrentAndRewind() << std::endl;
    
    return 0;
}