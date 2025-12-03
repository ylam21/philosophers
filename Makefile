# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 13:26:11 by omaly             #+#    #+#              #
#    Updated: 2025/12/03 19:08:30 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
NAME := $(BIN_DIR)/philo

# Compiler settings
CC := cc
CFLAGS :=	-Wall \
			-Wextra \
			-Werror

# Build tools
RM = rm -rf

# Source files
MAIN_SRCS =	src/philo.c \
			src/input_checker.c \
			src/error.c

SRCS = $(MAIN_SRCS)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) \
	-o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR) $(BIN_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
