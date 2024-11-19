/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:54:55 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/19 10:23:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

// template <typename T, typename W>
// void    iter(T *address, unsigned int len, W (*func)(T &param));

template <typename T>
void    iter(T *address, unsigned int len, void (*func)(T &param))

#endif