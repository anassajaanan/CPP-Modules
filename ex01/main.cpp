#include <iostream>
#include <string>
#include <limits>
#include "Contact.hpp"
# include "PhoneBook.hpp"


void	printMenu()
{
	std::cout << "Please select an option:" << std::endl;
    std::cout << "1️⃣ ADD 📝" << std::endl;
    std::cout << "2️⃣ SEARCH 🔍" << std::endl;
    std::cout << "3️⃣ EXIT 🚪" << std::endl;
    std::cout << "Enter your choice 💻: ";
}

int main()
{
	std::string	choice;
	PhoneBook	phoneBook;

	while (1)
	{
		printMenu();
		std::cin >> choice;
		std::cout << std::endl;
		if (choice.compare("ADD") == 0)
		{
			phoneBook.addNewContact(phoneBook.createContact());
			std::cout << std::endl;
		}
		else if (choice.compare("SEARCH") == 0)
		{
			if (phoneBook.getNumOfContacts() == 0)
			{
				std::cout << "No contacts found! 🤷‍♂️. Try adding some contacts first.\n\n";
				continue;
			}
			phoneBook.printTableHeader();
			for (int i = 0; i < phoneBook.getNumOfContacts(); i++)
			{
				phoneBook.printContact(i);
			}
			phoneBook.printTableFooter();
			std::cout << std::endl;

			while (true)
			{
				int			selectedIndex;

				std::cout << "Enter the index of the entry to display: ";

				if (std::cin >> selectedIndex)
				{
					if (selectedIndex >= 0 && selectedIndex < phoneBook.getNumOfContacts())
					{
						phoneBook.printContactDetails(selectedIndex);
						break;
					}
					else
					{
						std::cout << "    ❌ Invalid index. Please enter a valid index. ❌" << std::endl;
					}
				}
				 else
				{
					// Clear the error flags and discard the invalid input
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "    ❌ Invalid input. Please enter a valid index. ❌" << std::endl;
				}
			}
		}
		else if (choice.compare("EXIT") == 0)
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid input ❌" << std::endl << std::endl;
	}
}