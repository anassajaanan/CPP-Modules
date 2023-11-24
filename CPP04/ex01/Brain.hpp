

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>


class Brain
{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(std::string idea);
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	~Brain();


	void	displayIdeas() const;
};



#endif /* BRAIN_HPP */