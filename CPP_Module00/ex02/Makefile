# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 20:50:07 by alfux             #+#    #+#              #
#    Updated: 2022/10/20 19:53:45 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	tests.cpp Account.cpp

OBJ		=	$(SRC:%.cpp=%.o)

HDR		=	Account.hpp

OPTIONS	=	-Wall -Werror -Wextra -std=c++98

CC		=	c++

NAME	=	account

GREEN	=	\033[32m

RED		=	\033[31m

GREY	=	\033[90m

WHITE	=	\033[0m

$(NAME)	:	$(OBJ)
			@($(CC) $(OPTIONS) $(OBJ) -o $@)
			@(echo "$(GREEN)$@ linked$(WHITE)")

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPTIONS) -c $< -o $@)
			@(echo "$(GREY)$@ comipled$(WHITE)")

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo "$(RED)object files cleaned$(WHITE)")

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo "$(RED)$@ erased$(WHITE)")

re		:	fclean all

.PHONY	:	all clean fclean re
