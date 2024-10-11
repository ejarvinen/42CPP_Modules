/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:21:39 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/11 09:35:24 by emansoor         ###   ########.fr       */
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

		Harl::Level	convertLevel(std::string level);

	public:

		Harl();
		~Harl();

		void		complain(std::string level);
};

#endif