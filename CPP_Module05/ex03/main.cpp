/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:16:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 05:19:13 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"

int	main(void)
{
	Intern		some_random_intern;
	Bureaucrat	donald("Donald", 1);
	Form	*rff;

	rff = some_random_intern.makeForm("shrubbery creation", "mylittlegarden");
	donald.signForm(*rff);
	donald.executeForm(*rff);
	delete rff;
	rff = some_random_intern.makeForm("robotomy request", "Bender");
	donald.signForm(*rff);
	donald.executeForm(*rff);
	delete rff;
	rff = some_random_intern.makeForm("presidential pardon", "turkeys");
	donald.signForm(*rff);
	donald.executeForm(*rff);
	delete rff;
	rff = some_random_intern.makeForm("", "louloulou");
	donald.signForm(*rff);
	donald.executeForm(*rff);
	delete rff;
	return (0);
}
