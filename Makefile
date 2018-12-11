##
## EPITECH PROJECT, 2018
## makefile
## File description:
## lib
##

SRC	=	src/main.c  \
		src/key_up.c	\
		src/key_down.c	\
		src/key_left.c	\
		src/key_right.c	\
		src/error_handling.c	\
		src/tool_functions.c	\
		src/space_bar.c	\
		src/error_functions.c   \
		src/error_function_two.c    \
		src/replace_storage.c   \
		src/check_the_win.c

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Wextra -lncurses -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)

clean:	
		rm -f $(OBJ)
		rm -rf *~
		rm -rf src/*~

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all
