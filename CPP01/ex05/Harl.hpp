/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:21:39 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/09 15:46:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>

class Harl
{
	private:
		
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		enum	Level {
				DEBUG,
				INFO,
				WARNING,
				ERROR,
				FAIL
		};

	public:

		Harl();
		~Harl();

		void		complain(std::string level);
		Harl::Level	convertLevel(std::string level);
};




#endif