#include <iostream>
void fourthTask() {
    // звезды 8х6 13 линий
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << "*  ";
        }
        for(int k = 0; k < 31; k++) {
            std::cout << "⎻⎻";
        }
        std::cout << std::endl;
    }
    for (int m = 0; m < 7; m++) {
        for (int n = 0; n < 83; n++) {
            std::cout << "⎻";
        }
        std::cout << std::endl;
    }
}
