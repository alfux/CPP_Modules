/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:22:32 by alfux             #+#    #+#             */
/*   Updated: 2022/10/11 14:48:05 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

int	ft_word(char *word)
{
	while (ft_isspace(*word))
		word++;
	if (!*word)
		return (0);
	while (*word)
	{
		while (*word && !ft_isspace(*word))
			std::cout << ft_toupper(*(word++));
		while (ft_isspace(*word))
			word++;
		if (*word)
			std::cout << ' ';
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while (*(av + i))
			if (ft_word(*(av + i++)) && *(av + i))
				std::cout << " ";
	std::cout << std::endl;
	return (0);
}
