#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG\n";
}

void Harl::info(void)
{
	std::cout << "INFO\n";
}

void Harl::warning(void)
{
	std::cout << "WARNING\n";
}

void Harl::error(void)
{
	std::cout << "ERROR\n";
}

void Harl::complain(std::string level)
{
	const std::string func[4] = {"debug", "info", "warning", "error"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for(int i = 0; i < 4; i++)
	{
		if (func[i] == level)
		{
			(this->*f[i])();
		}
	}
}
