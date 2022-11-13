/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:10:32 by alfux             #+#    #+#             */
/*   Updated: 2022/11/13 03:19:21 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template <typename T> typename T::iterator easyfind(T &, long long);

# include "easyfind.tpp"
#endif
