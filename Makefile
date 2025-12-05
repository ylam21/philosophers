# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 13:26:11 by omaly             #+#    #+#              #
#    Updated: 2025/12/05 15:44:11 by omaly            ###   ########.fr        #
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
MAIN_SRCS =	src/philosophers.c \
			src/input_checker.c \
			src/data_setup.c \
			src/forks_setup.c \
			src/philos_setup.c \
			src/run_simulation.c \
			src/read_flag.c \
			src/write_flag.c \
			src/write_status.c \
			src/routine.c \
			src/allocate_threads.c \
			src/error.c \
			src/cleanup.c \
			src/get_timestamp_millisec.c

UTILS_SRCS =	src/utils/ft_isdigit.c \
				src/utils/ft_aatoi.c \
				src/utils/is_whitespace.c

SRCS = $(MAIN_SRCS) $(UTILS_SRCS)

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
