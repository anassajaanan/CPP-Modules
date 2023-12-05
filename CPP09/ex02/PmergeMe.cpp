#include "PmergeMe.hpp"
#include <cctype>
#include <chrono>
#include <iterator>
#include <list>
#include <vector>



PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vector = other.vector;
		this->list = other.list;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }

void		PmergeMe::setVector(std::vector<int> &vector) { this->vector = vector; }

void		PmergeMe::setList(std::list<int> &list) { this->list = list; }

std::vector<int>	&PmergeMe::getVector() { return (this->vector); }

std::list<int>		&PmergeMe::getList() { return (this->list); }




int		PmergeMe::processInput(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe [number1] [number2] [number3] ..." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (std::isalpha(argv[i][j]))
			{
				std::cout << "Error: non-numeric character" << std::endl;
				return (1);
			}
		}
		std::string	inputStr(argv[i]);
		std::istringstream iss(inputStr);
		int num;
		while (iss >> num)
		{
			if (num < 0)
			{
				std::cout << "Error: negative number" << std::endl;
				return (1);
			}
			this->vector.push_back(num);
			this->list.push_back(num);
		}
	}
	if (this->vector.size() == 0)
	{
		std::cout << "Error: no numbers" << std::endl;
		return (1);
	}
	if (this->vector.size() == 1)
	{
		std::cout << "Error: only one number" << std::endl;
		return (1);
	}
	if (this->vector.size() > MAX_LIMIT)
	{
		std::cout << "Error: too many numbers" << std::endl;
		return (1);
	}

	return (0);
}

void	PmergeMe::insertionSortVector(std::vector<int> &vec, int start, int end)
{
	for (int i = 0; i < end - start; i++)
	{
		int j = i + 1 + start;
		int targetToBeInserted = vec[j];
		while (j > start && vec[j - 1] > targetToBeInserted)
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = targetToBeInserted;
	}
}

void	PmergeMe::insertionSortList(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	for (std::list<int>::iterator start = begin; start != end; start++)
	{
		std::list<int>::iterator	tempIt = std::next(start);
		int	targetToBeInserted = *tempIt;
		while (tempIt != begin && *(std::prev(tempIt)) > targetToBeInserted)
		{
			*tempIt = *(std::prev(tempIt));
			tempIt--;
		}
		*tempIt = targetToBeInserted;
	}
}

void	PmergeMe::mergeVector(std::vector<int> &vec, int start, int mid, int end)
{
	std::vector<int>	tmpVector;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (vec[i] < vec[j])
			tmpVector.push_back(vec[i++]);
		else
			tmpVector.push_back(vec[j++]);
	}
	while (i <= mid)
		tmpVector.push_back(vec[i++]);
	while (j <= end)
		tmpVector.push_back(vec[j++]);
	for (int i = 0; i < (int)tmpVector.size(); i++)
	{
		vec[start + i] = tmpVector[i];
	}
}


void	PmergeMe::mergeList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end)
{
	std::list<int>	tmpList;

	std::list<int>::iterator	i = start;
	std::list<int>::iterator	j = std::next(mid);
	while (i != std::next(mid) && j != std::next(end))
	{
		if (*i < *j)
			tmpList.push_back(*i++);
		else
			tmpList.push_back(*j++);
	}
	while (i != std::next(mid))
		tmpList.push_back(*i++);
	while (j != std::next(end))
		tmpList.push_back(*j++);
	std::list<int>::iterator	tmpIt = tmpList.begin();
	while (start != std::next(end))
	{
		*start = *tmpIt;
		start++;
		tmpIt++;
	}
}

// Ford-Johnson algorithm.
void	PmergeMe::mergeInsertionSortVector(std::vector<int> &vec, int start, int end)
{
	if (end - start < 16)
	{
		insertionSortVector(vec, start, end);
		return ;
	}
	int mid = (end + start) / 2;
	mergeInsertionSortVector(vec, start, mid);
	mergeInsertionSortVector(vec, mid + 1, end);
	mergeVector(vec, start, mid, end);
}

// Ford-Johnson algorithm.
void	PmergeMe::mergeInsertionSortList(std::list<int>::iterator start, std::list<int>::iterator end)
{
	if (std::distance(start, end) < 16)
	{
		insertionSortList(start, end);
		return ;
	}
	std::list<int>::iterator	mid = std::next(start, std::distance(start, end) / 2);
	mergeInsertionSortList(start, mid);
	mergeInsertionSortList(std::next(mid), end);
	mergeList(start, mid, end);
}

void	PmergeMe::performMergeSortVector(std::vector<int> &vec)
{
	printVector(std::string("Before: "));

	// start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortVector(vec, 0, vec.size() - 1);
	// end time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// calculate duration
	this->vectorDuration = end - start;

	printVector(std::string("After: "));

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vectorDuration.count() << " us" << std::endl;
}

void	PmergeMe::performMergeSortList(std::list<int> &list)
{
	// start time
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	mergeInsertionSortList(list.begin(), std::prev(list.end()));
	// end time
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	// calculate duration
	this->listDuration = end - start;

	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << listDuration.count() << " us" << std::endl;
}



void	PmergeMe::printVector(std::string word)
{
	std::cout << std::endl << "==========================" << std::endl << std::endl;
	std::cout << word;
	for (int i = 0; i < (int)vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl << std::endl;
}


void	PmergeMe::printList()
{
	std::cout << "List: ";
	std::list<int>::iterator	it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}