/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:37:46 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 06:30:36 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN(void) {}

RPN::RPN(RPN const &cpy): stack(cpy.stack), rpn(cpy.rpn) {}

RPN::RPN(std::string const &rpn): rpn(rpn) 
{
	this->rpn.erase(0, this->rpn.find_first_not_of(WSPACE));
	this->rpn.erase(this->rpn.find_last_not_of(WSPACE) + 1);
	this->checkSyntax();
}

RPN::~RPN(void) {}

RPN	&RPN::operator=(RPN const &cpy)
{
	this->stack = cpy.stack;
	this->rpn = cpy.rpn;
	return (*this);
}

RPN	&RPN::operator=(std::string const &rpn)
{
	this->rpn = rpn;
	this->rpn.erase(0, this->rpn.find_first_not_of(WSPACE));
	this->rpn.erase(this->rpn.find_last_not_of(WSPACE) + 1);
	while (this->stack.size())
		this->stack.pop();
	this->checkSyntax();
	return (*this);
}

void	RPN::solve(void)
{
	while (this->rpn.size())
	{
		if (this->rpn[0] >= '0' && this->rpn[0] <= '9')
		{
			this->stack.push(std::stod(this->rpn));
			this->rpn.erase(0, this->rpn.find_first_not_of(DIGIT));
		}
		else if (!this->rpn.find_first_of("+-*/"))
			this->process();
		else
			throw (Error(ESYN));
		this->rpn.erase(0, this->rpn.find_first_not_of(WSPACE));
	}
	if (this->stack.size() != 1)
		throw (Error(ESYN));
	std::cout << this->stack.top() << std::endl;
}

void	RPN::process(void)
{
	double	tmp;

	if (stack.size() < 2)
		throw (Error(ESYN));
	tmp = this->stack.top();
	this->stack.pop();
	switch (this->rpn[0])
	{
		case '+':
			this->stack.top() += tmp;
			break ;
		case '-':
			this->stack.top() -= tmp;
			break ;
		case '*':
			this->stack.top() *= tmp;
			break ;
		case '/':
			this->stack.top() /= tmp;
			break ;
	}
	this->rpn.erase(0, 1);
}

void	RPN::checkSyntax(void)
{
	if (!this->rpn.size())
		throw (Error(EARG));
	if (this->rpn.find_first_not_of(WSPACE) == std::string::npos)
		throw (Error(EARG));
	if (this->rpn.find_first_not_of(VALID_CHAR) != std::string::npos)
		throw (Error(ESYN));
}
