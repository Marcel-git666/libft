# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmravec <mmravec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 22:02:38 by mmravec           #+#    #+#              #
#    Updated: 2024/09/05 15:39:20 by mmravec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a            # Name of the static library
CC = gcc-14                  # Compiler to use
CFLAGS = -Wall -Werror -Wextra # Compilation flags
SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_strlen.c ft_toupper.c ft_tolower.c
OBJS = $(SRCS:.c=.o)      # Object files corresponding to .c files

# Rule to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default target to build the library
all: $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)

# Clean up object files and the static library
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
