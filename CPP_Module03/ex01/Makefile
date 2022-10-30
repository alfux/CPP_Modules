# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 00:50:39 by alfux             #+#    #+#              #
#    Updated: 2022/10/30 03:05:47 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	ClapTrap.hpp ScavTrap.hpp

SRC		=	main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

CC		=	c++

NAME	=	action

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $(NAME) linked)

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo $< compiled into $@)

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo object files deleted)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo $(NAME) deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
