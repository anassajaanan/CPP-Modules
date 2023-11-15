

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>


class Harl
{
private:
	void	debug(void);
	void	infos(void);
	void	warning(void);
	void	error(void);

public:
	void	complain(std::string level);

};


int	getLevelNumber(std::string level);

#endif // HARL_HPP