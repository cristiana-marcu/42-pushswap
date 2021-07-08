# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 11:58:16 by cmarcu            #+#    #+#              #
#    Updated: 2021/07/06 13:55:59 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c rule_swap.c rule_push.c rule_rotate.c lst_utils.c \
		error_checking.c sorter.c chunker.c ruler.c

SRCS_BONUS = rule_swap.c rule_push.c rule_rotate.c lst_utils.c \
		error_checking.c get_next_line.c checker.c ruler.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = push_swap

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g3 -fsanitize=address
LDFLAGS = -g3 -fsanitize=address -L$(LIBFTPATH) -lft
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

bonus: $(OBJS_BONUS)
	@$(CC) $(LDFLAGS) $(OBJS_BONUS) -I $(INCLUDES) -o checker

ARG :=	$(shell seq 0 10 | sort -R)

exe: $(NAME)
	./push_swap $(ARG)

check: $(NAME)
	./push_swap $(ARG) | ./checker_Mac $(ARG)

check_bonus: $(NAME) bonus
	@echo Official checker
	./push_swap $(ARG) | ./checker_Mac $(ARG)
	@echo My checker
	./push_swap $(ARG) | ./checker $(ARG)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
