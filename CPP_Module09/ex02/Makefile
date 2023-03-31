# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 17:25:57 by alfux             #+#    #+#              #
#    Updated: 2023/03/31 07:15:32 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	PmergeMe.hpp Error.hpp

SRC		=	PmergeMe.cpp Error.cpp main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

CFLAGS	+=	-Wall -Wextra -Werror -std=c++98

INC		=	-I./

CC		=	c++

NAME	=	PmergeMe

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
