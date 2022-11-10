/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:08:53 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 02:11:24 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Serial.hpp"

uintptr_t	serialize(Data *ptr)
	{return (reinterpret_cast<uintptr_t> (ptr));}

Data	*deserialize(uintptr_t raw)
	{return (reinterpret_cast<Data *> (raw));}
