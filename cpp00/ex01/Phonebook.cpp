#include <iostream>
#include <cstring>

void	print(std::string text)
{
	std::cout << text << std::endl;
}

int is_number(const char *str)
{
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	has_chars(const char *str)
{
	int	len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		if (isalpha(str[i]))
			return (1);
	}
	return (0);
}

void set_null(std::string& buffer)
{
		if (!has_chars(buffer.c_str()))
		{
			print("not alphanumeric string, set to None");
			buffer = "None";
		}
}

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

class PhoneBook
{
private:
	Contact m_contact[8];
public:
	int		i;

	PhoneBook()
	{
		i = 0;
	}

	void Add(int& i)
	{
		std::string	buffer;
		print("First name:");
		std::getline(std::cin, buffer);
		set_null(buffer);
		m_contact[i].m_first_name = buffer;
		print("Last name:");
		std::getline(std::cin, buffer);
		set_null(buffer);
		m_contact[i].m_last_name = buffer;
		print("Nickname:");
		std::getline(std::cin, buffer);
		set_null(buffer);
		m_contact[i].m_nickname = buffer;
		print("Phone number:");
		std::getline(std::cin, buffer);
		if (!is_number(buffer.c_str()) || buffer == "")
		{
			print("invalid number, number was set to 0");
			m_contact[i].m_phone_number = 0;
		}
		else if (buffer.size() > 10)
			print("number too long, set to 0");
		else
		{
			m_contact[i].m_phone_number = std::stoi(buffer);
		}
		print("Darkest secret:");
		std::getline(std::cin, buffer);
		set_null(buffer);
		m_contact[i].m_darkest_secret = buffer;
		print("Contact added!");
	}

	void PrintContact(const int i)	
	{
		int	size;
		std::cout << "         " << i << "|";
		size = m_contact[i].m_first_name.size();
		if (size < 11)
		{
			while (10 - size++)
				std::cout << " ";
			std::cout << m_contact[i].m_first_name << "|";
		}
		else
			std::cout << m_contact[i].m_first_name.substr(0, 9) << ".|";
		size = m_contact[i].m_last_name.size();
		if (size < 11)
		{
			while (10 - size++)
				std::cout << " ";
			std::cout << m_contact[i].m_last_name << "|";
		}
		else
			std::cout << m_contact[i].m_last_name.substr(0, 9) << ".|";
		size = m_contact[i].m_nickname.size();
		if (size < 11)
		{
			while (10 - size++)
				std::cout << " ";
			std::cout << m_contact[i].m_nickname;
		}
		else
			std::cout << m_contact[i].m_nickname.substr(0, 9) << ".";

	}

	void checkSpace(int& i)
	{
		for (int counter = 0; m_contact[i].m_first_name != ""; counter++)
		{
			i %= 8;
			if (counter == 9)
				return ;
			i++;
		}
		return ;
	}

	void PrintContacts(void)	
	{
		int	i;

		i = 0;
		print("     index|  first n.|   last n.|    nickn.");
		while (i < 8)
		{
			PrintContact(i);
			std::cout << std::endl;
			i++;
		}
	}

	void SearchContact(int target)
	{
		for (int i = -1; i < 8; ++i)
		{
			if (target > 7 || target < 0)
				print("invalid index");
			else if (target == i)
				this->PrintContact(i);
			else
				continue ;
		}
	}
	void Search(void)
	{
		std::string	target;

		PrintContacts();
		print("Select the user:");
		std::getline(std::cin, target);
		if (!is_number(target.c_str()) || target.size() > 1 || target == "")
			return (print("invalid index"));
		else
		{
			print("     index|  first n.|   last n.|    nickn.");
			SearchContact(std::stoi(target));
			std::cout << std::endl;
		}
	}
};

int	main(void)
{
	std::string buffer;
	PhoneBook	pb;

	while(1)
	{
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
		{
			pb.checkSpace(pb.i);
			pb.Add(pb.i);
		}
		if (buffer == "SEARCH")
			pb.Search();
		if (buffer == "EXIT")
			return (0);
	}
	return (0);
}
