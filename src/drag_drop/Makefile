##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CPPFLAGS = -I ../include
CPPFLAGS +=	-lcsfml-graphics
CPPFLAGS +=	-lcsfml-audio
CPPFLAGS += -lcsfml-system
CPPFLAGS += -lcsfml-window

SRC	+=	sprite_create.c
SRC	+=	drag_drop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libdrag_drop.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean