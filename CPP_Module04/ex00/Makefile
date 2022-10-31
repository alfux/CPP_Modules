# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 02:57:32 by alfux             #+#    #+#              #
#    Updated: 2022/10/31 04:12:44 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Animal.hpp Dog.hpp Cat.hpp

SRC		=	Animal.cpp Dog.cpp Cat.cpp main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Wextra -Werror -Wshadow -std=c++98 -g

CC		=	c++

NAME	=	test

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $@ linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $@ compiled)

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo objects deleted)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo $(NAME) deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
