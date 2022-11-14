/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:17:18 by alfux             #+#    #+#             */
/*   Updated: 2022/11/14 04:33:37 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <random>

#define TEST 10001

static int64_t	getRandom(void)
{
	std::random_device	rand;
	int64_t				ret;

	ret = rand();
	if (rand() % 2)
		return ((-1) * ret);
	return (ret);
}

static int64_t	getSmallRandom(void)
{
	std::random_device	rand;
	int64_t				ret;

	ret = rand() / 100000000;
	if (rand() % 2)
		return ((-1) * ret);
	return (ret);
}

int	main(void)
{
	Span					obj(TEST);
	std::vector<int64_t>	v(TEST);
	unsigned long			i;

	try
		{std::cout << "Shortest distance is " << obj.shortestSpan();}
	catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}
	std::generate(v.begin(), v.end(), &getRandom); 
	obj.addRange(v.begin(), v.end());
	std::cout << "Smallest in range is "
		<< *std::min_element(v.begin(), v.end()) << std::endl
		<< "Largest in range is "
		<< *std::max_element(v.begin(), v.end()) << std::endl
		<< "Shortest distance is " << obj.shortestSpan() << std::endl
		<< "Longest distance is " << obj.longestSpan() << std::endl;
	try
		{obj.addNumber(7);}
	catch (std::exception &e)
		{std::cerr << e.what() << std::endl << std::endl;}

	v.resize(5);
	std::generate(v.begin(), v.end(), &getSmallRandom);
	obj = Span(TEST);
	obj.addRange(v.begin(), v.end());
	for (i = 0; i < v.size(); i++)
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	std::cout << "Shortest distance is " << obj.shortestSpan() << std::endl
		<< "Longest distance is " << obj.longestSpan() << std::endl;
	
	obj = Span(5);
	try
		{obj.addRange(v.begin(), v.end(), 2);}
	catch (std::exception &e)
	{
		obj = Span(5);
		std::cerr << std::endl << e.what() << std::endl;
	}
	try
		{std::cout << "Try shortest: " << obj.shortestSpan();}
	catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}
	obj.addNumber(6);
	try
		{std::cout << "Try longest: " << obj.longestSpan();}
	catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}
	obj.addNumber(3);
	obj.addNumber(17);
	obj.addNumber(9);
	obj.addNumber(11);
	try
		{obj.addNumber(13);}
	catch (std::exception &e)
		{std::cerr << e.what() << std::endl;}
	std::cout << "Shortest distance is " << obj.shortestSpan() << std::endl
		<< "Longest distance is " << obj.longestSpan() << std::endl;
	return (0);
}
