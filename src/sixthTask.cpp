#include <iostream>
#include <string>
#include <format>

int convertToInt(const char &input);

void sixthTask() {
    std::cout << "введите число в римском формате: ";
    std::string romanNumber; std::cin >> romanNumber;
    int result = 0;
    bool wasLast = false;
    const size_t length = romanNumber.size();
    std::vector<int> numbers;
    numbers.reserve(length);
    numbers.push_back(convertToInt(romanNumber[0]));
    for(size_t i = 1; i < length; i++) {
        numbers[i] = convertToInt(romanNumber[i]);
    }

    for (int i = 0; i < length-1; i++) {
        if(numbers[i] >= numbers[i+1]) {
            result += numbers[i];
            wasLast = false;
        }
        else {
            result += numbers[i+1]-numbers[i];
            wasLast = true;
            i++;
        }
    }
    if (!wasLast) result += numbers[length-1];
    std::cout << std::format("при переводе числа '{}' из римского формата получается: {}",
        romanNumber, result) << std::endl;
}

int convertToInt(const char &input) {
    switch (input) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            throw std::invalid_argument(std::format("\nошибка! {} - не римская цифра!", input));
    }
}



