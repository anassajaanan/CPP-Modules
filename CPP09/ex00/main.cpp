#include "BitcoinExchange.hpp"
#include <exception>



int main(int argc, char **argv)
{
	BitcoinExchange	btc;

	if (argc != 2)
	{
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return (1);
	
	}

	try
	{
		btc.loadDataBase();
		btc.processInput(argv[1]);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}