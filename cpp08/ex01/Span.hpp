#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	public:

		Span(unsigned int N);
		~Span();
		
		Span(Span const &other);
		Span	&operator=(Span const &other);

		void	addNumber();
		void	addNumber(int nbr);
		void	addNumbers(unsigned int size);
		void	addNumbers(unsigned int size, int nbr);

		int	shortestSpan();
		int	longestSpan();

	private:

		unsigned int		m_len;
		std::vector<int>	m_span;

		int	generateRandom();
};

#endif
