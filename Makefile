NAME 		= push_swap
CHECK		= checker

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1
CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		=

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= algo_utilis.c\
			  best_sort.c\
			  config.c\
			  get.c\
			  high_sort.c\
			  instruction.c\
			  instruction_utilis.c\
			  main.c\
			  merge_sort.c\
			  new_instruction.c\
			  push_swap.c\
			  quick_sort.c\
			  radix_sort.c\
			  script.c\
			  skip_instruction.c\
			  tab.c

CHECK_SRC	= algo_utilis.c\
			  bonus/checker.c\
			  bonus/main.c\
			  best_sort.c\
			  config.c\
			  get.c\
			  high_sort.c\
			  instruction.c\
			  instruction_utilis.c\
			  merge_sort.c\
			  new_instruction.c\
			  push_swap.c\
			  quick_sort.c\
			  radix_sort.c\
			  script.c\
			  skip_instruction.c\
			  tab.c

OBJ 		= $(SRC:.c=.o)
CHECK_OBJ	= $(CHECK_SRC:.c=.o)

all: $(NAME)

bonus: $(CHECK)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(CLINKS)

$(CHECK): $(LIBFT) $(CHECK_OBJ)
	$(CC) $(CFLAGS) -o $(CHECK) $(CHECK_OBJ) $(LIBFT) $(CLINKS)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

$(FT):
	$(CLONE) https://github.com/kodokaii/libft_plus_plus.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	if [ -d "$(FT)" ]; then $(MAKE) clean -C $(FT); fi
	$(RM) $(OBJ)
	$(RM) $(CHECK_OBJ)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(CHECK)

clear: fclean
	$(RM) -r $(FT)

re: fclean all

.PHONY:		all bonus clear clean fclean re
