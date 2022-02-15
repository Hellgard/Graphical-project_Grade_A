##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC = 	create_game.c \
		create_hunt.c \
		duckhunt.c \
		game_one.c \
		game_two.c \
		my_put.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include

NAME = my_hunter

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -lcsfml-audio -lcsfml-system -lcsfml-window -lcsfml-graphics


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
