/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:35 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/08 17:57:30 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	replace(std::string *line, std::string original, std::string replacement)
{
	size_t	pos;

	pos = (*line).find(original);
	while (pos != std::string::npos)
	{
		(*line).erase(pos, original.length());
		(*line).insert(pos, replacement);
		pos = (*line).find(original);
	}
}

int	sed(char *argv[])
{
	std::ifstream	inFile(argv[1]);
	std::string		outfileName = argv[1];
	std::ofstream	outFile(outfileName.append(".replace"));
	std::string		line;

	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cout << "Error opening files" << std::endl;
		return (1);
	}
	while (getline(inFile, line))
	{
		replace(&line, argv[2], argv[3]);
		outFile << line;
	}
	inFile.close();
	outFile.close();
	return (0);
}
