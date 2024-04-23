#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char **argv)
{
	std::ifstream		fin;
	std::ofstream		fout;
	std::string			filename;
	char				tmp;
	std::ostringstream	oss;
	std::string			final_str;
	std::string			tmp_str;
	int					idx;
	int					str_len;

	if (argc != 4)
	{
		std::cout << "Error: Wrong input." << std::endl;
		return (0);
	}

	filename = argv[1];
	filename.append(".replace");

	fin.open(argv[1]);
	fout.open(filename.c_str());

	while(fin.get(tmp))
		oss << tmp;

	final_str = oss.str();

	str_len = strlen(argv[2]);
	while (final_str.find(argv[2]) != std::string::npos)
	{
		idx = final_str.find(argv[2]);
		tmp_str = final_str.substr(0, idx);
		tmp_str.append(argv[3]);
		tmp_str.append(final_str.substr(idx + str_len));
		final_str = tmp_str;
	}

	fout << final_str;

	fin.close();
	fout.close();
}
