/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:53:32 by alfux             #+#    #+#             */
/*   Updated: 2022/11/12 19:20:26 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename t_T>
	char const	*Array<t_T>::OutOfRangeAccess::what(void) const throw()
	{return ("error: out of range access denied");}

template <typename t_T> Array<t_T>::Array(void)
	: array(reinterpret_cast<t_T *> (0)), array_size(0) {}

template <typename t_T> Array<t_T>::Array(unsigned int n) : array_size(n)
{
	try
		{this->array = new t_T[this->array_size]();}
	catch (std::exception &e)
	{
		this->array = reinterpret_cast<t_T *> (0);
		this->array_size = 0;
		std::cerr << "error: Array<t_T>(n): " << e.what() << std::endl;
	}
}

template <typename t_T> Array<t_T>::Array(Array<t_T> const &cpy)
	: array_size(cpy.array_size)
{
	unsigned int	i;

	try
		{this->array = new t_T[this->array_size]();}
	catch (std::exception &e)
	{
		this->array = reinterpret_cast<t_T *> (0);
		this->array_size = 0;
		std::cerr << "error: Array<t_T>(copy): " << e.what() << std::endl;
		return ;
	}
	for (i = 0; i < this->array_size; i++)
		*(this->array + i) = *(cpy.array + i);
}

template <typename t_T> Array<t_T>::~Array(void)
	{delete[] this->array;}

template <typename t_T>
	Array<t_T>	&Array<t_T>::operator=(Array<t_T> const &cpy)
{
	unsigned int	i;

	delete[] this->array;
	this->array_size = cpy.array_size;
	try
		{this->array = new t_T[this->array_size]();}
	catch (std::exception &e)
	{
		this->array = reinterpret_cast<t_T *> (0);
		this->array_size = 0;
		std::cerr << "error: Array<t_T>(=): " << e.what() << std::endl;
		return (*this);
	}
	for (i = 0; i < this->array_size; i++)
		*(this->array + i) = *(cpy.array + i);
	return (*this);
}

template <typename t_T> t_T	&Array<t_T>::operator[](unsigned int n)
{
	if (n >= this->array_size)
		throw (Array<t_T>::OutOfRangeAccess());
	return (*(this->array + n));
}

template <typename t_T>
	t_T const	&Array<t_T>::operator[](unsigned int n) const
{
	if (n >= this->array_size)
		throw (Array<t_T>::OutOfRangeAccess());
	return (*(this->array + n));
}

template <typename t_T> unsigned int	Array<t_T>::size(void) const
	{return (this->array_size);}

#endif
