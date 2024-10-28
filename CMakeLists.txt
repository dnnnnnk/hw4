cmake_minimum_required(VERSION 3.29)
project(hw_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(hw_4 main.cpp
        src/firstTask.cpp
        src/secondTask.cpp
        src/thirdTask.cpp
        src/fourthTask.cpp
        src/fifthTask.cpp
        include/firstTask.h
        include/secondTask.h
        include/thirdTask.h
        include/fourthTask.h
        include/fifthTask.h
        src/runTasks.cpp
        include/runTasks.h
        src/sixthTask.cpp
        include/sixthTask.h
        src/seventhTask.cpp
        include/seventhTask.h
        src/eighthTask.cpp
        include/eighthTask.h
        src/ninthTask.cpp
        include/ninthTask.h
)
