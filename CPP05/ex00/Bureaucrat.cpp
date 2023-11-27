#include "Bureaucrat.hpp"
#include <exception>

const char	*GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) { }

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) { }


Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }


std::string	Bureaucrat::getName() const
{
	return (name);
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
		throw (GradeTooHighException());
}

void	Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
		throw(GradeTooLowException());
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}
