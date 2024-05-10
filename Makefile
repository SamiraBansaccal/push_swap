# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabansac <sabansac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 03:23:28 by sabansac          #+#    #+#              #
#    Updated: 2024/05/10 20:40:16 by sabansac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
SRCDIR = src/
INCLDIR = includes/
CFLAGS = -Wall -Wextra -Werror -I$(INCLDIR)
LFLAGS = -L$(INCLDIR) -lft -lftprintf

SRC_FILES = main.c \
	push_swap.c \
	push_swap_radix.c \

SRC = $(addprefix $(SRCDIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(SRCDIR)%.o: $(SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LFLAGS)


clean:
	rm -f $(SRCDIR)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re