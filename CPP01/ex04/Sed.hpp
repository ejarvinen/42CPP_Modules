/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:17:20 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/11 15:38:41 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

# include <iostream>
# include <fstream>
# include <istream>
# include <string>

int		sed(char *argv[]);
void	moc_replace(std::string line, std::string original, std::string replacement);

#endif