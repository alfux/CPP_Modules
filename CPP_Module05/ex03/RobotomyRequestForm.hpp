/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 01:32:58 by alfux             #+#    #+#             */
/*   Updated: 2022/11/07 01:56:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <chrono>
# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private :
		std::string const	target;

		void	action(void) const;

	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &);
		RobotomyRequestForm(std::string const &);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &);
};

#endif
