# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 14:50:06 by maltun            #+#    #+#              #
#    Updated: 2023/07/29 02:10:46 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
PUSHSWAP_SRC = ft_pushswap.c ft_check_error.c ft_operations.c ft_operations_2.c ft_operations_3.c

OBJ=$(PUSHSWAP_SRC:.c=.o)

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

all: libft $(NAME)
	@echo "$(GREEN)****** Push Swap Compiled Succesfuly ******"

rainbow_title:
	@clear
	@echo "$(MAGENTA) ██▓███   █    ██   ██████  ██░ ██      ██████  █     █░ ▄▄▄       ██▓███  "
	@echo "▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒   ▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒"
	@echo "▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░   ░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒"
	@echo "▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██      ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒"
	@echo "▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓   ▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░"
	@echo "▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒   ▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░"
	@echo "░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░   ░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░     "
	@echo "░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░   ░  ░  ░    ░   ░    ░   ▒   ░░       "
	@echo "            ░           ░   ░  ░  ░         ░      ░          ░  ░        	$(YELLOW)By maltun$(RESET)"
	

libft: rainbow_title
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF_DIR)/libftprintf.a

.c.o:
	@$(CC) -c $(CFLAGS) $<

clean: rainbow_title
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR)/libft clean
	@rm -rf $(OBJ)
	@echo "$(GREEN)****** Cleaned ******"

fclean: clean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR)/libft fclean
	@rm -f push_swap

re: fclean all

.PHONY: all libft clean fclean re