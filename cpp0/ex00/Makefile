# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 22:40:49 by fursini           #+#    #+#              #
#    Updated: 2024/05/26 22:40:50 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f
SRC		=	./Megaphone.cpp


$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

all:	$(NAME)

clean:
			$(RM) $(NAME)

fclean: clean

re:		fclean all

.PHONY: all clean fclean re
