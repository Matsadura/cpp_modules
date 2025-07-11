#include <iostream>
#include <cctype>

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string arg;
		for (i = 1; i < ac; i++)
			arg += av[i];
		for (j = 0; j < (int)arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		std::cout << arg << std::endl;
	}
	return (0);
}