# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaly <omaly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 13:26:11 by omaly             #+#    #+#              #
#    Updated: 2026/03/16 15:40:01 by omaly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
SRC_DIR := src
BUILD_DIR := build
NAME := philo

# Compiler settings
CC		:= cc
CFLAGS	:=	-Wall \
			-Wextra \
			-Werror

# Build tools
RM = rm -rf

# Source files
SRCS =	src/main.c \
		src/input_checker.c \
		src/arena/arena.c \
		src/init/data_init.c \
		src/init/state_init.c \
		src/routine/routine.c \
		src/routine/eat_routine.c \
		src/routine/sleep_routine.c \
		src/routine/think_routine.c \
		src/simulation/simulation.c \
		src/simulation/monitor.c \
		src/utils/error.c \
		src/utils/ft_atoi.c \
		src/utils/ft_isdigit.c \
		src/utils/get_timestamp_millisec.c \
		src/utils/is_whitespace.c \
		src/utils/u32_rw_safe.c \
		src/utils/write_status.c

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) \
	-o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
