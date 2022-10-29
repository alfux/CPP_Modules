# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 06:33:36 by alfux             #+#    #+#              #
#    Updated: 2022/10/29 07:37:25 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Fixed.hpp Point.hpp

SRC		=	main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

CC		=	c++

NAME	=	gSpot

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $@ linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $@ compiled)

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo object fils deleted)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo exec deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
