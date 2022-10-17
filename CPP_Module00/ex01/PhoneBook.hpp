/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:43 by alfux             #+#    #+#             */
/*   Updated: 2022/10/17 06:45:04 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# ifndef MAX_CONTACT
#  define MAX_CONTACT 8
# endif

class	PhoneBook
{
	Contact	contacts[MAX_CONTACT];
	int		n;

	int	no_contact(void);

	public :
			PhoneBook(void);
		int	add(void);
		int	search(void);
			~PhoneBook(void);
};

#endif
