# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fursini <fursini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 22:41:40 by fursini           #+#    #+#              #
#    Updated: 2024/05/26 22:41:41 by fursini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f
SRC		=	./PhoneBook.cpp \
			./Contact.cpp \
			./main.cpp

OBJ		=	$(SRC:.cpp=.o)


$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
