#ifndef BITCOINEXCHANGE_HPP 
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> m_csv;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	bool	getData();
	void	readInput(std::ifstream &file);

	bool	checkDate(int year, int month, int day) const;
	bool	checkZero(std::string const &str) const;

	std::string	getDate(std::string const &line) const;
	double		getValue(std::string const &line) const;

	void		printData(std::string str, double val);
public:
	BitcoinExchange(char const *file);
	~BitcoinExchange();

	void init();
	double btc_val(std::pair<std::string, double>& date_val);
};
#endif
