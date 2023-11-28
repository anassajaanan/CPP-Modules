

#pragma once
#ifndef AForm_HPP
# define AForm_HPP

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


class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			executeGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm	&operator=(const AForm &other);
	~AForm();

	void	beSigned(const Bureaucrat &other);

	std::string	getName() const;
	bool		isFormSigned() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

};



std::ostream	&operator<<(std::ostream &os, const AForm &other);



#endif /* AForm_HPP */