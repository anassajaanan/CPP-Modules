#include <iostream>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	numOfContacts = 0;
}

int	PhoneBook::getNumOfContacts()
{
	return (numOfContacts);
}

void	PhoneBook::addNewContact(Contact contact)
{
	if (numOfContacts < 8)
	{
		contacts[numOfContacts] = contact;
		numOfContacts++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = contact;
	}
}

Contact PhoneBook::createContact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "First Name: ";
	std::getline(std::cin >> std::ws, firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin >> std::ws, lastName);
	std::cout << "Nick Name: ";
	std::getline(std::cin >> std::ws, nickName);
	std::cout << "Phone Number: ";
	std::getline(std::cin >> std::ws, phoneNumber);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin >> std::ws, darkestSecret);

	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	return (newContact);
}

void	PhoneBook::printContact(int index)
{
	std::cout << "First Name: " << contacts[index].getFirstName();
	std::cout << ", Last Name: " << contacts[index].getLastName();
	std::cout << ", Nick Name: " << contacts[index].getNickName();
	std::cout << ", Phone Number: " << contacts[index].getPhoneNumber();
	std::cout << ", Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
}