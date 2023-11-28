#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char	*UnknownFormNameException::what() const throw()
{
	return ("Unknown form name");
}

Intern::Intern() { }

Intern::Intern(const Intern &other) { (void)other; }

Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() { }

AForm	*Intern::createShrubberyForm(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyRequestForm(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialPardonForm(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*(Intern::*functions[3])(std::string &_target) = {&Intern::createShrubberyForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	int	formIndex = getFormIndex(name);

	if (formIndex < 3)
	{
		std::cout << "Intern creates " << name << " form" << std::endl;
		return ((this->*functions[formIndex])(target));
	}
	else
	 	throw (UnknownFormNameException());
}

int	getFormIndex(std::string &name)
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int	i;
	for (i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			break;
	}
	return (i);
}