# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 21:41:54 by alfux             #+#    #+#              #
#    Updated: 2022/10/26 03:12:18 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Harl.hpp

SRC		=	main.cpp Harl.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Wextra -Werror -std=c++98 -g

CC		=	c++

NAME	=	HarlFilter

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $(NAME) linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $@ compiled)

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo $(OBJ) deleted)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo $(NAME) deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
