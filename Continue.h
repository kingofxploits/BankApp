#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
#include "Typewriter.h"
template<typename T>
void Continue(T string) {
    srand(time(NULL));
    int cursorPos{ 0 };
    std::vector<std::string> message;
    message.push_back(string);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    for (int i{ 0 }; i < message.size(); i++) {
        if (i == cursorPos) {
            //Change color and display
            int randomColor = 1 + rand() % 15;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), randomColor); // change text color to random
            std::cout << "\n\n\t\t\t\t";
            TypeWriter(message[i], 30);
            std::cout << std::endl;
        } //end if
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // change text color to normal
    } //end forloop
}//end Continue()