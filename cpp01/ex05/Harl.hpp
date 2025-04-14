#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

enum e_lvl {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl {
private:
	void m_debug(void);
	void m_info(void);
	void m_warning(void);
	void m_error(void);
	std::string m_lvl[4];
	void (Harl::*m_ptrlvl[4])(void);
public:
	Harl();
	~Harl();
	void complain(std::string level);
};
#endif
