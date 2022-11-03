# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:15:40 by alfux             #+#    #+#              #
#    Updated: 2022/11/03 02:50:45 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp		\
			IMateriaSource.hpp MateriaSource.hpp

SRC		=	AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp Character.cpp		\
			IMateriaSource.cpp MateriaSource.cpp main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Wextra -Werror -Wshadow -std=c++98 -g

CC		=	c++

NAME	=	test

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
