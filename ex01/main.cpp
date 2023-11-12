#include <iostream>
#include "Contact.hpp"
# include "PhoneBook.hpp"


void	printMenu()
{
	std::cout << "Please select an option:" << std::endl;
	std::cout << "1) ADD" << std::endl;
	std::cout << "2) SEARCH" << std::endl;
	std::cout << "3) EXIT" << std::endl;
}


int main()
{
	int	choice;
	

	PhoneBook phoneBook;
	
	while (1)
	{
		printMenu();
		std::cin >> choice;
		std::cout << std::endl;
		if (choice == 1)
		{
			phoneBook.addNewContact(phoneBook.createContact());
			std::cout << std::endl;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < phoneBook.getNumOfContacts(); i++)
			{
				std::cout << i << ") ";
				phoneBook.printContact(i);
			}
			std::cout << std::endl;
		}
		else if (choice == 3)
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}
	}


}