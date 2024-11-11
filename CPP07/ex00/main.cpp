/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:01:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/11 12:21:22 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template <typename T>
void	swap(T param1, T param2)
{
	T temp;
	
	temp = param1;
	paramp1 = param2;
	param2 = temp;
}

template <typename T>
T	min(T param1, T param2)
{
	T res;

	res = (param1 < param2) ? param1 : param2;
	return (res);
}

template <typename T>
T	max(T param1, T param2)
{
	T res;

	res = (param1 > param2) ? param1 : param2;
	return (res);
}

int	main(void)
{
	return (0);
}