/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:16:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/05 14:32:39 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	pdg("Alexis Fuchs", 1);
	Form		form;
	try
		{Form	test(1, 15);}
	catch (std::exception &ex)
		{std::cout << ex.what() << std::endl;}
	Form		test(15, 1);

	pdg.signForm(form);
	pdg -= 1;
	pdg.signForm(form);
	pdg.signForm(test);
	return (0);
}
