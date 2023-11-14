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

void	handleAddContact(PhoneBook &phoneBook)
{
	Contact newContact;

	newContact = phoneBook.createContact();
	phoneBook.addNewContact(newContact);
	std::cout << std::endl;
}


int	getValidIndexFromUser(PhoneBook &phoneBook)
{
	int	selectedIndex;

	while (true)
	{
		std::cout << "Enter the index of the entry to display: ";
		if (std::cin >> selectedIndex)
		{
			if (selectedIndex >= 0 && selectedIndex < phoneBook.getNumOfContacts())
				return (selectedIndex);
			else
				std::cout << "    ❌ Invalid index. Please enter a valid index. ❌" << std::endl;
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

void	handleSearchContact(PhoneBook &phoneBook)
{
	int	selectedIndex;

	if (phoneBook.getNumOfContacts() == 0)
	{
		std::cout << "No contacts found! 🤷‍♂️. Try adding some contacts first.\n\n";
		return ;
	}
	phoneBook.printContactTable();
	selectedIndex = getValidIndexFromUser(phoneBook);
	phoneBook.printContactDetails(selectedIndex);
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
			handleAddContact(phoneBook);
		else if (choice.compare("SEARCH") == 0)
			handleSearchContact(phoneBook);
		else if (choice.compare("EXIT") == 0)
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid input ❌" << std::endl << std::endl;
	}
}
