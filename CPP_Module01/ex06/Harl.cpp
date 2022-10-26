/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:49:35 by alfux             #+#    #+#             */
/*   Updated: 2022/10/26 03:34:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Harl.hpp"

Harl::Harl(void)
{
	ptr[0] = &Harl::einval;
	ptr[1] = &Harl::debug;
	ptr[2] = &Harl::info;
	ptr[3] = &Harl::warning;
	ptr[4] = &Harl::error;
}

void	Harl::einval(void)
{
	std::cerr << "fatal error: Harl does not know this level of severity\n";
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-tr"
		<< "iple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn’t put enough bacon in my burger ! If you did, I wouldn"
			<< "’t be asking for more !" << std::endl;

}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years whereas you started working here since "
		<< "last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager "
		<< "now." << std::endl;
}

void	Harl::complain(std::string level)
{
	((*this).**(ptr + (1 * !level.compare("DEBUG"))
		+ (2 * !level.compare("INFO")) + (3 * !level.compare("WARNING"))
		+ (4 * !level.compare("ERROR"))))();
}

Harl::~Harl(void) {}
