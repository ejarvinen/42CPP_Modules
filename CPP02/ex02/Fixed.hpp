/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:38:42 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/15 11:55:24 by emansoor         ###   ########.fr       */
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
		Fixed&	operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator==(Fixed &other);
		bool	operator!=(Fixed &other);
		bool	operator<(Fixed &other);
		bool	operator>(Fixed &other);
		bool	operator<=(Fixed &other);
		bool	operator>=(Fixed &other);

		float	operator+(Fixed other);
		float	operator-(Fixed other);
		float	operator*(Fixed other);
		float	operator/(Fixed other);

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		
		static Fixed			&min(Fixed &f1, Fixed &f2);
		static const Fixed		&min(const Fixed &f1, const Fixed &f2);
		static Fixed			&max(Fixed &f1, Fixed &f2);
		static const Fixed		&max(const Fixed &f1, const Fixed &f2);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &obj);

#endif