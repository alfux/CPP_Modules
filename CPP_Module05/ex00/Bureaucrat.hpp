/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:06:45 by alfux             #+#    #+#             */
/*   Updated: 2022/11/04 16:53:08 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class	Bureaucrat
{
	private :
		std::string const	name;
		int					grade;

		struct	GradeTooHighException : std::exception
			{char const	*what(void) const throw();};
		struct	GradeTooLowException : std::exception
			{char const *what(void) const throw();};

	public :
		Bureaucrat(void);
		Bureaucrat(std::string const &name);
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat(int const &grade);
		Bureaucrat(std::string const &name, int const &grade);
		virtual	~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &cpy);
		Bureaucrat	&operator+=(int const &inc);
		Bureaucrat	&operator-=(int const &dec);

		std::string const	&getName(void) const;
		int const			&getGrade(void) const;
};

std::ostream	&operator<<(std::ostream &flux, Bureaucrat const &obj);

#endif
