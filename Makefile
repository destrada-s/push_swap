# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: destrada <destrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:57:35 by destrada          #+#    #+#              #
#    Updated: 2022/12/13 20:30:12 by destrada         ###   ########.fr        #
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
		utils_calculations.c

SRCS_BONUS =	utils_command_stack.c \
				utils_command_stack2.c \
				utils_pos_stack.c \
				utils_lists_others.c \
				utils_linked_lists.c \
				utils_checks.c \
				checker.c 
				

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

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

bonus:	$(OBJS_BONUS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)

clean:
	$(RM) $(OBJS) 
	@make clean -C $(LIB_DIR)

fclean: clean
		@make fclean -C $(LIB_DIR)
		$(RM) $(NAME) 
		$(RM) $(LIBFT)
		

re: fclean all

.PHONY: all clean fclean re
