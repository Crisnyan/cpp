#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>

int main() {

	std::cout << std::endl;
	std::cout << "Base span:" << std::endl;
	try {
		Span sp = Span(5);
	
		std::cout << "Span:" << std::endl;
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "More numbers than size:" << std::endl;
	try
	{
		Span	sp = Span(10);
		
		std::cout << "Span:" << std::endl;
		sp.addNumbers(11);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Big span:" << std::endl;
	try
	{
		Span	sp = Span(10000);
		
		std::cout << "Span:" << std::endl;
		//sp.addNumbers(10000);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "No parameters:" << std::endl;
	try
	{
		Span	sp = Span(10);
		
		std::cout << "Span:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "One parameter:" << std::endl;
	try
	{
		Span	sp = Span(10);
		
		std::cout << "Span:" << std::endl;
		sp.addNumber(1000);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Same parameters:" << std::endl;
	try
	{
		Span	sp = Span(10);
		
		std::cout << "Span:" << std::endl;
		sp.addNumbers(10, 0);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Copy: " << std::endl;
	try {
		Span	sp = Span(10);

		sp.addNumbers(10, 5);

		Span	span(sp);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Assignment: " << std::endl;

	try {
		Span	sp = Span(10);

		sp.addNumbers(10, 5);

		Span	span = sp;
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}
