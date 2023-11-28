

#pragma once
#ifndef RobotomyRequestFORM_HPP
# define RobotomyRequestFORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void	execute(const Bureaucrat &executor) const;
};




#endif /* RobotomyRequestFORM_HPP */