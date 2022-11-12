/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:44:38 by alfux             #+#    #+#             */
/*   Updated: 2022/11/12 18:09:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

template <typename t_T> class	Array
{
	private :
		struct	OutOfRangeAccess : public std::exception
			{char const	*what(void) const throw();};

		t_T				*array;
		unsigned int	array_size;

	public :
		Array(void);
		Array(unsigned int);
		Array(Array const &);
		~Array(void);
		
		Array		&operator=(Array const &);
		t_T			&operator[](unsigned int);
		t_T const	&operator[](unsigned int) const;

		unsigned int	size(void) const;
};

# include "Array.tpp"
#endif
