#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> reconstruct_ouroboros(int final_value, int n) {
    std::vector<int> ouroboros;
    int current_value = final_value;

    while (ouroboros.size() < n) {
        int a = 0;
        while (true) {
            int divisor = std::pow(2, a);
            if (current_value % divisor != 0) {
                break;
            }
            int potential_b_value = current_value / divisor;
            if ((potential_b_value - 1) % 2 == 0) {
                int b = (potential_b_value - 1) / 2;
                ouroboros.push_back(b);
                current_value = divisor;
                break;
            }
            a++;
        }
    }

    std::reverse(ouroboros.begin(), ouroboros.end());
    return ouroboros;
}

int main() {
    int final_value = 104;
    int n = 3;
    std::vector<int> ouroboros = reconstruct_ouroboros(final_value, n);

    std::cout << "Original ouroboros: ";
    for (int value : ouroboros) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}