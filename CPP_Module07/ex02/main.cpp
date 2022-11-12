/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:54:42 by alfux             #+#    #+#             */
/*   Updated: 2022/11/12 19:25:22 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Array.hpp"

int	main(void)
{
	unsigned int		i;
	unsigned int		j;
	Array<Array<char> *>	tab0;
	Array<int>				tab(10);
	Array<std::string>		tab2(5);
	Array<std::string>		tabc(tab2);
	Array<std::string>		tabd(tabc);

	for (i = 0; i < tab.size(); i++)
		tab[i] = i;
	for (i = 0; i < tabc.size(); i++)
		(tabc[i] = "antiword") += i + '0';

	tab0 = Array<Array<char> *> (8);
	for (i = 0; i < tab0.size(); i++)
	{
		tab0[i] = new Array<char> (3);
		for (j = 0; j < tab0[i]->size(); j++)
			(*tab0[i])[j] = 'a' + i + j;
	}
	
	std::cout << "Int array:" << std::endl;
	for (i = 0; i < tab.size(); i++)
		std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
	std::cout << std::endl << "Unmodified string array:" << std::endl;
	for (i = 0; i < tab2.size(); i++)
		std::cout << "tab2[" << i << "] = " << tab2[i] << std::endl;
	std::cout << std::endl << "Modified copy of string array:" << std::endl;
	for (i = 0; i < tabc.size(); i++)
		std::cout << "tabc[" << i << "] = " << tabc[i] << std::endl;
	std::cout << std::endl << "Unmodified copy of string array's copy:"
		<< std::endl;
	for (i = 0; i < tabd.size(); i++)
		std::cout << "tabd[" << i << "] = " << tabd[i] << std::endl;
	std::cout << std::endl << "Array<char> *array:" << std::endl;
	for (i = 0; i < tab0.size(); i++)
	{
		std::cout << "tab0[" << i << "] = " << std::endl << '\t';
		for (j = 0; j < tab0[i]->size(); j++)
			std::cout << "tab0[" << i << "][" << j << "] = " << (*tab0[i])[j]
				<< std::endl
				<< static_cast<char> ('\t' * (j != (tab0[i]->size() - 1)));
	}
	for (i = 0; i < tab0.size(); i++)
		delete tab0[i];
	return (0);
}
