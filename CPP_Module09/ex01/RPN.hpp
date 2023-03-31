/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:37:36 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 06:26:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>
# include <iostream>
# include <cmath>
# include <Error.hpp>

# define WSPACE "\t\n\r\v\f "
# define DIGIT "0123456789"
# define VALID_CHAR "+-*/0123456789\t\n\r\v\f "

class	RPN
{
	std::stack<double>	stack;
	std::string			rpn;

	public:
		RPN(void);
		RPN(RPN const &cpy);
		RPN(std::string const &rpn);
		~RPN(void);

		RPN	&operator=(RPN const &cpy);
		RPN	&operator=(std::string const &rpn);

		void	solve(void);
	
	private:
		void	process(void);
		void	checkSyntax(void);
};

#endif
