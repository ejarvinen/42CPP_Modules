/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:01:28 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/23 12:35:50 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void	swap(T &param1, T &param2)
{
	T temp;
	
	temp = param1;
	param1 = param2;
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

#endif