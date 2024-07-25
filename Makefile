# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alramire <alramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 11:33:51 by alramire          #+#    #+#              #
#    Updated: 2024/07/25 19:06:34 by alramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include -I./libft
LIBFT = ./libft/libft.a
# SRCS = *.c
SRCS = inputs.c stack.c moves.c main.c
# OBJS = *.o
OBJS = $(SRCS:.c=.o) # This is a substitution pattern, where the files ends with c it replaces with o
AR = ar rc
RM = rm -f
LIB	= ranlib

all: libft $(NAME)

libft:
	@make -C ./libft
	@$(AR) libft.a $(wildcard ./libft/*.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJS) -L./libft -o $(NAME)
#$(CC) $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJS) -L./libft -lft

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

#$(NAME): libft $(SRCS)
#	$(CC) $(FLAGS) $(INCLUDE) -c $(SRCS)
#	$(AR) $(NAME) $(OBJS)
#	$(LIB) $(NAME)
#	chmod +x $(NAME)

#$(NAME):
#	$(CC)  $(FLAGS) $(SRCS)
#	$(AR)  $(NAME) $(OBJS)
#	$(LIB) $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
