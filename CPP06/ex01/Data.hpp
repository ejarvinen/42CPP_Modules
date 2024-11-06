/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:11:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 12:21:51 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data {

	public:

		Data();
		Data(Data const &copy);
		virtual ~Data();
		Data	&operator=(Data const &other);

		virtual void	printAddress() = 0;

};

#endif