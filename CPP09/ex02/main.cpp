#include <iostream>
#include <string>
#include <vector>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


void	insertionSort(std::vector<int> &vec, int start, int end)
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

// void	insertionSort(std::vector<int> &vec)
// {
// 	for (int i = 0; i < (int)vec.size() - 1; i++)
// 	{
// 		int	j = i + 1;
// 		int targetToInsert = vec[j];
// 		while (j > 0 && vec[j - 1] > targetToInsert)
// 		{
// 			vec[j] = vec[j - 1];
// 			j--;
// 		}
// 		vec[j] = targetToInsert;
// 	}
// }


int main()
{
	std::vector<int> vec {9,5,2,10,0,8,4,1,7,3};

	insertionSort(vec, 0, 4);

	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";

	std::cout << std::endl;

	insertionSort(vec, 5, 9);

	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";

	insertionSort(vec, 0, 9);	

	std::cout << std::endl;

	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";
}