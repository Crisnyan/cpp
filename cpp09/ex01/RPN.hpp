/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:52:07 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/04/10 14:21:38 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>

#define NUM 0
#define TOKEN 1
#define ERROR 2

class RPN {
private:
	std::stack<int>	m_stk;
	int		m_token;

	RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);
	
	int whatIsThis(std::string const &str);
	void calculate();
	bool isToken(int c) const;
	void handleProgram(std::string const &str);
	void end(std::string const &str) const;
	bool OverflowPlus(int a, int b) const;
	bool OverflowMinus(int a, int b) const;
	bool OverflowMult(int a, int b) const;
public:
	RPN(char const *input);
	RPN(char **input);
	~RPN();

};

#endif
