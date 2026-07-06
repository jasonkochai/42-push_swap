CC = cc

NAME = push_swap

BONUS_NAME = checker

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

INC = -I. -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = \
	algo_utils.c \
	choose_algo.c \
	complex.c \
	disorder.c \
	error_handle.c \
	flags.c \
	helpers.c \
	input.c \
	main.c \
	medium.c \
	numbers.c \
	output.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	simple.c \
	stack_free.c \
	stack_setup.c \
	stack_utils.c \
	swap.c \
	tiny_sort.c \
	validation.c

CHECKER_SRCS = \
	algo_utils.c \
	checker_utils.c \
	checker.c \
	choose_algo.c \
	complex.c \
	disorder.c \
	error_handle.c \
	flags.c \
	helpers.c \
	input.c \
	medium.c \
	numbers.c \
	output.c \
	push.c \
	reverse_rotate.c \
	rotate.c \
	simple.c \
	stack_free.c \
	stack_setup.c \
	stack_utils.c \
	swap.c \
	tiny_sort.c \
	validation.c

OBJS = $(SRCS:.c=.o)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
