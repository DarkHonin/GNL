LIBTEST=${CURDIR}/../libtest
LIBFT=${CURDIR}/libft

LIBS = $(LIBFT) $(LIBTEST)

FLAGS=-I$(LIBTEST) -I$(LIBFT) -I. -L$(LIBTEST) -L$(LIBFT) -lft -ltest -Wextra -Wall -Werror

make: make_libs
	gcc $(FILE) get_next_line.c $(FLAGS) -o $(FILE).bin

make_libs:
	for i in $(LIBS); do \
		make -C $$i LIBFT=$(LIBFT); \
	done

