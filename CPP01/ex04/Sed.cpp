/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:35 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/14 17:56:00 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	moc_replace(std::string *buffer, std::string s1, std::string s2)
{
	size_t	pos;

	pos = (*buffer).find(s1);
	while (pos != std::string::npos)
	{
		(*buffer).erase(pos, s1.length());
		(*buffer).insert(pos, s2);
		pos = (*buffer).find(s1, pos + s2.length());
	}
}

int	sed(char *argv[])
{
	char			chr;
	std::string		buffer;
	std::string		s1;
	std::string		s2;
	std::string		outfileName = argv[1];
	std::ifstream	inFile(argv[1]);
	std::ofstream	outFile(outfileName.append(".replace"));

	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cout << "Error opening files" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	while (!inFile.eof() && inFile >> std::noskipws >> chr) 
	{
		buffer += chr;
	}
	if (!s1.empty() && s1.compare(s2) != 0)
		moc_replace(&buffer, s1, s2);
	outFile << buffer;
	inFile.close();
	outFile.close();
	return (0);
}
