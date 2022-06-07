##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/ -lmylibrary

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

SRC		=	src/

SRCS_C = $(shell find src -name "*.c")

CFLAGS = -I./include -g

NAME = my_rpg

all: $(NAME)

libmylibrary:
	make re -C lib/my_library/

$(NAME): libmylibrary $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS) $(LIB) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my_library/

re:	fclean all
	make clean
