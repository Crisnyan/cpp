#include "Harl.hpp"

Harl::Harl() {
	m_lvl[DEBUG] = "DEBUG";
	m_lvl[INFO] = "INFO";
	m_lvl[WARNING] = "WARNING";
	m_lvl[ERROR] = "ERROR";
	m_ptrlvl[DEBUG] = &Harl::m_debug;
	m_ptrlvl[INFO] = &Harl::m_info;
	m_ptrlvl[WARNING] = &Harl::m_warning;
	m_ptrlvl[ERROR] = &Harl::m_error;
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::m_debug(void) {
	std::cout << "HARL DEBUG" << std::endl;
}

void Harl::m_info(void) {
	std::cout << "HARL INFO" << std::endl;
}

void Harl::m_warning(void) {
	std::cout << "HARL WARNING" << std::endl;
}

void Harl::m_error(void) {
	std::cout << "HARL ERROR" << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (m_lvl[i] == level) {
			(this->*m_ptrlvl[i])();
			return ;
		}
	}
	std::cout << "HARL MUMBLING" << std::endl;
}
