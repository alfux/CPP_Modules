/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:43 by alfux             #+#    #+#             */
/*   Updated: 2022/10/14 18:00:03 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>

# ifndef MAX_CONTACT
#  define MAX_CONTACT 8
# endif

class	PhoneBook
{
	Contact	contacts[MAX_CONTACT];

	public :
			PhoneBook();
		int	add();
		int	search();
			~PhoneBook();
};

#endif
