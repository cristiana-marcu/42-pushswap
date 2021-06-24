# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 11:58:16 by cmarcu            #+#    #+#              #
#    Updated: 2021/06/24 17:24:55 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c rule_swap.c rule_push.c rule_rotate.c lst_utils.c error_checking.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = -L$(LIBFTPATH) -lft
RM = rm -f

INCLUDES = ./includes/

LIBFTPATH	= ./libft/
LIBFTNAME =	libft.a
LIBFT =	$(LIBFTPATH)$(LIBFTNAME)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(LDFLAGS) $(OBJS) -I $(INCLUDES) -o $(NAME)

$(LIBFT):
	make re -C $(LIBFTPATH)

ARG :=	$(shell seq 0 100 | sort -R)

exe: $(NAME)
	./push_swap $(ARG)

check: $(NAME)
	./push_swap $(ARG) | ./checker_Mac $(ARG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
