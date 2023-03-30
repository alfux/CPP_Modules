# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 17:25:57 by alfux             #+#    #+#              #
#    Updated: 2023/03/30 04:16:26 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	BitcoinExchange.hpp Date.hpp Error.hpp

SRC		=	BitcoinExchange.cpp Date.cpp Error.cpp main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

CFLAGS	+=	-Wall -Wextra -Werror -std=c++98

INC		=	-I./

CC		=	c++

NAME	=	btc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

%.o		:	%.cpp $(HDR)
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

fclean	:	clean
			rm -rf $(NAME)

clean	:
			rm -rf $(OBJ)

re		:	fclean all

.PHONY	:	all fclean clean re
