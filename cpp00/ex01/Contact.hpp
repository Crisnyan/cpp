#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
public:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_darkest_secret;
	int			m_phone_number;
	Contact()
	{
		m_first_name = "";
		m_last_name = "";
		m_nickname = "";
		m_darkest_secret = "";
		m_phone_number = 0;
	}
};

void	print(std::string text);
int	is_number(const char *str);
int	has_chars(const char *str);
void set_null(std::string& buffer);
#endif
