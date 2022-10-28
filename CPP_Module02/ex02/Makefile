# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 06:33:36 by alfux             #+#    #+#              #
#    Updated: 2022/10/28 05:42:09 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Fixed.hpp

SRC		=	main.cpp Fixed.cpp

SRCT	=	myTests.cpp Fixed.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OBJT	=	$(SRCT:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

CC		=	c++

NAME	=	fixed

NAMET	=	mytests

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $@ linked)

$(NAMET):	$(OBJT)
			@($(CC) $(OPT) $(OBJT) -o $@)
			@(echo $@ linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $@ compiled)

all		:	$(NAME) $(NAMET)

clean	:
			@(rm -rf $(OBJ) $(OBJT))
			@(echo object fils deleted)

fclean	:	clean
			@(rm -rf $(NAME) $(NAMET))
			@(echo exec deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
