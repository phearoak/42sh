##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	= gcc

CFLAGS	= -W -Wall -Wextra
CFLAGS	+= -lncurses
CFLAGS	+= -I ./include
CFLAGS	+= -I ./src/gobblings/include
CFLAGS	+= -I ./src/backtick/include
CFLAGS	+= -I ./src/history/include
CFLAGS	+= -I ./src/variables/include
CFLAGS	+= -I ./src/line_edit/include
CFLAGS	+= -I ./src/alias/include
CFLAGS	+= -I ./src/builtins/include
CFLAGS	+= -I ./src/termios/include
CFLAGS	+= -I ./src/foreach/include
CFLAGS	+= -I ./src/if/include

CLIB	= -L ./lib/my -lmy

LIB	= ./lib/my/libmy.a

SRC	= $(wildcard src/*.c)
SRC	+= $(wildcard src/gobblings/*.c)
SRC	+= $(wildcard src/backtick/*.c)
SRC	+= $(wildcard src/history/*.c)
SRC	+= $(wildcard src/inhibitors/*.c)
SRC	+= $(wildcard src/variables/*.c)
SRC	+= $(wildcard src/line_edit/*.c)
SRC	+= $(wildcard src/quotes/*.c)
SRC	+= $(wildcard src/alias/*.c)
SRC	+= $(wildcard src/builtins/*.c)
SRC	+= $(wildcard src/termios/*.c)
SRC	+= $(wildcard src/scripting/*.c)
SRC	+= $(wildcard src/foreach/*.c)
SRC	+= $(wildcard src/if/*.c)

OBJ	= $(SRC:.c=.o)

TARGET_TEST	= $(wildcard ./src/gobblings/*.c)
TARGET_TEST	+= $(wildcard ./lib/my/*.c)
TARGET_TEST	+= ./src/line_edit/add_at_index.c
TARGET_TEST	+= ./src/count_str.c
TARGET_TEST	+= ./src/dup_min_max.c
TARGET_TEST	+= ./src/not_command.c
TARGET_TEST	+= ./src/show_env.c
TARGET_TEST	+= ./src/variables/is_alphanum.c
TARGET_TEST	+= ./src/variables/delete_slash.c

SRC_TEST	= $(wildcard tests/*.c)
SRC_TEST	+= $(wildcard tests/tests_lib/*.c)

BIN = 42sh

all: $(BIN)

$(BIN): $(LIB) $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS) $(CLIB)

$(LIB):
	make -C ./lib/my/

tests_run: $(LIB)
	$(CC) $(CFLAGS) -o test $(SRC_TEST) $(TARGET_TEST) $(CLIB) --coverage -lcriterion
	./test

clean:
	$(RM) *~
	$(RM) #*#
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	make clean -C ./lib/my/

fclean: clean
	$(RM) $(BIN)
	$(RM) test
	make fclean -C ./lib/my/

re: fclean all
