/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:51:37 by alfux             #+#    #+#             */
/*   Updated: 2022/11/11 17:37:09 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "iter.hpp"

int	main(void)
{
	std::string	tab3[8] = {"Bon", "jou", "je", "su", "is", "une", "phra", "!"};
	char		tab[8] = {'B', 'O', 'N', 'J', 'O', 'U', 'R', 0};
	int			tab2[8] = {3, 10, 5, 16, 8, 4, 2, 1};
	int			i;

	std::cout << "Original tab: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab + i);
	std::cout << std::endl;
	iter<char, char>(tab, 8, &addone<char, char>);
	std::cout << "iter tab: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab + i);
	std::cout << std::endl << std::endl;

	std::cout << "Original tab2: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab2 + i) << ' ';
	std::cout << std::endl;
	iter<int, void>(tab2, 8, &addone<int, void>);
	std::cout << "iter tab2: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab2 + i) << ' ';
	std::cout << std::endl << std::endl;
	
	std::cout << "Original tab3: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab3 + i) << ' ';
	std::cout << std::endl;
	iter<std::string, void>(tab3, 8, &addone<std::string, void>);
	std::cout << "iter tab3: ";
	for (i = 0; i < 8; i++)
		std::cout << *(tab3 + i) << ' ';
	std::cout << std::endl;
	return (0);
}
