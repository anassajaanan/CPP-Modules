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
		PhoneBook();
		int		getNumOfContacts();
		void	addNewContact(Contact contact);

		Contact	createContact();
		void	printTableHeader();
		void	printContact(int index);
		void 	printTableFooter();

		void	printContactDetails(int selectedIndex);

};

#endif