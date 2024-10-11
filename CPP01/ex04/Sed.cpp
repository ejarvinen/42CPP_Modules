/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:19:35 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/11 09:49:20 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	moc_replace(std::string *line, std::string s1, std::string s2)
{
	size_t	pos;

	pos = (*line).find(s1);
	while (pos != std::string::npos)
	{
		(*line).erase(pos, s1.length());
		(*line).insert(pos, s2);
		pos = (*line).find(s1);
	}
}

int	sed(char *argv[])
{
	std::string		line;
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
	while (getline(inFile, line))
	{
		if (!s1.empty() && s1.compare(s2) != 0)
			moc_replace(&line, s1, s2);
		outFile << line;
		outFile << std::endl;
	}
	inFile.close();
	outFile.close();
	return (0);
}
