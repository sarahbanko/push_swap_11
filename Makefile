NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -Istack -Ioperations -Iparsing -Ialgorithms -Iutils

SHARED		= utils/ft_utils.c \
			  utils/ft_split.c \
			  utils/ft_string.c \
			  parsing/args_builder.c \
			  stack/stack_init.c \
			  stack/stack_push.c \
			  stack/stack_pop.c \
			  stack/stack_utils.c \
			  operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/rev_rotate.c \
			  operations/opcount.c \
			  parsing/parsing.c \
			  parsing/parsing_utils.c \
			  algorithms/disorder.c \
			  algorithms/medium_a_utils.c \
			  algorithms/medium_b_utils.c \
			  algorithms/sort_simple.c \
			  algorithms/sort_medium.c \
			  algorithms/sort_complex.c \
			  algorithms/sort_adaptive.c \
			  algorithms/bench.c

PS_SRCS		= main.c

PS_OBJS		= $(SHARED:.c=.o) $(PS_SRCS:.c=.o)

$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(PS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
