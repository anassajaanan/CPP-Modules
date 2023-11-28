

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void	execute(const Bureaucrat &executor) const;
};





#endif /* SHRUBBERYCREATIONFORM_HPP */