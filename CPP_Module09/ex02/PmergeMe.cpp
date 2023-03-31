/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:13:34 by alfux             #+#    #+#             */
/*   Updated: 2023/03/31 21:27:56 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &cpy):
	vector_time(cpy.vector_time),
	list_time(cpy.list_time),
	vector(cpy.vector),
	list(cpy.list) {}

PmergeMe::PmergeMe(std::string const &seq)
{
	std::string	tmp;
	uint32_t	val;

	this->checkSeq(seq);
	tmp = seq;
	tmp.erase(0, tmp.find_first_not_of(WSPACE));
	tmp.erase(tmp.find_last_not_of(WSPACE) + 1);
	while (tmp.size())
	{
		val = std::stoul(tmp);
		this->vector.push_back(val);
		this->list.push_back(val);
		tmp.erase(0, tmp.find_first_not_of(DIGIT));
		tmp.erase(0, tmp.find_first_not_of(WSPACE));
	}
}

PmergeMe::~PmergeMe(void) {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &cpy)
{
	this->vector_time = cpy.vector_time;
	this->list_time = cpy.list_time;
	this->vector = cpy.vector;
	this->list = cpy.list;
	return (*this);
}

PmergeMe	&PmergeMe::operator=(std::string const &seq)
{
	std::string	tmp;
	uint32_t	val;

	this->checkSeq(seq);
	tmp = seq;
	tmp.erase(0, tmp.find_first_not_of(WSPACE));
	tmp.erase(tmp.find_last_not_of(WSPACE) + 1);
	this->vector_time = this->vector_time.zero();
	this->list_time = this->list_time.zero();
	this->vector.clear();
	this->list.clear();
	while (tmp.size())
	{
		val = std::stoul(tmp);
		this->vector.push_back(val);
		this->list.push_back(val);
		tmp.erase(0, tmp.find_first_not_of(DIGIT));
		tmp.erase(0, tmp.find_first_not_of(WSPACE));
	}
	return (*this);
}

std::ostream	&PmergeMe::operator>>(std::ostream &os)
{
	std::vector<uint32_t>::iterator	vit;

	os << "Unsorted sequence:";
	for (vit = this->vector.begin(); vit != vector.end(); ++vit)
		os << " " << *vit;
	//this->sortVector();
	//this->sortList();
	std::chrono::system_clock::time_point	now(std::chrono::system_clock().now());
	while (this->vector_time.count() < 10)
		this->vector_time = std::chrono::system_clock().now() - now;
	os << std::endl << "Sorted sequence:";
	for (vit = this->vector.begin(); vit != vector.end(); ++vit)
		os << " " << *vit;
	os << std::endl << "Time to process a range of " << vector.size() << " ele";
	os << "ments with std::vector: " << this->vector_time.count();
	os << std::endl << "Time to process a range of " << list.size() << " eleme";
	os << "nts with std::vector: " << this->list_time.count();
	return (os);
}

void	PmergeMe::checkSeq(std::string const &seq)
{
	if (!seq.size())
		throw (Error(ESYN));
	if (seq.find_first_of(DIGIT) == std::string::npos)
		throw (Error(ESYN));
	if (seq.find_first_not_of(UINTSEQ) != std::string::npos)
		throw (Error(ESYN));
}
