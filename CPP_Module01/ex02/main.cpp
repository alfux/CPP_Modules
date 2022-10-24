/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:29:22 by alfux             #+#    #+#             */
/*   Updated: 2022/10/24 23:26:09 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int	main(void)
{
	std::string	hi("HI THIS IS BRAIN");
	std::string	*stringPTR;
	std::string	&stringREF = hi;

	stringPTR = &hi;
	std::cout << "string adress: " << &hi << std::endl;
	std::cout << "stringPTR content: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;
	std::cout << "string content: " << hi << std::endl;
	std::cout << "stringPTR's pointed content: " << *stringPTR << std::endl;
	std::cout << "stringREF content: " << stringREF << std::endl;
	return (0);
}
