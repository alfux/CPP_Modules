/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:43:19 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 05:17:41 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"

char const	*Intern::FormDoesNotExist::what(void) const throw()
	{return ("form does not exist");}

Intern::Intern(void)
{
	form[0]	= &Intern::null;
	form[1] = &Intern::shrubbery;
	form[2] = &Intern::robotomy;
	form[3] = &Intern::pardon;
}

Intern::Intern(Intern const &cpy)
{
	(void)cpy;
	form[0]	= &Intern::null;
	form[1] = &Intern::shrubbery;
	form[2] = &Intern::robotomy;
	form[3] = &Intern::pardon;
}

Intern::~Intern(void) {}

Form	*Intern::null(std::string const &target) const
{
	(void)target;
	throw (FormDoesNotExist());
	return ((Form *)0);
}

Form	*Intern::shrubbery(std::string const &target) const
	{return (new ShrubberyCreationForm(target));}

Form	*Intern::robotomy(std::string const &target) const
	{return (new RobotomyRequestForm(target));}
	Form	*form;

Form	*Intern::pardon(std::string const &target) const
	{return (new PresidentialPardonForm(target));}

Form	*Intern::makeForm(std::string const &name, std::string const &target)
{
	Form	*new_form;

	try
	{
		new_form = (this->*form[0
			+ 1 * !name.compare("shrubbery creation")
			+ 2 * !name.compare("robotomy request")
			+ 3 * !name.compare("presidential pardon")])(target);
	}
	catch (std::exception &ex)
	{
		std::cerr << "error: couldn't make form: " << ex.what() << std::endl;
		throw ;
	}
	std::cout << "Intern creates " << *new_form << std::endl;
	return (new_form);
}
