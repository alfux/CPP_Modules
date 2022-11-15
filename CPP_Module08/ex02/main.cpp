/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:08:47 by alfux             #+#    #+#             */
/*   Updated: 2022/11/16 00:11:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	MutantStack<int>			test;
	MutantStack<int>::iterator	it;

	it = test.begin();
	test.push(12);
	std::cout << "test.top() = " << test.top() << std::endl;
	std::cout << "it = " << *it << std::endl;
	*it = 9;
	std::cout << "it = " << *it << std::endl;
	std::cout << "test.top() = " << test.top() << std::endl;
	return (0);
}
