##
## EPITECH PROJECT, 2018
## PSU_my_sokoban_2018
## File description:
## makefile
##

EXEC_NAME = my_sokoban

TEST_EXEC_NAME = cr_test

MAIN =		my_sokoban.c    \
		fs_open_file.c  \
		my_mouv_p.c \
		my_map.c    \
		my_putstr.c

SRCS =

TEST_SRCS =

C_FLAGS = -fno-builtin -W -Wall -lm -lncurses

all	:
		make $(EXEC_NAME)

$(EXEC_NAME):	$(OBJS)
		gcc $(C_FLAGS) -o $(EXEC_NAME) $(addprefix source/, $(MAIN) $(SRCS))

test_run:
		gcc -o $(TEST_EXEC_NAME) $(SRCS) $(TEST_SRCS) $(LIB) --coverage -lcriterion

clean:
		rm -f $(OBJS) $(MAIN:.c=.o)

fclean:		clean
		rm -f $(EXEC_NAME)

cclean:		fclean
		rm -f *.gcda *.gcno

re:		fclean all

test_re:	cclean test_run
