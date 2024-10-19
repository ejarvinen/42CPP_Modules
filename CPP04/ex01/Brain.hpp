/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:34:57 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/19 15:45:19 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <string>
# include <iostream>

class Brain {

	protected:

		std::string	ideas[100];

	public:

		Brain();
		Brain(std::string ideas);
		Brain(const Brain &copy);
		~Brain();
		Brain&	operator=(const Brain &other);

};

#endif