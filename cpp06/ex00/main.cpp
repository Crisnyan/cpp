/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:05:06 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/02/18 14:11:37 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return std::cout << "Argument needed" << std::endl, 1;
	else if (argc > 2)
		return std::cout << "Maximum of one argument" << std::endl, 1;
	
	ScalarConverter::convert(argv[1]);
	
	return 0;
}
