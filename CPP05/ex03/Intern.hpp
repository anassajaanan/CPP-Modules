

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>


class AForm;

class UnknownFormNameException : public std::exception
{
public:
	virtual const char	*what() const throw();
};

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);
	~Intern();


	AForm	*createShrubberyForm(std::string &target);
	AForm	*createRobotomyRequestForm(std::string &target);
	AForm	*createPresidentialPardonForm(std::string &target);

	AForm	*makeForm(std::string name, std::string target);
};

int	getFormIndex(std::string &name);

#endif /* INTERN_HPP */