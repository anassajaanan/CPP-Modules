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

		AForm AForm("AForm", 42, 42);
		std::cout << AForm;

		bureaucrat.signAForm(AForm);
		
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;

		bureaucrat.signAForm(AForm);
		std::cout << AForm;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}