/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DerivedClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:15:59 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/06 12:22:05 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVEDCLASS_H
# define DERIVEDCLASS_H

# include "Data.hpp"

class DerivedClass : public Data {

	public:

		DerivedClass();
		DerivedClass(DerivedClass const &copy);
		~DerivedClass();
		DerivedClass	&operator=(DerivedClass const &other);

		void	printAddress() override;

};

#endif