##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC =	manage_enemy.c \
		manage_info.c \
		manage_move.c \
		player_collision.c \
		runner.c \
		my_put.c \
		get_score.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include

NAME = my_runner

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) -lcsfml-audio -lcsfml-system -lcsfml-window -lcsfml-graphics


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
