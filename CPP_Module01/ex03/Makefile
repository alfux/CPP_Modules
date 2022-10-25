# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 00:52:35 by alfux             #+#    #+#              #
#    Updated: 2022/10/25 01:13:20 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
HDR		=	Weapon.hpp HumanA.hpp HumanB.hpp

SRC		=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -std=c++98 -g

CC		=	c++

NAME	=	fight

$(NAME)	:	$(OBJ)
			@($(CC) $(OPT) $(OBJ) -o $@)
			@(echo "$@ linked")

%.o		:	%.cpp $(HDR)
			@($(CC) $(OPT) -c $< -o $@)
			@(echo "$@ compiled")

all		:	$(NAME)

clean	:
			@(rm -rf $(OBJ))
			@(echo "objects cleaned")

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo "$(NAME) deleted")

re		:	fclean all

.PHONY	:	all clean fclean re
