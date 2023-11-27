#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>



int main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Anas", 44);
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		Form form("form", 42, 42);
		std::cout << form;

		bureaucrat.signForm(form);
		
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}