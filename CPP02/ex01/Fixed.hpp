/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:38:42 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/11 17:04:04 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

	private:

		int					value;
		static const int	fbits = 8;

	public:

		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int param);
		Fixed(const float param);
		~Fixed();
		Fixed&	operator=(const Fixed &overloadCopy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif