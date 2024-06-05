# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 22:48:47 by fursini           #+#    #+#              #
#    Updated: 2024/06/05 20:22:31 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bureaucrat
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f
SRC		=	main.cpp Bureaucrat.cpp Form.cpp \



OBJ		=	$(SRC:.cpp=.o)


$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re:		fclean all

leak: re
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=leaks.txt ./$(NAME)

.PHONY: all clean fclean re
