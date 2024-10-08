/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:13:03 by alfux             #+#    #+#             */
/*   Updated: 2023/04/01 03:52:12 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <chrono>
# include <Error.hpp>

# define DIGIT "0123456789"
# define WSPACE "\t\n\r\v\f "
# define UINTSEQ "0123456789\t\n\r\v\f "

class	PmergeMe
{
	std::chrono::duration<double, std::ratio<1, 1000> >	vector_time;
	std::chrono::duration<double, std::ratio<1, 1000> >	list_time;
	std::vector<uint32_t>								vector;
	std::list<uint32_t>									list;

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &cpy);
		PmergeMe(std::string const &seq);
		~PmergeMe(void);

		PmergeMe		&operator=(PmergeMe const &cpy);
		PmergeMe		&operator=(std::string const &seq);
		std::ostream	&operator>>(std::ostream &os);

	private:
		void	checkSeq(std::string const &seq);
		void	trimCpy(std::string &dst, std::string const &src);
		void	sort(std::vector<uint32_t> &seq);
		void	sort(std::list<uint32_t> &seq);
		void	insert(std::vector<uint32_t> &small, std::vector<uint32_t> &big);
		void	insert(std::list<uint32_t> &small, std::list<uint32_t> &big);
		bool	isSorted(std::vector<uint32_t> const &seq);
		bool	isSorted(std::list<uint32_t> const &seq);
};

#endif
