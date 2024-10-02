#include <iostream>
#include <ctype.h>

/*
this shit is needed to print stuff to stdout with tailing newline:
std::cout << "whatever" << endl;  || how do we get it to print variables....?

std::cout << variableName;  || prints variableName to stdout

std::cout << "Some text here " << variableName << " some more text"; || apparently works too

*/

void	megaphone(int argc, char *argv[])
{
	int	arg;
	int	index;

	for (arg = 1; arg < argc; arg++)
	{
		for (index = 0; argv[arg][index]; index++)
		{
			if (isaplha(argv[arg][index]))
			{
				
			}
			std::cout << argv[index] << "\n";
		}
	}
}



int	main(int argc, char *argv[])
{
	megaphone(argc, argv);
	return (0);
}