#include "credit.h"

// Given an int, return the sum of its individual digits
// eg: 123 would return 6
// hint: an easy way to parse an int into digits is using /10 and %10
int getSumOfDigits(int number)
{
    int sum{0};
    if(number > 0)
    {
        sum += number%10;
    }
    if((number / 10) > 0)
    {
        sum += (number/10)%10;
    }
    if((number/100) > 0)
    {
        sum += (number/100)%10;
    }
    if((number/1000) > 0)
    {
        sum += (number/1000)%10;
    }
    return sum;
}
// Returns true if the cardNumber starts with prefix
// Hint: research how the string.substr() function works.
bool startsWith(const std::string& cardNumber, const std::string& prefix)
{
    int prefixLength = prefix.length();
    std::string cardPrefix = cardNumber.substr(0, prefixLength);
    if(cardPrefix == prefix)
    {
        return true;
    }
    return false;
}
// Returns true if the cardNumber startsWith() "4", "5", "37", or "6"
// hint:make use of startsWith()
bool hasValidPrefix(const std::string& cardNumber)
{
    std::string prefix[4]{"4","5","37","6"};

    if( startsWith(cardNumber, prefix[0]) ) {return true;}
    if( startsWith(cardNumber, prefix[1]) ) {return true;}
    if( startsWith(cardNumber, prefix[2]) ) {return true;}
    if( startsWith(cardNumber, prefix[3]) ) {return true;}
    return false;
}
// Return sum of odd-place digits from right to left in the card
// number (step 1, part 3)
int sumOfOddPlaceRightToLeft (const std::string& cardNumber)
{
    int oddSum = 0;
    for(int charIndex = cardNumber.length() - 1; charIndex >= 0; charIndex -= 2)
    {
        int temp = cardNumber[charIndex] - '0';
        oddSum += cardNumber[charIndex] - '0';
    }
    return oddSum;
}
// Return the results from step 1, part 1 & 2
// hint: make use of getSumOfDigits()
int sumOfDoubleEvenPlaceRightToLeft (const std::string& cardNumber)
{
    int doubleEvenSum = 0;
    for(int charIndex = cardNumber.length() - 2; charIndex >= 0; charIndex-=2)
    {
        int doubleValue = cardNumber[charIndex] - '0';
        doubleValue *= 2;
        if(doubleValue > 9)
        {
            doubleEvenSum += getSumOfDigits(doubleValue);
        } else {
            doubleEvenSum += doubleValue;
        }
    }
    return doubleEvenSum;
}
// Return true if the card number is valid
// (valid if it passes all tests including test for valid prefix)
// This is the "workhorse" function that co-ordinates all the others.
bool isValid(const std::string& cardNumber)
{
    if(hasValidPrefix(cardNumber))
    {
        int doubleEvenSum = sumOfDoubleEvenPlaceRightToLeft(cardNumber);
        int oddSum = sumOfOddPlaceRightToLeft(cardNumber);

        int finalSum = doubleEvenSum + oddSum;

        if((finalSum%10) == 0)
        {
            return true;
        }
    }
    return false;
}