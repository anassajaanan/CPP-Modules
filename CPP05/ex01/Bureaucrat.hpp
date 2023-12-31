

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class GradeTooHighException : public std::exception
{
public:
	const char	*what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
	const char	*what() const throw();
};

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat	&operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signAForm(AForm &other);

};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &other);


#endif /* BUREAUCRAT_HPP */