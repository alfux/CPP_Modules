/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:43 by alfux             #+#    #+#             */
/*   Updated: 2022/10/15 06:41:39 by alfux            ###   ########.fr       */
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
	private :
		Contact	contacts[MAX_CONTACT];

	public :
			PhoneBook(void);
		int	add(void);
		int	search(void);
			~PhoneBook(void);
};

#endif
