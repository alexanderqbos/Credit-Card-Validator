#include <string>

#ifndef CREDIT_H
#define CREDIT_H

// Given an int, return the sum of its individual digits
// eg: 123 would return 6
// hint: an easy way to parse an int into digits is using /10 and %10
int getSumOfDigits(int number);
// Returns true if the cardNumber starts with prefix
// Hint: research how the string.substr() function works.
bool startsWith(const std::string& cardNumber, const std::string& prefix);
// Returns true if the cardNumber startsWith() "4", "5", "37", or "6"
// hint:make use of startsWith()
bool hasValidPrefix(const std::string& cardNumber);
// Return sum of odd-place digits from right to left in the card
// number (step 1, part 3)
int sumOfOddPlaceRightToLeft (const std::string& cardNumber);
// Return the results from step 1, part 1 & 2
// hint: make use of getSumOfDigits()
int sumOfDoubleEvenPlaceRightToLeft (const std::string& cardNumber);
// Return true if the card number is valid
// (valid if it passes all tests including test for valid prefix)
// This is the "workhorse" function that co-ordinates all the others.
bool isValid(const std::string& cardNumber);


#endif