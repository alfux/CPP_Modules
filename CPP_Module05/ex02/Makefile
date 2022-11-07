# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 01:47:45 by alfux             #+#    #+#              #
#    Updated: 2022/11/07 03:01:17 by alfux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR		=	Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp 				\
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp				\

SRC		=	Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp 				\
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp		\

OBJ		=	$(SRC:%.cpp=%.o)

OPT		=	-Wall -Werror -Wextra -Wshadow -std=c++98 -g

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
			@(echo objects deleted)

fclean	:	clean
			@(rm -rf $(NAME))
			@(echo $(NAME) deleted)

re		:	fclean all

.PHONY	:	all clean fclean re
