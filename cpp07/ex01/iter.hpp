#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(T *addr, size_t len, void(*f)(T&)) {
	if (!addr || !f)
		return ;
	for (size_t i = 0; i < len; ++i) {
		f(addr[i]);
	}
}

template <typename T> void iter(const T *addr, size_t len, void(*f)(const T&)) {
	if (!addr || !f)
		return ;
	for (size_t i = 0; i < len; ++i) {
		f(addr[i]);
	}
}

#endif
