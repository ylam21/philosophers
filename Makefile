# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 13:26:11 by omaly             #+#    #+#              #
#    Updated: 2026/03/02 09:33:23 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
SRC_DIR := src
NAME := philo

# Compiler settings
CC := cc
CFLAGS :=	-Wall \
			-Wextra \
			-Werror

# Build tools
RM = rm -rf

all: $(NAME)

$(NAME): src/main.c
	$(CC) $(CFLAGS) src/main.c \
	-o $@

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
