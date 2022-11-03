/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:48:36 by alfux             #+#    #+#             */
/*   Updated: 2022/11/03 03:10:28 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MateriaSource's default constructor called]" << std::endl;
	this->memory[0] = (AMateria *)0;
	this->memory[1] = (AMateria *)0;
	this->memory[2] = (AMateria *)0;
	this->memory[3] = (AMateria *)0;
}

MateriaSource::MateriaSource(MateriaSource const &cpy) : IMateriaSource(cpy)
{
	for (int i = 0; i < 4; i++)
	{
		if (cpy.memory[i])
		{
			this->memory[i] = cpy.memory[i]->clone();
			if (!this->memory[i])
				std::cerr << "error: couldn't clone memory slot " << i
					<< std::endl;
		}
		else
			this->memory[i] = (AMateria *)0;
	}
	std::cout << "[MateriaSource's copy constructor called]" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "[MateriaSource's destructor called]" << std::endl;
	if (this->memory[0])
		delete this->memory[0];
	if (this->memory[1])
		delete this->memory[1];
	if (this->memory[2])
		delete this->memory[2];
	if (this->memory[3])
		delete this->memory[3];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &cpy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory[i])
		{
			delete this->memory[i];
			this->memory[i] = (AMateria *)0;
		}
		if (cpy.memory[i])
		{
			this->memory[i] = cpy.memory[i]->clone();
			if (!this->memory[i])
				std::cerr << "error: couldn't clone memory slot " << i
					<< std::endl;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->memory[i])
		{
			this->memory[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*tmp;
	int			i;

	tmp = (AMateria *)0;
	for (i = 0; i < 4; i++)
	{
		if (!this->memory[i])
			continue ;
		if (type.compare(this->memory[i]->getType()) == 0)
		{
			tmp = this->memory[i]->clone();
			if (!tmp)
				std::cerr << "error: couldn't create materia" << std::endl;
			break ;
		}
	}
	return (tmp);
}
