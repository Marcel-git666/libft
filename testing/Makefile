# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 21:40:51 by mmravec           #+#    #+#              #
#    Updated: 2024/09/03 22:46:43 by mmravec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = test
CC = gcc-14
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_PATH = ../ 
LIBFT = $(LIBFT_PATH)libft.a

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Target to create the test executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

# Rule to make libft.a by calling the Makefile in libft directory
$(LIBFT):
	make -C $(LIBFT_PATH)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Phony targets to avoid confusion with files of the same name
.PHONY: all clean fclean re

# Target to compile everything
all: $(NAME)

# Clean up object files in the testing directory
clean:
	rm -f $(OBJS)

# Clean up everything that can be rebuilt
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all
