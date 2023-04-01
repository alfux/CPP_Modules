/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:13:34 by alfux             #+#    #+#             */
/*   Updated: 2023/04/01 04:05:55 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe(void): vector_time(0), list_time(0) {}

PmergeMe::PmergeMe(PmergeMe const &cpy):
	vector_time(cpy.vector_time),
	list_time(cpy.list_time),
	vector(cpy.vector),
	list(cpy.list) {}

PmergeMe::PmergeMe(std::string const &seq)
{
	std::chrono::system_clock::time_point	start;
	std::string								tmp;

	start = std::chrono::system_clock().now();
	this->checkSeq(seq);
	this->trimCpy(tmp, seq);
	this->vector_time = std::chrono::system_clock().now() - start;
	this->list_time = this->vector_time;
	start = std::chrono::system_clock().now();
	while (tmp.size())
	{
		this->vector.push_back(std::stoul(tmp));
		tmp.erase(0, tmp.find_first_not_of(DIGIT));
		tmp.erase(0, tmp.find_first_not_of(WSPACE));
	}
	this->vector_time += std::chrono::system_clock().now() - start;
	this->trimCpy(tmp, seq);
	start = std::chrono::system_clock().now();
	while (tmp.size())
	{
		this->list.push_back(std::stoul(tmp));
		tmp.erase(0, tmp.find_first_not_of(DIGIT));
		tmp.erase(0, tmp.find_first_not_of(WSPACE));
	}
	this->list_time += std::chrono::system_clock().now() - start;
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
	*this = PmergeMe(seq);
	return (*this);
}

std::ostream	&PmergeMe::operator>>(std::ostream &os)
{
	std::chrono::system_clock::time_point	start;
	std::vector<uint32_t>::iterator			vit;

	os << "Unsorted sequence:";
	for (vit = this->vector.begin(); vit != vector.end(); ++vit)
		os << " " << *vit;
	start = std::chrono::system_clock().now();
	this->sort(this->vector);
	this->vector_time += std::chrono::system_clock().now() - start;
	start = std::chrono::system_clock().now();
	this->sort(this->list);
	this->list_time += std::chrono::system_clock().now() - start;
	os << std::endl << "Sorted sequence:  ";
	for (vit = this->vector.begin(); vit != vector.end(); ++vit)
		os << " " << *vit;
	os << std::endl << "Time to process a range of " << vector.size() << " ele";
	os << "ments with std::vector: " << this->vector_time.count() << "ms";
	os << std::endl << "Time to process a range of " << list.size() << " eleme";
	os << "nts with std::list: " << this->list_time.count() << "ms";
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

void	PmergeMe::trimCpy(std::string &dst, std::string const &src)
{
	dst = src;
	dst.erase(0, dst.find_first_not_of(WSPACE));
	dst.erase(dst.find_last_not_of(WSPACE) + 1);
}

void	PmergeMe::sort(std::vector<uint32_t> &seq)
{
	std::vector<uint32_t>			small;

	if (this->isSorted(seq))
		return ;
	while (seq.size() - small.size() > 1)
	{
		if (*seq.begin() < *(++seq.begin()))
		{
			small.push_back(*seq.begin());
			seq.erase(seq.begin());
		}
		else
		{
			small.push_back(*(++seq.begin()));
			seq.erase(++seq.begin());
		}
	}
	this->sort(seq);
	this->insert(small, seq);
}

void	PmergeMe::sort(std::list<uint32_t> &seq)
{
	std::list<uint32_t>				small;

	if (this->isSorted(seq))
		return ;
	while (seq.size() - small.size() > 1)
	{
		if (*seq.begin() < *(++seq.begin()))
		{
			small.push_back(*seq.begin());
			seq.pop_front();
		}
		else
		{
			small.push_back(*(++seq.begin()));
			seq.erase(++seq.begin());
		}
	}
	this->sort(seq);
	this->insert(small, seq);
}

void	PmergeMe::insert(std::vector<uint32_t> &small, std::vector<uint32_t> &big)
{
	std::vector<uint32_t>::iterator	it;

	while (small.size())
	{
		for (it = big.begin(); it < big.end() && *it < small[0]; ++it);
		big.insert(it, small[0]);
		small.erase(small.begin());
	}
}

void	PmergeMe::insert(std::list<uint32_t> &small, std::list<uint32_t> &big)
{
	std::list<uint32_t>::iterator	it;

	while (small.size())
	{
		for (it = big.begin(); it != big.end() && *it < *small.begin(); ++it);
		big.insert(it, *small.begin());
		small.pop_front();
	}
}

bool	PmergeMe::isSorted(std::vector<uint32_t> const &seq)
{
	std::vector<uint32_t>::const_iterator	it;

	if (!seq.size())
		return (true);
	for (it = ++seq.begin(); it < seq.end(); ++it)
		if (*std::prev(it) > *it)
			return (false);
	return (true);
}

bool	PmergeMe::isSorted(std::list<uint32_t> const &seq)
{
	std::list<uint32_t>::const_iterator	it;

	if (!seq.size())
		return (true);
	for (it = ++seq.begin(); it != seq.end(); ++it)
		if (*std::prev(it) > *it)
			return (false);
	return (true);
}
