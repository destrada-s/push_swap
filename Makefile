# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: destrada <destrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:57:35 by destrada          #+#    #+#              #
#    Updated: 2022/12/07 15:50:06 by destrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c \
		utils_command_stack.c \
		utils_command_stack2.c \
		utils_pos_stack.c \
		utils_command_sort_stack.c \
		utils_lists_others.c \
		utils_linked_lists.c \
		utils_sort_algorithm.c

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

LIB_DIR = mega_libft/

LIBFT = libft.a

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS) 
	@make clean -C $(LIB_DIR)

fclean: clean
		@make fclean -C $(LIB_DIR)
		$(RM) $(NAME) 
		$(RM) $(LIBFT)
		

re: fclean all

.PHONY: all clean fclean re
