#include <iostream>
#include <ctype.h>

void	megaphone(int argc, char *argv[])
{
	int				arg;
	int				index;
	unsigned char	chr;

	if (argc < 2)
	{
		std::cout << "Not enough arguments\n";
		return ;
	}
	for (arg = 1; arg < argc; arg++)
	{
		for (index = 0; argv[arg][index]; index++)
		{
			chr = argv[arg][index];
			if (std::isalpha(chr))
			{
				chr = std::toupper(chr);
			}
			std::cout << chr;
		}
	}
	std::cout << "\n";
}

int	main(int argc, char *argv[])
{
	megaphone(argc, argv);
	return (0);
}
