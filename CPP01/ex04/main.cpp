/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:14:58 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/08 17:53:18 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (1);
	}
	return (sed(argv));
}
