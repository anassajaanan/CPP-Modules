#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

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
		// Constructors
		PhoneBook();

		// Accessors
		int		getNumOfContacts();

		// facilitators
		Contact	createContact();
		void	addNewContact(Contact &contact);

		void	printTableHeader();
		void	printContact(int index);
		void 	printTableFooter();
		void	printContactTable();

		void	printContactDetails(int selectedIndex);

};

#endif