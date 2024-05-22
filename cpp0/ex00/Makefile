NAME	=	megaphone
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -f
SRC	=	./Megaphone.cpp


$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

all:	$(NAME)

clean:
			$(RM) $(NAME)

fclean: clean

re:		fclean all

.PHONY: all clean fclean re
