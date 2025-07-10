#include <iostream>

int	main(int ac, char *av[])
{
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < ac; i++)
		{
			std::string arg(av[i]);
			for (j = 0; j < (int)arg.length(); j++)
				arg[j] = toupper(arg[j]);
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return (0);
}