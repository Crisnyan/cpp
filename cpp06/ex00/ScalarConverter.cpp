/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:59:03 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/02/24 17:54:29 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

#define IMP "impossible"

Type	parser(std::string str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;

	char	*end;

	std::strtol(str.c_str(), &end, 10);
	if (*end == '\0')
		return INT;

	if (str[str.length() - 1] == 'f' && str != "inf" && str != "-inf" && str != "+inf")
		str[str.length() - 1] = '\0';

	
	double	num2 = std::strtod(str.c_str(), &end);
	if (*end == '\0')
	{
		if (std::isnan(num2))
			return NAN_VAL;
		else if (std::isinf(num2))
			return INF;
		else 
			return DOUBLE;
	}
	return INVALID;
}

void	convertToDouble(double value, int type)
{
	std::cout << "double: ";
	std::cout << value;
	if (type != NAN_VAL && type != INF)
	{
		bool point = (std::floor(value) == value);
		if (point)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

void	convertToFloat(double value, int type)
{
	std::cout << "float: ";
	std::cout << value;
	if (type != NAN_VAL && type != INF)
	{
		bool point = (std::floor(value) == value);
		if (point)
			std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	convertToInt(double value, int type)
{
	std::cout << "int: ";
	if (type == INF || type == NAN_VAL || value > INT_MAX || value < INT_MIN)
		std::cout << IMP << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	convertToChar(double value, int type)
{
	std::cout << "char: ";
	if (value < 0 || value > 255 || type == INF || type == NAN_VAL)
		std::cout << IMP << std::endl;
	else if (value > 31 && value < 127)
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	size_t type = parser(str);
	
	if (type == INVALID)
	{
		std::cout << "Error: Invalid input!" << std::endl;
		return ;
	}

	double	value = std::strtod(str.c_str(), NULL);
	
	if (type == CHAR)
		value = static_cast<double>(str[0]);

	convertToChar(value, type);
	convertToInt(value, type);
	convertToFloat(value, type);
	convertToDouble(value, type);
	
}
