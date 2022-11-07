/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:27:22 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 05:07:19 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private :
		struct	FormDoesNotExist : std::exception
			{char const	*what(void) const throw();};

		Form	*null(std::string const &) const;
		Form	*shrubbery(std::string const &) const;
		Form	*robotomy(std::string const &) const;
		Form	*pardon(std::string const &) const;
		Form	*(Intern::*form[4])(std::string const &) const;
	
	public :
		Intern(void);
		Intern(Intern const &);
		~Intern(void);

		Intern	&operator=(Intern const &);

		Form	*makeForm(std::string const &, std::string const &);
};

#endif
