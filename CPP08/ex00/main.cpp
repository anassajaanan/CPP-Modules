#include "easyfind.hpp"
#include <array>
#include <exception>
#include <list>
#include <vector>
#include <deque>

void testEasyFindOnVector()
{
	std::vector<int>	vec;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	std::cout << "============ Test on Vector ============\n";
	
	try
	{
		it = easyFind(vec, 5);
		std::cout << *it << " Found" << std::endl;
		it = easyFind(vec, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}


void	testEasyFindOnDeque()
{
	std::deque<int>	deque;
	std::deque<int>::iterator it;

	for (int i = 0; i < 10; i++)
		deque.push_back(i);
	
	std::cout << "============ Test on Deque ============\n";
	try
	{
		it = easyFind(deque, 5);
		std::cout << *it << " Found" << std::endl;
		it = easyFind(deque, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testEasyFindOnList()
{
	std::list<int>	myList;
	std::list<int>::iterator it;

	for (int i = 0; i < 10; i++)
		myList.push_back(i);

	std::cout << "============ Test on List ============\n";
	try
	{
		it = easyFind(myList, 5);
		std::cout << *it << " Found" << std::endl;
		it = easyFind(myList, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	
	}
}

int main()
{
	testEasyFindOnVector();
	testEasyFindOnDeque();
	testEasyFindOnList();
}