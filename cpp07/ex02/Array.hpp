#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
	unsigned int	m_len;
	T 		*m_addr;
public:
	Array() : m_len(0), m_addr(new T[0]) {};
	~Array() {delete[] m_addr;};

	Array(unsigned int n) : m_len(n), m_addr(new T[n]) {
		for (unsigned int i = 0; i < m_len; ++i) {
			m_addr[i] = T();
		}
	};

	Array(const Array& other) : m_len(other.m_len), m_addr(new T[m_len]) {
		for (unsigned int i = 0; i < m_len; ++i) {
			m_addr[i] = other.m_addr[i];
		};
	};

	Array& operator=(const Array& other) {
	if (this != &other) {
		delete[] m_addr;
		m_len = other.m_len;
		m_addr = new T[m_len];
		for (unsigned int i = 0; i < m_len; ++i)
			m_addr[i] = other.m_addr[i];
		}
		return (*this);
	};

	T& operator[](int index) {
		if (index < 0 || (unsigned int)index >= m_len)
			throw(std::out_of_range("Out of bounds!"));
		return (m_addr[index]);
	};

	unsigned int size() {return (m_len);};
};

#endif
