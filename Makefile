# Name of the executable
NAME = fractol

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g -I$(FRACTOL_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Fractol.h library path
FRACTOL_DIR = include/

# MiniLibX library path
MLX_DIR = /home/s4nxez/minilibx_linux
MLX = $(MLX_DIR)/libmlx.a

# Ft_printf library path
PRINTF_DIR = include/ft_printf/include
PRINT = include/ft_printf/libftprintf.a

# Libft library path
LIBFT_DIR = include/libft/include
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRCS = mandelbrot.c window_settings.c render.c main.c julia.c

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -Linclude/libft/ -lft -Linclude/ft_printf/ -lftprintf

# Compilation rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME)

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
