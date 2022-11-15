/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:09:22 by alfux             #+#    #+#             */
/*   Updated: 2022/11/15 23:54:19 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <exception>
# include <iterator>
# include <stack>

template <typename t_vtype> class	MutantStack : public std::stack<t_vtype>
{
	typedef std::iterator<std::bidirectional_iterator_tag, t_vtype> t_bidir;

	private :
		struct	BadDereferencing : std::exception
			{char const	*what(void) const throw();};
		class	PrivIterator : public t_bidir
		{
			protected :
				MutantStack<t_vtype>	*mutant;
				size_t					position;
				size_t					m_size;

			public :
				PrivIterator(void);
				PrivIterator(PrivIterator const &);
				PrivIterator(MutantStack<t_vtype> *, size_t);
				~PrivIterator(void);

				t_vtype					&operator*(void);
				virtual PrivIterator	&operator=(PrivIterator const &);
				PrivIterator			&operator++(void);
				PrivIterator			&operator--(void);
				PrivIterator			operator++(int);
				PrivIterator			operator--(int);
				bool					operator==(PrivIterator const &) const;
				bool					operator!=(PrivIterator const &) const;
				bool					operator<=(PrivIterator const &) const;
				bool					operator>=(PrivIterator const &) const;
				bool					operator<(PrivIterator const &) const;
				bool					operator>(PrivIterator const &) const;
		};

		std::stack<t_vtype>	memory;

		void	swapToMem(void);
		void	swapFromMem(void);

	public :
		class	iterator : public PrivIterator
		{
			public :
				iterator(void);
				iterator(PrivIterator const &);
				~iterator(void);

				PrivIterator	&operator=(PrivIterator const &);
		};

		MutantStack(void);
		MutantStack(MutantStack<t_vtype> const &);
		~MutantStack(void);

		MutantStack<t_vtype>	&operator=(MutantStack<t_vtype> const &);

		PrivIterator	begin(void);
		PrivIterator	end(void);
};

# include "MutantStack.tpp"
#endif
