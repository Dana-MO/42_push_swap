NAME = push_swap.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJS = $(LIBFT_DIR)/*.o

SRC = main.c stack_init.c init_a_nodes.c init_b_nodes.c stack_sort.c sort_multiple.c \
		stack_utils.c check_input.c stack_push.c stack_reverse.c stack_rotate.c stack_swap.c

OBJ =  $(SRC:%.c=%.o)
		 
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	ar -rcs $(NAME) $(OBJ) $(LIBFT_OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re