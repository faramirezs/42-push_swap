# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alramire <alramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 11:33:51 by alramire          #+#    #+#              #
#    Updated: 2024/08/07 15:41:53 by alramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I./include
SRCS = inputs.c stack.c stack_sorting.c moves.c target_pos.c free_args.c positions.c index.c sort.c cost.c cheap_move.c sources.c ft_split.c main.c
OBJS = $(SRCS:.c=.o)
AR = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
