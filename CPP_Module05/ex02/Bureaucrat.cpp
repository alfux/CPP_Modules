/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:12:12 by alfux             #+#    #+#             */
/*   Updated: 2022/11/06 23:58:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
	{return ("error: grade is too high");}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
	{return ("error: grade is too low");}

Bureaucrat::Bureaucrat(void) : name("Nameless"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name) : name(name), grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const &cp) : name(cp.name), grade(cp.grade)
{
	if (this->grade > 150)
		throw (GradeTooLowException());
	else if (this->grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(int const &grade) : name("Nameless"), grade(grade) 
{
	if (this->grade > 150)
		throw (GradeTooLowException());
	else if (this->grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
	: name(name), grade(grade)
{
	if (this->grade > 150)
		throw (GradeTooLowException());
	else if (this->grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &cpy)
{
	if (cpy.grade > 150)
		throw (GradeTooLowException());
	else if (cpy.grade < 1)
		throw (GradeTooHighException());
	this->grade = cpy.grade;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator+=(int const &inc)
{
	if (this->grade - inc < 1)
		throw (GradeTooHighException());
	else if (this->grade - inc > 150)
		throw (GradeTooLowException());
	this->grade -= inc;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator-=(int const &dec)
{
	if (this->grade + dec > 150)
		throw (GradeTooLowException());
	else if (this->grade + dec < 1)
		throw (GradeTooHighException());
	this->grade += dec;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
	{return (this->name);}

int const	&Bureaucrat::getGrade(void) const
	{return (this->grade);}

void	Bureaucrat::signForm(Form &form)
{
	try
		{form.beSigned(*this);}
	catch (std::exception &ex)
	{
		std::cout << *this << " couldn't sign " << form << " because "
			<< ex.what() << std::endl;
		return ;
	}
	std::cout << *this << " " << form << std::endl;
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
		{form.execute(*this);}
	catch (std::exception &ex)
	{
		std::cerr << *this << " couldn't execute " << form << " because: "
			<< ex.what() << std::endl;
		return ;
	}
	std::cout << *this << " executed " << form << std::endl;
}

std::ostream	&operator<<(std::ostream &fl, Bureaucrat const &ob)
{
	fl << ob.getName() << ", bureaucrat grade " << ob.getGrade();
	return (fl);
}
