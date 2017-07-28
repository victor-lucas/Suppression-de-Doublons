SRC	=	trie.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-Iinclude

NAME	=	out

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g -g3 -o $(NAME) $(OBJ) $(CFLAGS) -L. -lgnl

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean re
