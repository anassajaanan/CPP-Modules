#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	numOfContacts = 0;
}

int	PhoneBook::getNumOfContacts()
{
	return (numOfContacts);
}

void	PhoneBook::addNewContact(Contact &contact)
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

void	PhoneBook::printTableHeader()
{
	std::string	tableHeader[4] = {"Index", "First Name", "Last Name", "Nick Name"};

	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;
	for (int j = 0; j < 4; j++)
	{
		std::cout << '|';
		if (tableHeader[j].length() <= 10)
		{
			for (int i = 0; i < 10 - (int)tableHeader[j].length(); i++)
				std::cout << ' ';
			std::cout << tableHeader[j];
		}
		else
			std::cout << tableHeader[j].substr(0, 9) << '.';
	}
	std::cout << '|' << std::endl;
	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;
}

void	PhoneBook::printContact(int index)
{
	Contact	&contact = contacts[index];
	std::string	infos[4] = {std::to_string(index), contact.getFirstName(), contact.getLastName(), contact.getNickName()};
	for (int j = 0; j < 4; j++)
	{
		std::cout << '|';
		if (infos[j].length() <= 10)
		{
			for (int i = 0; i < 10 - (int)infos[j].length(); i++)
				std::cout << ' ';
			std::cout << infos[j];
		}
		else
			std::cout << infos[j].substr(0, 9) << '.';
	}
	std::cout << '|' << std::endl;
}

void	PhoneBook::printTableFooter()
{
	for (int i = 0; i < 45; i++)
		std::cout << '-';
	std::cout << std::endl;
}

void	PhoneBook::printContactTable()
{
	printTableHeader();
	for (int i = 0; i < numOfContacts; i++)
	{
		printContact(i);
	}
	printTableFooter();
	std::cout << std::endl;
}

void	PhoneBook::printContactDetails(int selectedIndex)
{
	Contact &selectedContact = contacts[selectedIndex];

	std::cout << std::endl;
	std::cout << "- First Name     : " << selectedContact.getFirstName() << std::endl;
    std::cout << "- Last Name      : " << selectedContact.getLastName() << std::endl;
    std::cout << "- Nickname       : " << selectedContact.getNickName() << std::endl;
    std::cout << "- Phone Number   : " << selectedContact.getPhoneNumber() << std::endl;
    std::cout << "- Darkest Secret : " << selectedContact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}