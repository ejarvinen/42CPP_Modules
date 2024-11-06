/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:21:11 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 12:22:49 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:

		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();
		Serializer	&operator=(Serializer const &other);
	
	public:

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
		
};

#endif