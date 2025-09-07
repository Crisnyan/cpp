#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
};

BitcoinExchange::~BitcoinExchange() {
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_csv(other.m_csv) {
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->m_csv = other.m_csv;
	return (*this);
};

BitcoinExchange::BitcoinExchange(char const *path) {
	std::ifstream		file(path);

	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	if (!getData())
		return ;

	readInput(file);

	file.close();
}

bool	BitcoinExchange::checkDate(int year, int month, int day) const {
	if (month < 1 || month > 12)
		return false;

	int	daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysMonth[1] = 29;

	if (day > daysMonth[month -1] || day < 1)
		return false;
	return true;
}

std::string	BitcoinExchange::getDate(std::string const &line) const {
	int	year, month, day;

	for (int i = 0; static_cast<size_t>(i) < line.size(); i++) {
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(line[i]))
			return std::cerr << "Error: bad input => " << line << std::endl, "";
	}
	if (line.size() != 10 || line[4] != '-' || line[7] != '-' )
		return std::cerr << "Error: bad input => " << line << std::endl, "";

	year = std::atoi(line.substr(0,4).c_str());
	month = std::atoi(line.substr(5,2).c_str());
	day = std::atoi(line.substr(8,2).c_str());

	if (!checkDate(year, month, day))
		return std::cerr << "Error: invalid date => " << line << std::endl, "";

	return line;
}

bool	BitcoinExchange::checkZero(std::string const &str) const {
	int		size = static_cast<int>(str.length());
	bool	point = false;
	
	for (int i = 0; i < size; i++) {
		if (str[i] == '0')
			continue ;
		else if (str[i] == '.' && !point)
			point = true;
		else
			return false;
	}
	return true;
}

double	BitcoinExchange::getValue(std::string const &line) const {
	double value = std::atof(line.c_str());

	if (line.empty() || (value == 0.0 && !checkZero(line)))
		return std::cerr << "Error: bad input => " << line << std::endl, -1;
	else if (value < 0)
		return std::cerr << "Error: not a positive number." << std::endl, -1;
	else if (value > 1000)
		return std::cerr << "Error: too large number." << std::endl, -1;
	return value;
}

bool	BitcoinExchange::getData() {
	std::ifstream	file("data.csv");
	std::string	line, date, rate;
	double		value;

	if (!file.is_open())
		return std::cerr << "Error: could not open data.csv!" << std::endl, false;

	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t	pos = line.find_first_of(',');
		date = line.substr(0, pos);
		rate = line.substr(pos + 1);
		
		date = getDate(date);
		value = std::atof(rate.c_str());
	
		if (date == "")
			return false;
		else if (value == 0.0 && !checkZero(rate))
			return std::cerr << "Error: bad input => " << line << std::endl, false;

		m_csv.insert(std::make_pair(date, value));
	}

	return true;
}

void	BitcoinExchange::readInput(std::ifstream &file) {
	std::string	line, date, token, val;
	double		value;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream iss(line);

		if (!(iss >> date >> token >> val) || !iss.eof() || token != "|") {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		date = getDate(date);
		value = getValue(val);
	
		if (date == "" || value == -1)
			continue ;
		
		printData(date, value);
	}
}

void	BitcoinExchange::printData(std::string str, double val) {
	std::cout << str << " => " << val << " = ";

	for (std::map<std::string, double>::iterator it = m_csv.begin(); it != m_csv.end(); it++) {
		std::map<std::string, double>::iterator last = it;
		last++;

		if (it == m_csv.begin() && it->first > str) {
			std::cout << 0 << std::endl;
			return ;
		}

		if (last == m_csv.end() || (it->first <= str && last->first > str)) {
			std::cout << it->second * val << std::endl;
			return ;
		}
	}
}
