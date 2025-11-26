#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "usage: ./harlv2 'LEVEL'\n";
		return (1);
	}

	Harl harlv2;

	std::string arg = std::string(av[1]);
	harlv2.complain(arg);
	return (0);
}