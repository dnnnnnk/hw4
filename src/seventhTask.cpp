#include <iostream>
class RandomNumberGenerator {
    const int m;
    const int i;
    const int c;
    public:
    RandomNumberGenerator(const int& m, const int& i, const int& c): m(m), i(i), c(c){}

    void generateRandomNumber(int& S) const {
        for (int j = 1; j <= i; ++j) {
            S = (m * S + i)%c;
        }
        std::cout << S << std::endl;
    }
};

void seventhTask() {
    std::cout << "какой метод используем? (1/2): ";
    int method; std::cin >> method;
    std::cout << std::endl;
    std::cout << "введите начальное число: ";
    int inputS; std::cin >> inputS;
    std::cout << std::endl;
    if (method == 1) {
        const RandomNumberGenerator firstMethod(37, 3, 64);
        firstMethod.generateRandomNumber(inputS);
    }
    else if (method == 2) {
        const RandomNumberGenerator secondMethod(25173, 13849, 65537);
        secondMethod.generateRandomNumber(inputS);
    }

}
