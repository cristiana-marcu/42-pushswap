# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 11:58:16 by cmarcu            #+#    #+#              #
#    Updated: 2021/05/26 19:31:34 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g3 -fsanitize=address -L$(LIBFTPATH) -lft
RM = rm -f

INCLUDES = ./includes/

LIBFTPATH	= ./libft/
LIBFTNAME =	libft.a
LIBFT =	$(LIBFTPATH)$(LIBFTNAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES) -o $(NAME) $(LIBFT)

$(LIBFT):
	make re -C $(LIBFTPATH)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
