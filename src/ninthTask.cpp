//
// Created by yrt on 21.10.24.
//
//
// #include <iostream>
// #include <vector>
//
// //сначала перевод в 10 путем умножения, потом число в 10 си переводим в нужное путем деления на это число (остатки)
//
// void convertToDexNum(int& num, const int& notationIN, const int& notationOUT);
//
// void ninthTask() {
//     std::cout << "какое число перевести? ";
//     int num; std::cin >> num;
//     std::cout << "из какой системы счисления? ";
//     int notationIN; std::cin >> notationIN;
//     std::cout << "в какую систему счисления? ";
//     int notationOUT; std::cin >> notationOUT;
//     convertToDexNum(num, notationIN, notationOUT);
//
// }
//
//
// // перевод из 10 в любую другую
// void convertToDexNum(int& num, const int& notationIN, const int& notationOUT) {
//     std::vector<int> newNum;
//     newNum.reserve(150);
//     while(num) {
//         newNum.insert(newNum.begin(), num%notationOUT);
//         num /= notationOUT;
//     }
//     for (int i = 0; i < newNum.size(); i++) {
//         std::cout << newNum[i];
//     }
//     std::cout << std::endl;
// }

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int charToValue(char c) {
    if (isdigit(c))
        return c - '0';
    return toupper(c) - 'A' + 10;
}

char valueToChar(int val) {
    if (val >= 0 && val <= 9)
        return '0' + val;
    return 'A' + (val - 10);
}

long long toDecimal(const string& number, int base) {
    long long decimal = 0;
    int len = number.length();
    for(int i = 0; i < len; ++i) {
        int value = charToValue(number[i]);
        decimal += value * pow(base, len - i - 1);
    }
    return decimal;
}

string fromDecimal(long long decimal, int base) {
    if(decimal == 0) return "0";
    string result = "";
    while(decimal > 0) {
        int remainder = decimal % base;
        result += valueToChar(remainder);
        decimal /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int ninthTask() {
    string number;
    int oldBase, newBase;

    cout << "введите число: ";
    cin >> number;
    cout << "введите старое основание системы счисления (2-16): ";
    cin >> oldBase;
    cout << "введите новое основание системы счисления (2-16): ";
    cin >> newBase;

    long long decimal = toDecimal(number, oldBase);

    string converted = fromDecimal(decimal, newBase);

    cout << "результат: " << converted << endl;

    return 0;
}
