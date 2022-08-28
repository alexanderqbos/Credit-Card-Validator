#include <iostream>
#include <fstream>
#include "credit.h"

int main()
{
    // DEBUG FUNCTIONS
    // int digitSum = getSumOfDigits(123);
    // std::cout << digitSum << " expected 6\n";
    // std::string cardNum = "4012888888881881";
    // bool validPrefix = hasValidPrefix(cardNum);
    // std::cout << validPrefix << " expected 1(true)\n";
    // if(isValid(cardNum))
    // {
    //     std::cout << "Card is valid\n";
    // }
    // else {
    //     std::cout << "Card is invalid\n";
    // }

    std::string fileName = "cards.txt";
    std::ifstream fileIn;
    fileIn.open(fileName);
    if(fileIn.is_open())
    {
        std::cout << "File opened!\n";
        std::string cardNumber;
        while(fileIn >> cardNumber)
        {
            std::cout << cardNumber << ", valid: " << isValid(cardNumber) << "\n";
        }
    } else {
        std::cout << "File failed to open!\n";
    }

    return 0;
}