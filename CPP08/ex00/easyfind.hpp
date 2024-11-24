/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:41:59 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/24 14:06:45 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <iostream>

template <typename T>
void	easyfind(T &container, int findMe)
{
	if (container.empty())
		throw std::out_of_range("Can't perform search: container is empty");
	auto it = std::find(container.begin(), container.end(), findMe);
	if (it == container.end())
		throw std::out_of_range("Couldn't find the number");
	else
		std::cout << "Found " << findMe << std::endl;
}

#endif