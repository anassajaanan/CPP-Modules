#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

const char	*FormGradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*FormGradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

Form::Form()
	: name("defaultForm"), isSigned(false), signGrade(150), executeGrade(150) { }

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw (FormGradeTooHighException());
	if (signGrade > 150 || executeGrade > 150)
		throw (FormGradeTooLowException());
}

Form::Form(const Form &other)
	: name(other.name), isSigned(false), signGrade(other.signGrade), executeGrade(other.executeGrade) { }

Form	&Form::operator=(const Form &other)
{
	isSigned = other.isSigned;
	return (*this);
}

Form::~Form() { }

std::string	Form::getName() const
{
	return (name);
}

bool	Form::isFormSigned() const
{
	return (isSigned);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecuteGrade() const
{
	return (executeGrade);
}

void	Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= signGrade)
		isSigned = true;
	else
	 	throw (FormGradeTooLowException());
}

std::ostream	&operator<<(std::ostream &os, const Form &other)
{
	os	<< "FormName: " << other.getName()
		<< ", FormIsSigned: " << other.isFormSigned()
		<< ", FormSignGrade: " << other.getSignGrade()
		<< ", FormExecuteGrade: " << other.getExecuteGrade() << std::endl;
	return (os);
}