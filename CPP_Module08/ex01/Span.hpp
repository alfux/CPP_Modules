/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:16:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/14 04:18:43 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SPAN_HPP
# define SPAN_HPP
# include <cstdint>
# include <list>
# include <algorithm>

class	Span
{
	private :
		struct	FullSpan : std::exception
			{char const	*what(void) const throw();};
		struct	NoDistance : std::exception
			{char const	*what(void) const throw();};

		typedef std::list<int64_t>::iterator	t_iterator;

		std::list<int64_t>	elem;
		uint64_t			max_size;
		uint64_t			min_dist;

		uint64_t	distance(int64_t const &, int64_t const &);

	public :
		Span(uint64_t const & = 1);
		Span(Span const &);
		~Span(void);

		Span	&operator=(Span const &);

		void		addNumber(int64_t const &);
		uint64_t	shortestSpan(void) const;
		uint64_t	longestSpan(void) const;

		template <typename iter>
			void	addRange(iter const &st, iter const &ed, uint64_t n = 1)
		{
			typename std::iterator_traits<iter>::value_type	validity_check;
			iter											it;

			(void)validity_check;
			while (n--)
			{
				it = st;
				while (it < ed)
					this->addNumber(*(it++));
			}
		}
};

#endif
