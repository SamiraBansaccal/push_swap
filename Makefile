# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 03:23:28 by sabansac          #+#    #+#              #
#    Updated: 2024/05/26 04:47:25 by sabansac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
SRCDIR = src/
INCLDIR = includes/
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LFLAGS = -I$(INCLDIR) -L$(INCLDIR) -lft -lftprintf

SRC_FILES = main.c \
	push_swap.c \
	radix_sort.c \
	double_radix.c \
	mini_sort.c \
	args_validity.c \
	optimised_cmd.c \
	malloc_stuff.c \
	map_to_ranks.c \

SRC = $(addprefix $(SRCDIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(SRCDIR)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@

clean:
	rm -f $(SRCDIR)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re