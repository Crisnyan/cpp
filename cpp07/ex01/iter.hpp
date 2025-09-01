#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(const T *addr, const size_t len, void(*f)(T)) {
	for (size_t i = 0; i < len; ++i) {
		f(addr[i]);
	}
}

#endif
