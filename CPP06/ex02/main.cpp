/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:30:51 by emansoor          #+#    #+#             */
/*   Updated: 2024/11/09 13:36:01 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "time.h"

int	main(void)
{
	srand (time(NULL));
	
	Base	*random = generate();
	Base	*random1 = generate();
	Base	*random2 = generate();

	if (!random)
		return (1);
	if (!random1)
	{
		delete (random);
		return (1);
	}
	if (!random2)
	{
		delete (random);
		delete (random1);
		return (1);
	}
	
	identify(random);
	identify(*random);

	identify(random1);
	identify(*random1);

	identify(random2);
	identify(*random2);
	
	delete (random);
	delete (random1);
	delete (random2);
	return (0);
}