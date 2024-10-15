# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bclaeys <bclaeys@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 12:39:18 by bclaeys           #+#    #+#              #
#    Updated: 2024/09/12 13:55:57 by bclaeys          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CFILES=src/push_swap.c src/ps_utils.c src/ps_free_all.c src/ps_push.c \
src/ps_rotate.c src/ps_swap.c src/ps_push_min_max.c src/ps_hardcodes.c\
src/ps_algorithm.c src/ps_cost_calculator.c src/ps_error_management.c
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
INCFLAGS= -I libft -L libft -lft 
INCLUDES = -I ./libft
LIBFT=./libft/libft.a
OBJECTS=$(patsubst src/%.c,obj/%.o,$(CFILES))

all: $(LIBFT) $(MLX) obj $(NAME)
	
$(LIBFT):
	@echo "\033[33m[ .. ] | Compiling libft...\033[0m"
	@make -s -C libft 	
	@echo "\033[33m[OK] | libft ready!\033"

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(INCFLAGS)
	@echo "\033[33mpush_swap created\033[0m"

obj: 
	@mkdir -p obj

obj/%.o:src/%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@rm -rf obj
	@if [ -d "obj" ]; then rmdir obj/; \
	fi
	@make -s $@ -C libft
	@echo "\033[33mAll object files, dependency files, archive files and test files removed.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33mBinary removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re test libft obj 
