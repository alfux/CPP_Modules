# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 18:55:46 by alfux             #+#    #+#              #
#    Updated: 2022/11/09 11:11:36 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Convert.hpp

SRC		=	Convert.cpp main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Wextra -Werror -Wshadow -std=c++98 -g

CC		=	c++

NAME	=	convert

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
