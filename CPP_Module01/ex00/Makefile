# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 20:17:30 by alfux             #+#    #+#              #
#    Updated: 2022/10/24 02:54:35 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Zombie.hpp

SRC		=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

CC		=	c++

NAME	=	zombie

RED		=	\033[31m

GREEN	=	\033[32m

GREY	=	\033[90m

WHITE	=	\033[0m

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo "$(GREEN)$(NAME) linked$(WHITE)")

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo "$(GREY)$@ compiled$(WHITE)")

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo "$(RED)object files deleted$(WHITE)")

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo "$(RED)$(NAME) deleted$(WHITE)")

re		:	fclean all

.PHONY	:	all clean fclean re
