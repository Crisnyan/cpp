/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:39:35 by adrmarqu          #+#    #+#             */
/*   Updated: 2025/04/21 14:25:12 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>

class PmergeMe{
public:

	PmergeMe(char **input);
	PmergeMe(std::string input);
	~PmergeMe();

private:

	std::string	m_input;
	std::vector<unsigned int>		m_vector;
	std::deque<unsigned int>		m_deque;

	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe	&operator=(PmergeMe const &other);
	void	checkInput(std::string str);
	void	checkSign(std::string &str);
	void	display(double v, double d) const;
	void	handleProgram();

	template <typename T>
	void	setInsertionOrder(unsigned int n, T &jacob) {
		unsigned int	j0 = 0, j1 = 1;

		jacob.push_back(j0);
		while (j1 < n) {
			jacob.push_back(j1);
			unsigned int tmp = j1;
			j1 = j1 + 2 * j0;
			j0 = tmp;
		}
		if (jacob.size() > 2)
			jacob.erase(jacob.begin() + 1);
		for (unsigned int i = 0; i < n; i++)
			if (std::find(jacob.begin(), jacob.end(), i) == jacob.end())
				jacob.push_back(i);
	}

	template <typename T>
	double	sortAndTime(T &arr) {
		clock_t	start = clock();
		std::istringstream	iss(m_input);
		std::string			str;
		T					highers, lowers, jacob;

		while (iss >> str)
			arr.push_back(std::atoi(str.c_str()));
		if (arr.size() > 1) {
			for (unsigned int i = 0; i < arr.size() - 1; i += 2) {
				if (arr[i] > arr[i + 1]) {
					highers.push_back(arr[i]);
					lowers.push_back(arr[i + 1]);
				}
				else {
					highers.push_back(arr[i + 1]);
					lowers.push_back(arr[i]);
				}
			}
			if (arr.size() % 2)
				highers.push_back(arr.back());
			std::sort(lowers.begin(), lowers.end());
			setInsertionOrder(highers.size(), jacob);

			typename T::iterator	it;
			for (unsigned int i = 0; i < jacob.size(); i++) {
				unsigned int	val = highers[jacob[i]];
				it = std::lower_bound(lowers.begin(), lowers.end(), val);
				lowers.insert(it, val);
			}
			arr = lowers;
		}

		clock_t	end = clock();

		return static_cast<double>(end - start) / CLOCKS_PER_SEC * 10;
	}
};

#endif
