#include <cmath>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";
const std::string DARK_BLUE = "\033[38;5;19m";
void fifthTask() {
    const int width = 120;
    const int height = 25;
    double phase = 0.0;

    while (true) {
        system("clear");
        for (int y = 0; y < height; ++y) {
            double yValue = 1.0 - ((double)y / (height - 1)) * 2.0;
            for (int x = 0; x < width; ++x) {
                double xValue = ((double)x / (width - 1)) * 2.0 * M_PI + phase;
                double sineValue = sin(xValue);
                if (fabs(yValue - sineValue) < 0.05) {
                    if (sineValue > 0.4)
                        std::cout << "Z" << RESET;
                    else if (sineValue > -0.4)
                        std::cout << DARK_BLUE << "O" << RESET;
                    else if (sineValue > -1)
                        std::cout << RED << "V" << RESET;
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }

        phase += 0.01;

        usleep(1000);
    }
}
