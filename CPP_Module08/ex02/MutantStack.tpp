/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:13:17 by alfux             #+#    #+#             */
/*   Updated: 2022/11/16 05:44:53 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTANT_TPP
# define MUTANT_TPP

template <typename t_vtype> char const
	*MutantStack<t_vtype>::BadDereferencing::what(void) const throw ()
{
	return ("dereferencing out of range object");
}

template <typename t_vtype>
	MutantStack<t_vtype>::PrivIterator::PrivIterator(void)
	: mutant(0), position(0) {}

template <typename t_vtype>
	MutantStack<t_vtype>::PrivIterator::PrivIterator(PrivIterator const &cpy)
	: mutant(cpy.mutant), position(cpy.position) {}

template <typename t_vtype>
	MutantStack<t_vtype>::PrivIterator::PrivIterator
	(MutantStack<t_vtype> *mutant, size_t pos)
	: mutant(mutant), position(pos) {}

template <typename t_vtype>
	MutantStack<t_vtype>::PrivIterator::~PrivIterator(void) {}

template <typename t_vtype> t_vtype
	&MutantStack<t_vtype>::PrivIterator::operator*(void)
{
	t_vtype	*tmp;
	size_t	i;

	if (!this->position || this->position > this->mutant->size())
		throw (BadDereferencing());
	for (i = 1; i < this->position; i++)
		this->mutant->swapToMem();
	tmp = &this->mutant->top();
	for (i = this->position; i > 1; i--)
		this->mutant->swapFromMem();
	return (*tmp);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	&MutantStack<t_vtype>::PrivIterator::operator=(PrivIterator const &cpy)
{
	
	this->mutant = cpy.mutant;
	this->position = cpy.position;
	std::iterator<std::bidirectional_iterator_tag, t_vtype>::operator=(cpy);
	return (*this);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	&MutantStack<t_vtype>::PrivIterator::operator++(void)
{
	this->position--;
	return (*this);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	&MutantStack<t_vtype>::PrivIterator::operator--(void)
{
	this->position++;
	return (*this);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	MutantStack<t_vtype>::PrivIterator::operator++(int overload)
{
	PrivIterator	tmp(*this);

	(void)overload;
	this->position--;
	return (tmp);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	MutantStack<t_vtype>::PrivIterator::operator--(int overload)
{
	PrivIterator	tmp(*this);

	(void)overload;
	this->position++;
	return (tmp);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator==(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position == rh.position)
		return (true);
	return (false);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator!=(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position== rh.position)
		return (false);
	return (true);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator<=(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position >= rh.position)
		return (true);
	return (false);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator>=(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position <= rh.position)
		return (true);
	return (false);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator<(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position > rh.position)
		return (true);
	return (false);
}

template <typename t_vtype> bool
	MutantStack<t_vtype>::PrivIterator::operator>(PrivIterator const &rh) const
{
	if (this->mutant == rh.mutant && this->position < rh.position)
		return (true);
	return (false);
}

template <typename t_vtype>
	MutantStack<t_vtype>::iterator::iterator(void) : PrivIterator() {}

template <typename t_vtype>
	MutantStack<t_vtype>::iterator::iterator(PrivIterator const &cpy)
	: PrivIterator(cpy) {}

template <typename t_vtype>
	MutantStack<t_vtype>::iterator::~iterator(void) {};

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	&MutantStack<t_vtype>::iterator::operator=(PrivIterator const &cpy)
{
	return (PrivIterator::operator=(cpy));
}

template <typename t_vtype> void
	MutantStack<t_vtype>::swapToMem(void)
{
	if (this->size() > 0)
	{
		this->memory.push(this->top());
		this->pop();
	}
}

template <typename t_vtype> void
	MutantStack<t_vtype>::swapFromMem(void)
{
	if (this->memory.size() > 0)
	{
		this->push(this->memory.top());
		this->memory.pop();
	}
}

template <typename t_vtype>
	MutantStack<t_vtype>::MutantStack(void) : memory() {}

template <typename t_vtype>
	MutantStack<t_vtype>::MutantStack(MutantStack<t_vtype> const &cpy)
	: memory(cpy.memory) {}

template <typename t_vtype>
	MutantStack<t_vtype>::~MutantStack(void) {}

template <typename t_vtype> MutantStack<t_vtype>
	&MutantStack<t_vtype>::operator=(MutantStack<t_vtype> const &cpy)
{
	this->memory = cpy.memory;
	std::stack<t_vtype>::operator=(cpy);
	return (*this);
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	MutantStack<t_vtype>::begin(void)
{
	return (PrivIterator(this, this->size()));
}

template <typename t_vtype> typename MutantStack<t_vtype>::PrivIterator
	MutantStack<t_vtype>::end(void)
{
	return (PrivIterator(this, 0));
}

#endif
