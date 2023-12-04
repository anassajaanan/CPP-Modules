#include "BitcoinExchange.hpp"
#include <exception>



int main()
{
	BitcoinExchange	btc;


	try
	{
		btc.loadDataBase();
		btc.displayDataBase();
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}