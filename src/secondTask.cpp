#include <iostream>

void secondTask() {
    std::cout << "введите число: ";
    int num;
    std::cin >> num;
    switch (signbit(num)) {
        case 1:
            std::cout << "знак числа '-'" << std::endl;
        break;
        case 0:
            if (num == 0) std::cout<< "число является нулем!" << std::endl;
            else std::cout << "знак числа '+'"<< std::endl;
        break;
        default: std::cout << "вероятнее всего вы что то не так ввели" << std::endl;
        break;
    }
}
