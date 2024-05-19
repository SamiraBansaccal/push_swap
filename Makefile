# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 03:23:28 by sabansac          #+#    #+#              #
#    Updated: 2024/05/18 23:30:45 by sbansacc         ###   ########.fr        #
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
	push_swap_radix.c \

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