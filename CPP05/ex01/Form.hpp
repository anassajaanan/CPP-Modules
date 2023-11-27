

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class FormGradeTooHighException : public std::exception
{
public:
	const char	*what() const throw();
};

class FormGradeTooLowException : public std::exception
{
public:
	const char	*what() const throw();
};


class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			executeGrade;

public:
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &other);
	Form	&operator=(const Form &other);
	~Form();

	void	beSigned(const Bureaucrat &other);

	std::string	getName() const;
	bool		isFormSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

};



std::ostream	&operator<<(std::ostream &os, const Form &other);



#endif /* FORM_HPP */