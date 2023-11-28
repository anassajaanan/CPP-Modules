#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



int main(void)
{
	try
	{
		Intern someRandomIntern;

		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}