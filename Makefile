NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I. -Istack -Ioperations -Iparsing -Ialgorithms -Iutils

SHARED		= utils/ft_utils.c \
			  utils/ft_split.c \
			  parsing/args_builder.c \
			  stack/stack_init.c \
			  stack/stack_push.c \
			  stack/stack_pop.c \
			  stack/stack_utils.c \
			  operations/swap.c \
			  operations/push.c \
			  operations/rotate.c \
			  operations/rev_rotate.c \
			  parsing/parsing.c \
			  parsing/parsing_utils.c \
			  algorithms/disorder.c \
			  algorithms/medium_a_utils.c \
			  algorithms/medium_b_utils.c \
			  algorithms/sort_simple.c \
			  algorithms/sort_medium.c \
			  algorithms/sort_complex.c \
			  algorithms/sort_adaptive.c

PS_SRCS		= main.c
CH_SRCS		= checker_bonus/checker_main.c checker_bonus/op_silent.c

PS_OBJS		= $(SHARED:.c=.o) $(PS_SRCS:.c=.o)
CH_OBJS		= $(SHARED:.c=.o) $(CH_SRCS:.c=.o)

$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME)

$(BONUS): $(CH_OBJS)
	$(CC) $(CFLAGS) $(CH_OBJS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

bonus: $(BONUS)

clean:
	rm -f $(PS_OBJS) $(CH_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
