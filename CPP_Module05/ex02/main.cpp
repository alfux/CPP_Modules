/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:16:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 03:08:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				pdg("Donald Trump", 1);
	Bureaucrat				slave("Random Slave", 146);
	ShrubberyCreationForm	form("forest");
	RobotomyRequestForm		rmfreewill("R2D2");
	PresidentialPardonForm	turkey("turkey");

	slave.signForm(form);
	slave.signForm(rmfreewill);
	slave.signForm(turkey);
	slave.executeForm(form);
	slave.executeForm(rmfreewill);
	slave.executeForm(turkey);
	pdg.signForm(form);
	pdg.signForm(rmfreewill);
	pdg.signForm(turkey);
	slave.executeForm(form);
	slave.executeForm(rmfreewill);
	slave.executeForm(turkey);
	pdg.executeForm(form);
	pdg.executeForm(rmfreewill);
	pdg.executeForm(turkey);
	slave.executeForm(rmfreewill);
	slave += 141;
	slave.executeForm(rmfreewill);
	return (0);
}
