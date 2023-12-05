

#pragma once
#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "list"
#include <vector>
#include <algorithm>
#include <chrono>

const int MAX_LIMIT = 5000;

class PmergeMe
{
private:
	std::vector<int>	vector;
	std::list<int>		list;
	std::chrono::duration<double, std::micro> vectorDuration;
	std::chrono::duration<double, std::micro> listDuration;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void				setVector(std::vector<int> &vector);
	void				setList(std::list<int> &list);
	std::vector<int>	&getVector();
	std::list<int>		&getList();

	void		printVector(std::string str);
	void		printList();

	void		insertionSortVector(std::vector<int> &vector, int start, int end);
	void		mergeVector(std::vector<int> &vector, int start, int mid, int end);
	void		mergeInsertionSortVector(std::vector<int> &vector, int start, int end);
	void		performMergeSortVector(std::vector<int> &vector);

	void		insertionSortList(std::list<int>::iterator start, std::list<int>::iterator end);
	void		mergeList(std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end);
	void		mergeInsertionSortList(std::list<int>::iterator start, std::list<int>::iterator end);
	void		performMergeSortList(std::list<int> &list);


	int			processInput(int argc, char **argv);
};








#endif // PMERGE_ME_HPP