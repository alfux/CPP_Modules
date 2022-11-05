/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:16:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/05 14:20:18 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	pdg("Alexis Fuchs", 1);
	Form		form;

	pdg.signForm(form);
	pdg -= 1;
	pdg.signForm(form);
	return (0);
}
