#include <iostream>

int main(int argc, char *argv[])
{
	std::string tmp;

	if(argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			tmp = argv[i];
			for(unsigned long j = 0; j < tmp.length(); j++)
				tmp[j] = std::toupper(tmp[j]);
			std::cout << tmp;
		}
		std::cout << std::endl;
	}
}
