/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:22:30 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 01:48:43 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Convert.hpp"

char const	*Convert::Unknown::what(void) const throw()
	{return ("unknown type");}

Convert::Convert(void) : literal(), type()
{
	this->char_val = 0;
	this->int_val = 0;
	this->float_val = 0;
	this->double_val = 0;
	this->prec = 1;
}

Convert::Convert(std::string const &literal) : literal(literal), type()
{
	if (!this->literal.compare("nan") || !this->literal.compare("+inf")
		|| !this->literal.compare("-inf") || !this->literal.compare("inf"))
		this->type = "double";
	else if (!this->literal.compare("nanf") || !this->literal.compare("+inff")
		|| !this->literal.compare("-inff") || !this->literal.compare("inff"))
		this->type = "float";
	else
		this->findType();
	if (this->type.compare("unknown"))
	{
		this->assignType();
		this->initVal();
		this->setPrec();
	}
	else
	{
		this->char_val = 0;
		this->int_val = 0;
		this->float_val = 0;
		this->double_val = 0;
		this->prec = 1;
		throw (Convert::Unknown());
	}
}

Convert::Convert(Convert const &cpy) : literal(cpy.literal), type(cpy.type)
{
	this->char_val = cpy.char_val;
	this->int_val = cpy.int_val;
	this->float_val = cpy.float_val;
	this->double_val = cpy.double_val;
	this->prec = cpy.prec;
}

Convert::~Convert(void) {}

Convert	&Convert::operator=(Convert const &cpy)
{
	this->literal = cpy.literal;
	this->type = cpy.type;
	this->char_val = cpy.char_val;
	this->int_val = cpy.int_val;
	this->float_val = cpy.float_val;
	this->double_val = cpy.double_val;
	this->prec = cpy.prec;
	return (*this);
}

Convert	&Convert::operator=(std::string const &lit)
{
	this->literal = lit;
	if (!this->literal.compare("nan") || !this->literal.compare("+inf")
		|| !this->literal.compare("-inf") || !this->literal.compare("inf"))
		this->type = "double";
	else if (!this->literal.compare("nanf") || !this->literal.compare("+inff")
		|| !this->literal.compare("-inff") || !this->literal.compare("inff"))
		this->type = "float";
	else
		this->findType();
	if (this->type.compare("unknown"))
	{
		this->assignType();
		this->initVal();
		this->setPrec();
	}
	else
	{
		this->char_val = 0;
		this->int_val = 0;
		this->float_val = 0;
		this->double_val = 0;
		this->prec = 1;
		throw (Convert::Unknown());
	}
	return (*this);
}

void	Convert::findType(void)
{
	size_t	size;
	bool	first;

	first = true;
	size = this->literal.size();
	if ((size == 1 && (this->literal[0] < '0' || this->literal[0] > '9'))
		|| (size == 3 && this->literal[0] == '\'' && this->literal[2] == '\'')
		|| (size == 3 && this->literal[0] == '\"' && this->literal[2] == '\"'))
		return ((void)(this->type = "char"));
	for (size_t i = 0; i < size; i++)
	{
		if (this->literal[i] < '0' || this->literal[i] > '9')
		{
			if (i == 0 && (this->literal[i] == '+' || this->literal[i] == '-'))
				continue ;
			else if (i == size - 1 && !first && this->literal[i] == 'f')
				return ((void)(this->type = "float"));
			else if (this->literal[i] != '.' || !first)
				return ((void)(this->type = "unknown"));
			first = false;
		}
	}
	if (first)
		return ((void)(this->type = "int"));
	this->type = "double";
}

void	Convert::assignType(void)
{
	if (!this->type.compare("char"))
		char_val = this->literal[(this->literal.size() == 3)];
	else
	{
		try
		{
			if (!this->type.compare("int"))
				int_val = std::stoi(this->literal);
			else if (!this->type.compare("float"))
				float_val = std::stof(this->literal);
			else if (!this->type.compare("double"))
				double_val = std::stod(this->literal);
		}
		catch (...)
		{
			this->type = "double";
			this->char_val = 0;
			this->int_val = 0;
			this->float_val = 0;
			this->double_val = 0;
			this->prec = 1;
			double_val = std::stod(this->literal);
		}
	}
}

void	Convert::initVal(void)
{
	if (!this->type.compare("char"))
	{
		this->int_val = static_cast<int> (char_val);
		this->float_val = static_cast<float> (char_val);
		this->double_val = static_cast<double> (char_val);
	}
	if (!this->type.compare("int"))
	{
		this->char_val = static_cast<char> (int_val);
		this->float_val = static_cast<float> (int_val);
		this->double_val = static_cast<double> (int_val);
	}
	if (!this->type.compare("float"))
	{
		this->char_val = static_cast<char> (float_val);
		this->int_val = static_cast<int> (float_val);
		this->double_val = static_cast<double> (float_val);
	}
	if (!this->type.compare("double"))
	{
		this->char_val = static_cast<char> (double_val);
		this->int_val = static_cast<int> (double_val);
		this->float_val = static_cast<float> (double_val);
	}
}

void	Convert::setPrec(void)
{
	size_t	i;

	i = 0;
	while (i < this->literal.size() && this->literal[i] != '.')
		i++;
	this->prec = this->literal.size() - i;
	if (!this->prec)
		this->prec++;
	if (this->literal[this->literal.size() - 1] == 'f')
		this->prec--;
	if (this->prec > 1)
		this->prec--;
}

char const	&Convert::getChar(void) const
	{return (this->char_val);}

int const	&Convert::getInt(void) const
	{return (this->int_val);}

float const	&Convert::getFloat(void) const
	{return (this->float_val);}

double const	&Convert::getDouble(void) const
	{return (this->double_val);}

std::string const	&Convert::getLiteral(void) const
	{return (this->literal);}

std::string const	&Convert::getType(void) const
	{return (this->type);}

std::ostream	&Convert::display(std::ostream &stm) const
{
	stm << std::fixed << std::setprecision(this->prec);
	if (this->double_val <= -129 || this->double_val >= 128
		|| !this->literal.compare("nan")
		|| !this->literal.compare("nanf"))
		stm << "char: impossible" << std::endl;
	else if (this->double_val < 32 || this->double_val >= 127)
		stm << "char: non displayable" << std::endl;
	else
		stm << "char: \'" << this->char_val << "\'" << std::endl;
	if (this->double_val <= -2147483649 || this->double_val >= 2147483648
		|| !this->literal.compare("nan")
		|| !this->literal.compare("nanf"))
		stm << "int: impossible" << std::endl;
	else
		stm << "int: " << this->int_val << std::endl;
	stm << "float: " << this->float_val << "f" << std::endl;
	stm << "double: " << this->double_val;
	return (stm);
}

std::ostream	&operator<<(std::ostream &stm, Convert const &conv)
	{return (conv.display(stm));}
