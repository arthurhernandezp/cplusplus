#include <iostream>

template<typename T>
T soma(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Soma de inteiros: " << soma(5, 3) << std::endl;
    std::cout << "Soma de doubles: " << soma(3.5, 2.7) << std::endl;
    return 0;
}
