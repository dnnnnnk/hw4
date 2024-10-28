//
// Created by yrt on 18.10.24.
//

#include <iostream>
#include "../include/firstTask.h"
#include "../include/secondTask.h"
#include "../include/thirdTask.h"
#include "../include/fourthTask.h"
#include "../include/fifthTask.h"
#include "../include/sixthTask.h"
#include "../include/seventhTask.h"
#include "../include/eighthTask.h"
#include "../include/ninthTask.h"

void runTasks() {
    while (true) {
        std::cout << "введите номер задания (для завершения 0): ";
        int taskNum;
        std::cin >> taskNum;
        if (taskNum == 0) break;
        switch (taskNum) {
            case 1:
                firstTask();
            break;
            case 2:
                secondTask();
            break;
            case 3:
                thirdTask();
            break;
            case 4:
                fourthTask();
            break;
            case 5:
                fifthTask();
            break;
            case 6:
                sixthTask();
            break;
            case 7:
                seventhTask();
            break;
            case 8:
                eighthTask();
            break;
            case 9:
                ninthTask();
            break;
            default:
                std::cout << "неправильный номер задания!" << std::endl;
            break;
        }
    }
}

