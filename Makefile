# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 16:23:22 by dansanc3          #+#    #+#              #
#    Updated: 2024/12/14 12:36:43 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = fractol
BONUS_NAME = fractol_bonus

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I$(FRACTOL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR_INCLUDE) -I$(PRINTF_DIR)

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
LIBFT_DIR_INCLUDE = include/libft/include
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = mandelbrot window_settings render main julia no_bonus_input newton_bonus

# Bonus files
BONUS = input_bonus

# Object files
OBJS = $(addprefix obj/, $(addsuffix .o, $(SRC)))

# Object files for bonus compilation
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(filter-out no_bonus_input, $(SRC)) $(BONUS)))

SRCS = $(addsuffix .c, $(SRC))

OBJF =	.cache_exists

# Libraries
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -Linclude/libft/ -lft -Linclude/ft_printf/ -lftprintf

# Compilation rule
all: $(OBJF) $(LIBFT) $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(FRACTOL_DIR)/fractol.h | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

$(OBJF):
		@mkdir -p $(OBJ_DIR)/

# Rule to compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Bonus rule
bonus: $(OBJF) $(LIBFT) $(BONUS_NAME)

# Rule to link the final executable for bonus compilation
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
