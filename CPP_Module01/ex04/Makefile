# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 05:48:30 by alfux             #+#    #+#              #
#    Updated: 2022/10/25 07:47:53 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HDR		=	RStream.hpp

SRC		=	main.cpp RStream.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Wextra -Werror -std=c++98 -g

CC		=	c++

NAME	=	replace

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo $@ linked)

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
