#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main(void)
{
	try
	{
		Bureaucrat	bureaucrat("Anas", 20);
		std::cout << bureaucrat;
		
		// #=========== ShrubberyCreationForm =======#
		ShrubberyCreationForm	shrubbery("Home");
		std::cout << shrubbery;

		bureaucrat.signAForm(shrubbery);
		bureaucrat.executeAForm(shrubbery);

		// #=========== RobotmyRequestForm =======#
		RobotomyRequestForm	robotomy("Robot");
		std::cout << robotomy;

		bureaucrat.signAForm(robotomy);
		bureaucrat.executeAForm(robotomy);


		// #=========== PresidentialPardonForm =======#
		PresidentialPardonForm	presidential("President");
		std::cout << presidential;

		bureaucrat.signAForm(presidential);
		bureaucrat.executeAForm(presidential);
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0)
}