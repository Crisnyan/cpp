#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact m_contact[8];
public:
	int		i;

	PhoneBook() {
		i = 0;
	}
	void Add(int& i);
	void PrintContact(const int i);
	void checkSpace(int& i);
	void PrintContacts(void);
	void SearchContact(int target);
	void Search(void);
};
#endif
