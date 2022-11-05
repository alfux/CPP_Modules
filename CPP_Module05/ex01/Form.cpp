/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:50:36 by alfux             #+#    #+#             */
/*   Updated: 2022/11/05 14:23:48 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

char const	*Form::GradeTooHighException::what(void) const throw()
	{return ("error: grade is too high");}

char const	*Form::GradeTooLowException::what(void) const throw()
	{return ("error: grade is too low");}

Form::Form(void) : name("Generic"), status(false), gsign(1), gexec(1) {}

Form::Form(std::string const &name)
	: name(name), status(false), gsign(1), gexec(1) {}

Form::Form(Form const &cpy)
	: name(cpy.name), status(cpy.status), gsign(cpy.gsign), gexec(cpy.gexec)
{
	if (this->gsign > 150 || this->gexec > 150)
		throw (GradeTooLowException());
	else if (this->gsign < 1 || this->gexec < 1)
		throw (GradeTooHighException());
}

Form::Form(std::string const &name, int const &gsign, int const &gexec)
	: name(name), status(false), gsign(gsign), gexec(gexec)
{
	if (this->gsign > 150 || this->gexec > 150)
		throw (GradeTooLowException());
	else if (this->gsign < 1 || this->gexec < 1)
		throw (GradeTooHighException());
}

Form::Form(int const &gsign, int const &gexec)
	: name("Generic"), status(false), gsign(gsign), gexec(gexec)
{
	if (this->gsign > 150 || this->gexec > 150)
		throw (GradeTooLowException());
	else if (this->gsign < 1 || this->gexec < 1)
		throw (GradeTooHighException());
}

Form::~Form(void) {}

Form	&Form::operator=(Form const &cpy)
{
	this->status = cpy.status;
	return (*this);
}

std::string const	&Form::getName(void) const
	{return (this->name);}

bool const	&Form::getStatus(void) const
	{return (this->status);}

int const	&Form::getGradeToSign(void) const
	{return (this->gsign);}

int const	&Form::getGradeToExec(void) const
	{return (this->gexec);}

void	Form::beSigned(Bureaucrat const &bur)
{
	if (bur.getGrade() > this->gsign)
		throw (GradeTooLowException());
	this->status = true;
}

std::ostream	&operator<<(std::ostream &flux, Form const &form)
{
	if (form.getStatus())
		flux << "signed ";
	else
		flux << "unsigned ";
	flux << form.getName() << " form (grade " << form.getGradeToSign()
		<< " to sign " << form.getGradeToExec() << " to execute)";
	return (flux);
}
