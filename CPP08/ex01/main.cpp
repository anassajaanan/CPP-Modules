

#include "Span.hpp"



int main()
{
    try
    {
        // Create a Span instance with a capacity of 10,000
        Span sp(10000);

        // Fill the Span with random numbers between 1 and 1000
        sp.fillVector(1, 10000);

        // Print the first 10 elements for reference
        sp.printVector();

        // Find and print the shortest and longest spans
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}