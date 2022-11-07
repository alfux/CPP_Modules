/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:14:14 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 02:58:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("Shrubbery-Creation", 145, 137), target("generic") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
	: Form(cpy), target(cpy.target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("Shrubbery-Creation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=
	(ShrubberyCreationForm const &cpy) 
{
	if (this->target == cpy.target)
		Form::operator=(cpy);
	return (*this);
}

void	ShrubberyCreationForm::action(void) const
{
	std::fstream	stm(std::string(this->target + "_shrubbery"),
		std::ios_base::out | std::ios_base::app);
	stm << std::endl;
	stm << "     ###    #####                                   " << std::endl;
	stm << "    #####  #######   ###    ####     ####..####     " << std::endl;
	stm << "    #### / #######  #####  ######\\  #####||#####    " << std::endl;
	stm << "      ||/    ||#     ###   | ||##|  #####||#####    " << std::endl;
	stm << "    \\_||     |||      |       |  |    ###||###      " << std::endl;
	stm << "      ||   \\ |||      |       |          ||         " << std::endl;
	stm << "i..:..||ii..\\|||/..l.u|..ww|u||uu|wiiu..u||..ualfuxu" << std::endl;
}
