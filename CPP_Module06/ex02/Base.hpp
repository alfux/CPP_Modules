/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:57:44 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 03:17:14 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <random>

class	Base
{
	public :
		virtual	~Base(void);
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate(void);
void	identify(Base *);
void	identify(Base &);

#endif
