#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string	darkestSecret;
	public:
		// Constructors
		Contact();
		Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSecret);

		// Mutators
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickName(std::string nickName);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);

		// Accessors
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		// faciliators
		
};



#endif