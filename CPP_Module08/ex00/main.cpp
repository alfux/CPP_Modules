/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:10:22 by alfux             #+#    #+#             */
/*   Updated: 2022/11/13 03:25:46 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <forward_list>
#include <list>

int	main(int ac, char **av)
{
	std::vector<long>			tabv(10);
	std::vector<long>::iterator	itv;
	std::vector<long>::iterator	endv;
	int							i;
	int							look;
	
	if (ac != 2)
	{
		std::cerr << "error: bad arguments" << std::endl;
		return (1);
	}
	i = 0;
	try
		{look = std::stoi(*(av + 1));}
	catch (std::exception &e)
	{
		look = 0;
		std::cerr << "error: " << e.what() << std::endl << std::endl;
	}
	for (itv = tabv.begin(), endv = tabv.end(); itv != endv; itv++)
		*itv = i++;
	for (itv = tabv.begin(), endv = tabv.end(); itv != endv; itv++)
		std::cout << "tabv = " << *itv << std::endl;
	itv = easyfind(tabv, look);
	if (itv == tabv.end())
		std::cout << "Sorry not found !" << std::endl;
	else
		std::cout << "Found it: " << *itv << " !" << std::endl;
	std::cout << std::endl;

	std::deque<long>			tabd(10);
	std::deque<long>::iterator	itd;
	std::deque<long>::iterator	endd;
	
	for (itd = tabd.begin(), endd = tabd.end(); itd != endd; itd++)
		*itd = i++;
	for (itd = tabd.begin(), endd = tabd.end(); itd != endd; itd++)
		std::cout << "tabd = " << *itd << std::endl;
	itd = easyfind(tabd, look);
	if (itd == tabd.end())
		std::cout << "Sorry not found !" << std::endl;
	else
		std::cout << "Found it: " << *itd << " !" << std::endl;
	std::cout << std::endl;

	std::array<long, 10>			taba;
	std::array<long, 10>::iterator	ita;
	std::array<long, 10>::iterator	enda;
	
	for (ita = taba.begin(), enda = taba.end(); ita != enda; ita++)
		*ita = i++;
	for (ita = taba.begin(), enda = taba.end(); ita != enda; ita++)
		std::cout << "taba = " << *ita << std::endl;
	ita = easyfind(taba, look);
	if (ita == taba.end())
		std::cout << "Sorry not found !" << std::endl;
	else
		std::cout << "Found it: " << *ita << " !" << std::endl;
	std::cout << std::endl;

	std::forward_list<long>				tabfl(10);
	std::forward_list<long>::iterator	itfl;
	std::forward_list<long>::iterator	endfl;
	
	for (itfl = tabfl.begin(), endfl = tabfl.end(); itfl != endfl; itfl++)
		*itfl = i++;
	for (itfl = tabfl.begin(), endfl = tabfl.end(); itfl != endfl; itfl++)
		std::cout << "tabfl = " << *itfl << std::endl;
	itfl = easyfind(tabfl, look);
	if (itfl == tabfl.end())
		std::cout << "Sorry not found !" << std::endl;
	else
		std::cout << "Found it: " << *itfl << " !" << std::endl;
	std::cout << std::endl;

	std::list<long>				tabl(10);
	std::list<long>::iterator	itl;
	std::list<long>::iterator	endl;
	
	for (itl = tabl.begin(), endl = tabl.end(); itl != endl; itl++)
		*itl = i++;
	for (itl = tabl.begin(), endl = tabl.end(); itl != endl; itl++)
		std::cout << "tabl = " << *itl << std::endl;
	itl = easyfind(tabl, look);
	if (itl == tabl.end())
		std::cout << "Sorry not found !" << std::endl;
	else
		std::cout << "Found it: " << *itl << " !" << std::endl;
	std::cout << std::endl;

	return (0);
}
