# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 03:00:39 by alfux             #+#    #+#              #
#    Updated: 2022/11/11 16:57:06 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	iter.hpp

SRC		=	main.cpp

OBJ		=	main.o

OPT		=	-Wall -Wextra -Werror -Wshadow -std=c++98 -g

CC		=	c++

NAME	=	iter

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
