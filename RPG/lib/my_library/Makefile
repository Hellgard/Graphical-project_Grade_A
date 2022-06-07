##
## EPITECH PROJECT, 2021
## d10
## File description:
##

SRC		=	 sources/

SRC_C	=	$(wildcard sources/*.c)

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

OBJ	= 	$(SRC_C:.c=.o) ##Quitar los .c

NAME	=	libmylibrary.a  ##Nombre archivo

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ) $(LIB)
		rm -f $(OBJ)
		cp $(NAME) ../
		cp ./includes/my_library.h ../../include/

all:	$(NAME)

copy:   $(COPY)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all clean
