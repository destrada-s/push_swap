# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: destrada <destrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:57:35 by destrada          #+#    #+#              #
#    Updated: 2022/12/21 15:53:15 by destrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		push_swap.c \
		utils_command_stack.c \
		utils_command_stack2.c \
		utils_pos_stack.c \
		utils_command_sort_stack.c \
		utils_lists_others.c \
		utils_linked_lists.c \
		utils_sort_algorithm.c \
		general_algorithm.c \
		utils_checks.c \
		utils_more.c \
		utils_calculations.c 

SRCS_BONUS =	utils_command_stack.c \
				utils_command_stack2.c \
				utils_pos_stack.c \
				utils_lists_others.c \
				utils_linked_lists.c \
				utils_checks.c \
				checker.c \
				utils_more.c \
				utils_init_bonus.c \
				utils_checker_bonus.c
				

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar -rcs

LIB_DIR = mega_libft/

LIBFT = libft.a

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

NAME_BONUS = checker

all: libft $(NAME)

$(NAME): $(OBJS)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

libft:
	@make -C $(LIB_DIR)

bonus: libft $(NAME_BONUS) 

$(NAME_BONUS): $(OBJS_BONUS)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)
clean:
	$(RM) $(OBJS) $(OBJS_BONUS) 
	@make clean -C $(LIB_DIR)

fclean: clean
		@make fclean -C $(LIB_DIR)
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) $(LIBFT)
		

re: fclean all

.PHONY: all clean fclean re
