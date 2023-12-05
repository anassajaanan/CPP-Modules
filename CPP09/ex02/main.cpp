#include "PmergeMe.hpp"
#include <list>
#include <string>
#include <iterator>

int	getNumbersBetweenIterators(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	int	count = 0;
	while (begin != end)
	{
		begin++;
		count++;
	}
	return (count);

}



int main(int argc, char **argv)
{
	PmergeMe	pmergeMe;

	if (pmergeMe.processInput(argc, argv))
		return (1);
	
	pmergeMe.performMergeSortVector(pmergeMe.getVector());
	pmergeMe.performMergeSortList(pmergeMe.getList());

	return (0);

}