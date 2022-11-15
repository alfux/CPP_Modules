# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 22:05:57 by alfux             #+#    #+#              #
#    Updated: 2022/11/14 19:11:00 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	MutantStack.hpp MutantStack.tpp

SRC		=	main.cpp

OBJ		=	main.o

OPT		=	-Wall -Wextra -Werror -Wshadow -std=c++98 -g

CC		=	c++

NAME	=	mutantStack

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $@ linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $@ compiled)

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo objects removed)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo $(NAME) removed)

re		:	fclean all

.PHONY	:	all clean fclean re
