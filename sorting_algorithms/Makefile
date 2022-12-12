# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: destrada <destrada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:57:35 by destrada          #+#    #+#              #
#    Updated: 2022/11/29 14:03:12 by destrada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		sorting_algorithms.c \
		sorting_algorithms2.c

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

LIB_DIR = ../mega_libft/

LIBFT = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

NAME = sorting

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT) .
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) 

clean:
	$(RM) $(OBJS) 
	@make clean -C $(LIB_DIR)

fclean: clean
		$(RM) $(NAME) 
		$(RM) $(LIBFT)
		$(RM) $(LIB_DIR)$(LIBFT)

re: fclean all

.PHONY: all clean fclean re