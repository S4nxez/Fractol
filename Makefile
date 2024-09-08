# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 16:23:22 by dansanc3          #+#    #+#              #
#    Updated: 2024/09/07 19:26:35 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = fractol

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g -I$(FRACTOL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Fractol.h library path
FRACTOL_DIR = include/
OBJ_DIR = obj
SRC_DIR = src

# MiniLibX library path
MLX_DIR = include/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

# Ft_printf library path
PRINTF_DIR = include/ft_printf/include
PRINT = include/ft_printf/libftprintf.a

# Libft library path
LIBFT_DIR = include/libft/include
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC = mandelbrot window_settings render main julia newton

# Object files
OBJS = $(addprefix obj/, $(addsuffix .o, $(SRC)))


SRCS = $(addsuffix .c, $(SRC))

OBJF =	.cache_exists

# Libraries
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -Linclude/libft/ -lft -Linclude/ft_printf/ -lftprintf

# Compilation rule
all: $(OBJF) $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(FRACTOL_DIR)/fractol.h | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

$(OBJF):
		@mkdir -p $(OBJ_DIR)/

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME)

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
