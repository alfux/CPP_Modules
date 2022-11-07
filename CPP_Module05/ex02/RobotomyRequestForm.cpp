/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:44:18 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 02:58:57 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("Robotomy-Request", 72, 45), target("generic") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
	: Form(cpy), target(cpy.target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("Robotomy-Request", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=
	(RobotomyRequestForm const &cpy)
{
	if (this->target == cpy.target)
		Form::operator=(cpy);
	return (*this);
}

void	RobotomyRequestForm::action(void) const
{
	std::cout << "* bzzZzzzZZZZZ   vzzzt vzzzt TZZZZZZZZZZZZZ *" << std::endl;
	if (std::chrono::steady_clock::now().time_since_epoch().count() % 2)
		std::cout << "Success: " << this->target << " robotomised" << std::endl;
	else
		std::cout << "Failure: " << this->target << " escaped" << std::endl;
}
