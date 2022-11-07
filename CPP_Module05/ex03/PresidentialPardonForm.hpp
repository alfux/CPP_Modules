/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:47:34 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 02:50:06 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private :
		std::string const	target;

		void	action(void) const;

	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm(std::string const &);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &);
};

#endif
