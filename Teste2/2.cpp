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

    // Função que retira um nó por ID
    bool removeByID(int id) {
        if (!head) return false;  // Lista está vazia

        Node* temp = head;
        do {
            if (temp->songID == id) {
                if (temp->next == temp && temp->prev == temp) {  // Único nó na lista
                    delete temp;
                    head = nullptr;
                    current = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) head = temp->next;
                    if (temp == current) current = temp->next;
                    delete temp;
                }
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;  // ID não encontrado
    }

    // Função que deleta a lista e libera sua memória
    void deleteList() {
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

    // Destrutor para liberar a memória
    ~CircularDoublyLinkedList() {
        deleteList();
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

    // Função que intercala duas listas circulares
    static CircularDoublyLinkedList* intercalateLists(CircularDoublyLinkedList* list1, CircularDoublyLinkedList* list2) {
        CircularDoublyLinkedList* newList = new CircularDoublyLinkedList();

        if (!list1->head && !list2->head) return newList; // Ambas as listas são vazias
        if (!list1->head) { // Apenas a lista 2 tem elementos
            *newList = *list2;
            list2->head = nullptr;
            list2->current = nullptr;
            return newList;
        }
        if (!list2->head) { // Apenas a lista 1 tem elementos
            *newList = *list1;
            list1->head = nullptr;
            list1->current = nullptr;
            return newList;
        }

        Node* temp1 = list1->head;
        Node* temp2 = list2->head;
        Node* last = nullptr;
        bool first = true;

        do {
            if (temp1 != list1->head || first) {
                Node* newNode = new Node(temp1->songID);
                if (!newList->head) {
                    newList->head = newNode;
                    last = newNode;
                } else {
                    last->next = newNode;
                    newNode->prev = last;
                    last = newNode;
                }
                temp1 = temp1->next;
            }
            if (temp2 != list2->head || first) {
                Node* newNode = new Node(temp2->songID);
                if (!newList->head) {
                    newList->head = newNode;
                    last = newNode;
                } else {
                    last->next = newNode;
                    newNode->prev = last;
                    last = newNode;
                }
                temp2 = temp2->next;
            }
            first = false;
        } while (temp1 != list1->head || temp2 != list2->head);

        // Conectar os extremos para formar a lista circular
        if (last) {
            last->next = newList->head;
            newList->head->prev = last;
        }

        newList->current = newList->head;
        return newList;
    }

    // Função que verifica se há um loop na lista
    static bool hasLoop(Node* head) {
        if (!head) return false;

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;  // Loop detectado
        }

        return false;  // Nenhum loop encontrado
    }

    // Função para acessar o nó inicial (HEAD
    Node* getHead() const {
        return head;
    }
};

int main() {
    CircularDoublyLinkedList playlist1;
    CircularDoublyLinkedList playlist2;

    int songIDs1[] = {101, 103, 105};
    int songIDs2[] = {102, 104, 106, 108, 110};

    playlist1.createList(songIDs1, 3);
    playlist2.createList(songIDs2, 5);

    std::cout << "Playlist 1: ";
    playlist1.printList();

    std::cout << "Playlist 2: ";
    playlist2.printList();

    CircularDoublyLinkedList* intercalatedPlaylist = CircularDoublyLinkedList::intercalateLists(&playlist1, &playlist2);

    std::cout << "Intercalated Playlist: ";
    intercalatedPlaylist->printList();

    delete intercalatedPlaylist;

    // Teste para verificar loop
    CircularDoublyLinkedList testList;
    int testIDs[] = {201, 202, 203, 204};
    testList.createList(testIDs, 4);

    // Introduzindo um loop manualmente para teste
    testList.getHead()->next->next->next->next = testList.getHead()->next; // Loop: 204 -> 202

    std::cout << "Test list has loop: " << CircularDoublyLinkedList::hasLoop(testList.getHead()) << std::endl;

    return 0;
}