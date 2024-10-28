#include <iostream>
#include <format>
#include "../include/thirdTask.h"

int rectanglesArea();
double trianglesArea();
double circlesArea();

void thirdTask() {
    std::cout << "для какой фигуры рассчитать площадь?\n"
                 "прямоугольник - 1\n"
                 "треугольник - 2\n"
                 "круг - 3" << std::endl;
    int figure; std::cin >> figure;
    switch (figure) {
        case 1:
            std::cout << std::format("площадь прямоугольника равна: {}", rectanglesArea()) << std::endl;
        break;
        case 2:
            std::cout << std::format("площадь треугольника равна: {}", trianglesArea()) << std::endl;
        break;
        case 3:
            std::cout << std::format("площадь круга равна: {}", circlesArea()) << std::endl;
        break;
        default:
            std::cout << "неправильный номер фигуры!" << std::endl;
    }
}

int rectanglesArea() {
    std::cout << "введите 1-ю сторону прямоугольника: ";
    int s1; std::cin >> s1;
    std::cout << "введите 2-ю сторону прямоугольника: ";
    int s2; std::cin >> s2;
    return s1*s2;
}

double trianglesArea() {
    std::cout << "введите основание: ";
    int s1; std::cin >> s1;
    std::cout << "введите высоту, опущенную на основание: ";
    double height; std::cin >> height;
    return s1*height/2;
}

double circlesArea() {
    std::cout << "введите радиус круга: ";
    double s1; std::cin >> s1;
    return M_PI*pow(s1,2);
}