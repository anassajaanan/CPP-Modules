
#pragma once
#ifndef __PHONE_BOOK_H__
# define __PHONE_BOOK_H__

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"



class PhoneBook
{
private:
	Contact	contacts[8];
	int	numOfContacts;
public:
	PhoneBook();

	int		getNumOfContacts();

	Contact	createContact();
	void	addNewContact(Contact &contact);
	
	void	printTableHeader();
	void	printContact(int index);
	void 	printTableFooter();
	void	printContactTable();

	void	printContactDetails(int selectedIndex);

};

#endif /* __PHONE_BOOK_H__ */