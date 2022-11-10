/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 03:02:21 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 03:37:51 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Base.hpp"

Base::~Base(void) {}

Base	*generate(void)
{
	std::random_device	rand;
	int					which;

	which = static_cast<int> (rand() % 3);
	if (which == 0)
	{
		std::cout << "(Instance A generated)" << std::endl;
		return (new A());
	}
	else if (which == 1)
	{
		std::cout << "(Instance B generated)" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "(Instance C generated)" << std::endl;
		return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *> (p))
		std::cout << "Object is of type A" << std::endl;
	else if (dynamic_cast<B *> (p))
		std::cout << "Object is of type B" << std::endl;
	else
		std::cout << "Object is of type C" << std::endl;
}

void	identify(Base &p)
{
	try
		{(void)(dynamic_cast<A &> (p));}
	catch (...)
	{
		try
			{(void)(dynamic_cast<B &> (p));}
		catch (...)
		{
			std::cout << "Object is of type C" << std::endl;
			return ;
		}
		std::cout << "Object is of type B" << std::endl;
		return ;
	}
	std::cout << "Object is of type A" << std::endl;
}
