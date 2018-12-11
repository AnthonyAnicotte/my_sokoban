##
## EPITECH PROJECT, 2018
## makefile
## File description:
## task1
##

SRC	=   my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) copy clean

$(NAME):	$(OBJ)
	ar  rc	$(NAME) $(OBJ)

copy:
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
