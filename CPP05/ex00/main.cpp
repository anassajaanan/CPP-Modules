#include "Bureaucrat.hpp"
#include <exception>



int main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Anas", 1);
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


}