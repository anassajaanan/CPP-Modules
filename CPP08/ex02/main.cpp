#include "MutantStack.hpp"


int main()
{
    try
    {
        MutantStack<int> mstack;


        mstack.push(10);
        mstack.push(20);
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;


        mstack.push(30);
        mstack.push(40);
        mstack.push(50);
        mstack.push(60);

    
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

        // Test conversion to std::stack
        std::stack<int> s(mstack);

        // Clear the MutantStack
        while (!mstack.empty())
			mstack.pop();

        // Test edge cases
        std::cout << "Size after clear: " << mstack.size() << std::endl;
        mstack.push(100);
        std::cout << "Size after push: " << mstack.size() << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
