/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:08:47 by alfux             #+#    #+#             */
/*   Updated: 2022/11/16 06:42:06 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>

#define t_VTYPE int64_t
#define CONTAINER std::vector
#define S_CONTAINER "std::vector"

int	main(void)
{
	MutantStack<t_VTYPE>	mstack;;

	mstack.push(5);
	mstack.push(17);
	std::cout << "MutantStack output:\n" << std::setw(4) << mstack.top() << ' ';
	mstack.pop();
	std::cout << std::setw(4) << mstack.size() << ' ';
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	for (int i = 0; i < 29; i++)
	{
		if (i % 2)
			mstack.push(i);
		else
			mstack.push(-i);
	}
	mstack.push(0);
	MutantStack<t_VTYPE>::iterator optest = mstack.begin();
	MutantStack<t_VTYPE>::iterator it;
	it = optest;
	MutantStack<t_VTYPE>::iterator ite = mstack.end();
	++it;
	t_VTYPE	&test = *((--ite)++);
	--it;
	while (it < ite && ite > it && it <= ite && ite >= it && !(ite <= it))
	{
		if (it == ++(++mstack.begin()))
		{
			mstack.pop();
			std::cout << std::setw(4) << *it << ' ';
			mstack.push(666);
		}
		else
			std::cout << std::setw(4) << *it << ' ';
		++it;
	}
	std::stack<t_VTYPE> s(mstack);
	std::cout << std::endl;
	test = 12;
	for (it = mstack.begin(); it != mstack.end(); it++)
		std::cout << std::setw(4) << *it << ' ';
	std::cout << std::endl << std::endl;
//------------------------------------------------------------------------------
	CONTAINER<t_VTYPE>	vect;

	vect.push_back(5);
	vect.push_back(17);
	std::cout << S_CONTAINER << " output:\n" << std::setw(4) << vect.back()
		<< ' ';
	vect.pop_back();
	std::cout << std::setw(4) << vect.size() << ' ';
	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(737);
	for (int i = 0; i < 29; i++)
	{
		if (i % 2)
			vect.push_back(i);
		else
			vect.push_back(-i);
	}
	vect.push_back(0);
	CONTAINER<t_VTYPE>::iterator itv = vect.begin();
	CONTAINER<t_VTYPE>::iterator itve = vect.end();
	++itv;
	t_VTYPE	&testv = *((--itve)++);
	--itv;
	while (itv != itve)
	{
		if (itv == ++(++vect.begin()))
		{
			vect.pop_back();
			std::cout << std::setw(4) << *itv << ' ';
			vect.push_back(666);
		}
		else
			std::cout << std::setw(4) << *itv << ' ';
		++itv;
	}
	CONTAINER<t_VTYPE> sv(vect);
	std::cout << std::endl;
	testv = 12;
	for (itv = vect.begin(); itv != vect.end(); itv++)
		std::cout << std::setw(4) << *itv << ' ';
	std::cout << std::endl;
	return (0);
}

