#include "header.hpp"

/**
 * replace_str - Replaces all occurences of s1 with s2 in line
 * @s1: The string to search for
 * @s2: The string to replace with
 * @line: The string to search and replace in
 */
void	replace_str(const std::string& s1, const std::string& s2, std::string& line)
{
	std::size_t	s1_pos  = 0;

	if (s1.length() == 0)
		return;
	
	while (true)
	{
		s1_pos = line.find(s1, s1_pos);
		if (s1_pos != std::string::npos)
		{
			line.erase(s1_pos, s1.length());
			line.insert(s1_pos, s2);
		}
		else
			break;
		s1_pos += s2.length();
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2\n";
		return (1);
	}

	std::ifstream MyFile(av[1]);
	if (MyFile.is_open() == 0)
	{
		std::cerr << "Error opening file: " << av[1] << std::endl;
		return (1);
	}

	std::string	line;
	std::string outName = std::string(av[1]) + ".replace";
	std::ofstream MyOut(outName.c_str());
	if (MyOut.is_open() == 0)
	{
		std::cerr << "Error opening file: " << outName << std::endl;
		return (1);
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	while (std::getline(MyFile, line))
	{
		replace_str(s1, s2, line);
		MyOut << line << std::endl;
	}
	MyOut.close();
	return (0); 
}