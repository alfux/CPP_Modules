# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 19:24:23 by alfux             #+#    #+#              #
#    Updated: 2022/10/24 23:33:32 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC		=	main.cpp

OBJ		=	main.o

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

NAME	=	demystify

CC		=	c++

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo "$(NAME) linked")

%.o		:	%.cpp
			@($(CC) $(OPT) -c $< -o $@)
			@(echo "$@ compiled")

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo "object files deleted")

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo "$(NAME) deleted")

re		:	fclean all

.PHONY	:	all clean fclean re
