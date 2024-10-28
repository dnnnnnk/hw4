#include <fstream>
#include <iostream>
#include <format>

void firstTask() {
    int result;
    std::ofstream numbersFile("test.txt");
    if(numbersFile.is_open()) {
        for (int i = 1; i <= 10; i++) {
            int num;
            std::cout << std::format("введите {}-е число: ", i);
            std::cin >> num;
            numbersFile << num << std::endl;
        }
    }
    else std::cout << "ошибка открытия файла, попробуйте еще раз!" << std::endl;
    numbersFile.close();

    std::ifstream file("test.txt");
    std::string line;
    while (std::getline(file, line)) {
        result+=std::stoi(line);
    }
    file.close();
    std::cout << std::format("сумма введенных чисел: {}", result) << std::endl;
}
