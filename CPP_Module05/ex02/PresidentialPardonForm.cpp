/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:50:20 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 03:00:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("Presidential-Pardon", 25, 5), target("generic") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cp)
	: Form(cp), target(cp.target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("Presidential-Pardon", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=
	(PresidentialPardonForm const &cpy)
{
	if (this->target == cpy.target)
		Form::operator=(cpy);
	return (*this);
}

void	PresidentialPardonForm::action(void) const
	{std::cout << "Zaphod Beeblebrox pardoned " << this->target << std::endl;}
