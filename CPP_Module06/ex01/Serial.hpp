/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serial.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:02:25 by alfux             #+#    #+#             */
/*   Updated: 2022/11/10 02:32:07 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SERIAL_HPP
# define SERIAL_HPP
# include <iostream>
# include <cstdint>

struct	Data
{
	char	dummy;
	int		dummy_;
	float	_dummy;
	double	dduummmmyy;
};

uintptr_t	serialize(Data *);
Data		*deserialize(uintptr_t);

#endif
