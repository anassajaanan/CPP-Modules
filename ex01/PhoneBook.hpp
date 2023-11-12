#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <string>
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
		void	printContact(int index);

};

#endif