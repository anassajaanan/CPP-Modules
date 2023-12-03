

#include "Span.hpp"



int main()
{
    try
    {
        Span sp(100000);

        sp.fillVector(-100000, 100000);

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