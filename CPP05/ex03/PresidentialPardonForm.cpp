#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("DefaultTarget") { }

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), target(other.target) { }

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->isFormSigned() == false)
		throw (FormNotSignedException());
	if (executor.getGrade() > this->getExecuteGrade())
		throw (FormGradeTooLowException());

	std::cout << "📜 " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}