#include "MutantStack.hpp"
#include <list>

int main() {
	MutantStack<int> ms;
	std::list<int> ls;

	std::cout << "Push 2 elements" << std::endl;
	ms.push(5);
	ls.push_back(5);
	ms.push(17);
	ls.push_back(17);

	std::cout << "Mutant stack: " << ms.top() << std::endl;
	std::cout << "List: " << ls.back() << std::endl;

	std::cout << std::endl;
	std::cout << "Pop last element" << std::endl;
	ms.pop();
	ls.pop_back();

	std::cout << "Mutant stack: " << ms.top() << std::endl;
	std::cout << "List: " << ls.back() << std::endl;

	std::cout << std::endl;
	std::cout << "Push 4 more elements" << std::endl;
	ms.push(3);
	ls.push_back(3);
	ms.push(5);
	ls.push_back(5);
	ms.push(737);
	ls.push_back(737);
	ms.push(0);
	ls.push_back(0);

	std::cout << std::endl;
	std::cout << "Size" << std::endl;
	std::cout << "Mutant stack: " << ms.size() << std::endl;
	std::cout << "List: " << ls.size() << std::endl;

	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator eit = ms.end();

	std::list<int>::iterator lit = ls.begin();
	std::list<int>::iterator leit = ls.end();

	++it;
	--it;
	++lit;
	--lit;

	std::cout << std::endl;
	std::cout << "Mutant stack: " << std::endl;
	while (it != eit) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::cout << "List: " << std::endl;
	while (lit != leit) {
		std::cout << *lit << std::endl;
		++lit;
	}
	std::stack<int> stk(ms);
	
	std::cout << std::endl;
	std::cout << "Stack assigned: " << std::endl;
	for (int i = 0; i < (int)ms.size(); ++i) {
		std::cout << "Stack " << ms.size() - i << ": " << stk.top() << std::endl;
		stk.pop();
	}

	return 0;
}
