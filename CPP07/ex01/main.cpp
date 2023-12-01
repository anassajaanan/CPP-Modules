#include "iter.hpp"
#include <iostream>


int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    int intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Printing integers: ";
    iter(intArray, intArrayLength, printValue<int>);
    
    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Printing doubles: ";
    iter(doubleArray, doubleArrayLength, printValue<double>);

    // Test with an array of characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    int charArrayLength = sizeof(charArray) / sizeof(char);

    std::cout << "Printing characters: ";
    iter(charArray, charArrayLength, printValue<char>);

	// Test with an array of strings
	std::string stringArray[] = {"Hello", "Anas,", "42", "is", "Awesome!"};
	int stringArrayLength = sizeof(stringArray) / sizeof(std::string);

	std::cout << "Printing strings: ";
	iter(stringArray, stringArrayLength, printValue<std::string>);

    return 0;
}