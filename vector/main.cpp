#include <iostream>
#include <vector.hpp>

int main() {
    Vector<int> vetor;

    for (int i = 0; i < 10; i++) {
        vetor.push_back(i);
    }

    std::cout << vetor << std::endl;

    vetor.erase(5);

    std::cout << vetor << std::endl;
    std::cout << "Capacidade: " << vetor.get_capacity() << "\nTamanho: " << vetor.get_size() << std::endl;
}
