#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("DefaultTarget") { }

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), target(other.target) { }

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void	RobotomyRequestForm::execute(const Bureaucrat &other) const
{
	if (this->isFormSigned() == false)
		throw (FormNotSignedException());
	if (other.getGrade() > this->getExecuteGrade())
		throw (FormGradeTooLowException());
	
	std::cout << "🔧🔨 Some drilling noises..." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << "🤖 " << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "🚫 Robotomy failed for " << target << std::endl;

}