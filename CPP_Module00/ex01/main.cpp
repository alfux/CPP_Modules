/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:08:07 by alfux             #+#    #+#             */
/*   Updated: 2022/10/11 17:07:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stdlib.h>

int	main(void)
{
	void	*lost;

	std::cout << "Hello world!\n";
	lost = malloc(17 * sizeof (char));
	(void)lost;
	return (0);
}
