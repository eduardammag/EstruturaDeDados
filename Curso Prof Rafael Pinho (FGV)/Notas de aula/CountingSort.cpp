#include <iostream>
#include <vector>
#include <algorithm>

// Função para encontrar o máximo elemento no vetor
template <typename T>
T findMax(const std::vector<T>& vec) {
    return *std::max_element(vec.begin(), vec.end());
}

// Função de ordenação usando o algoritmo Counting Sort
template <typename T>
void countingSort(std::vector<T>& vec) {
    T maxElement = findMax(vec);
    std::vector<int> count(maxElement + 1, 0);
    std::vector<T> result(vec.size());

    // Contagem da ocorrência de cada elemento
    for (const auto& elem : vec) {
        count[elem]++;
    }

    // Atualização dos índices
    for (int i = 1; i <= maxElement; ++i) {
        count[i] += count[i - 1];
    }

    // Ordenação do vetor de entrada
    for (int i = vec.size() - 1; i >= 0; --i) {
        result[count[vec[i]] - 1] = vec[i];
        count[vec[i]]--;
    }

    // Cópia do resultado para o vetor de entrada
    for (size_t i = 0; i < vec.size(); ++i) {
        vec[i] = result[i];
    }
}

// Função para imprimir um vetor
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {4, 2, 2, 8, 3, 3, 1};
    
    std::cout << "Vetor original: ";
    printVector(vec);

    countingSort(vec);

    std::cout << "Vetor ordenado: ";
    printVector(vec);

    return 0;
}
