NAME=libftprintf.a
SRCS=ft_printf.c ft_print_helper.c
OBJS=$(SRCS:.c=.o)
RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)
	@echo "$(GREEN)****** Printf Compiled Succesfuly ******$(RESET)"

$(NAME): $(OBJS)
	@make bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $@ $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
