/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:51:57 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 00:54:37 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	private :
		std::string const	target;

		void	action(void) const;

	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm(std::string const &);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);
};

#endif
