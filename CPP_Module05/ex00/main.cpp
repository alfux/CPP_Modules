/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:39:00 by alfux             #+#    #+#             */
/*   Updated: 2022/11/04 16:59:40 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	pdg("Elon Musk", 1);
		Bureaucrat	vp("Vice president");
		Bureaucrat	slave(2);
		Bureaucrat	clone(vp);
		Bureaucrat	def;

		vp = slave;
		std::cout << pdg << " is our first bureaucrat" << std::endl;
		((pdg -= 10) -= 12) += 230;
		std::cout << pdg << " has been demoted twice" << std::endl;
		std::cout << vp << " is our second bureaucrat" << std::endl;
		std::cout << slave << " is our first slave" << std::endl;
		std::cout << clone << " is our first clone" << std::endl;
		std::cout << def << " is our first zombie" << std::endl;
		def += 149;
		std::cout << def << " has been promoted" << std::endl;
		vp -= 148;
		std::cout << vp << " has been demoted" << std::endl;
	}
	catch (std::exception &ex)
		{std::cerr << ex.what() << std::endl;}
	return (0);
}
