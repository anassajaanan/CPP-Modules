#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

const char	*FormGradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char	*FormGradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

AForm::AForm()
	: name("defaultAForm"), isSigned(false), signGrade(150), executeGrade(150) { }

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw (FormGradeTooHighException());
	if (signGrade > 150 || executeGrade > 150)
		throw (FormGradeTooLowException());
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(false), signGrade(other.signGrade), executeGrade(other.executeGrade) { }

AForm	&AForm::operator=(const AForm &other)
{
	isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm() { }

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::isFormSigned() const
{
	return (isSigned);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::getExecuteGrade() const
{
	return (executeGrade);
}

void	AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() <= signGrade)
		isSigned = true;
	else
	 	throw (FormGradeTooLowException());
}

std::ostream	&operator<<(std::ostream &os, const AForm &other)
{
	os	<< "AFormName: " << other.getName()
		<< ", AFormIsSigned: " << other.isFormSigned()
		<< ", AFormSignGrade: " << other.getSignGrade()
		<< ", AFormExecuteGrade: " << other.getExecuteGrade() << std::endl;
	return (os);
}