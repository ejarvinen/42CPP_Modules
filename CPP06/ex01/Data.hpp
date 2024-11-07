/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:11:27 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/07 12:16:45 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data {

	private:

		int	_dataInt;

	public:

		Data();
		Data(int dataInt);
		Data(Data const &copy);
		~Data();
		Data	&operator=(Data const &other);

		int	getInt();

};

#endif