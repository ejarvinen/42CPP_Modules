/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:42:56 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 13:04:40 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(void)
{
	Array<int>			intA(5);
	Array<std::string>	strA(5);

	std::cout << "size of intArray: " << intA.size() << std::endl;
	std::cout << "size of strArray: " << strA.size() << std::endl;
	return (0);
}
