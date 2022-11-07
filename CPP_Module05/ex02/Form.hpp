/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:05:38 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 00:08:51 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private :
		struct	GradeTooHighException : std::exception
			{char const	*what(void) const throw();};
		struct	GradeTooLowException : std::exception
			{char const	*what(void) const throw();};
		struct	UnsignedForm : std::exception
			{char const	*what(void) const throw();};

		std::string const	name;
		bool				status;
		int const			gsign;
		int const			gexec;

		virtual void	action(void) const = 0;

	public :
		Form(void);
		Form(std::string const &);
		Form(Form const &);
		Form(std::string const &, int const &, int const &);
		Form(int const &, int const &);
		virtual	~Form(void) = 0;

		Form	&operator=(Form const &);

		std::string const	&getName(void) const;
		bool const			&getStatus(void) const;
		int const			&getGradeToSign(void) const;
		int const			&getGradeToExec(void) const;
		void				beSigned(Bureaucrat const &);
		void				execute(Bureaucrat const &) const;
};

std::ostream	&operator<<(std::ostream &, Form const &);

#endif
