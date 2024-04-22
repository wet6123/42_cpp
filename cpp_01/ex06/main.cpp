#include "Harl.hpp"

int main(int argc, char* argv[])
{
	Harl	harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
}
