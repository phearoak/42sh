##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c)

OBJ = 	$(SRC:.c=.o)

LIB	= 	libmy.a

CFLAGS	= -W -Wall -Wextra
CFLAGS	+= 	-I ../../include

all: $(LIB)

$(LIB): $(OBJ)
	$(AR) rsc $(LIB) $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#

fclean: clean
	$(RM) $(LIB)

re: fclean all
