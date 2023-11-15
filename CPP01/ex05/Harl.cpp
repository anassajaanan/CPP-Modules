#include "Harl.hpp"

int	getLevelNumber(std::string level)
{
	int i;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	return (i);
}

void	Harl::debug (void)
{
	std::cout << "(DEBUG): I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::infos (void)
{
	std::cout << "(INFO): I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning (void)
{
	std::cout << "(WARNING): I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error (void)
{
	std::cout << "(ERROR): This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::infos, &Harl::warning, &Harl::error};

	int levelNumber = getLevelNumber(level);

	if (levelNumber < 4)
		(this->*functions[levelNumber])();
	else
	 	std::cout << "Unknown complaint level: " << level << std::endl;
}