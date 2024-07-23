# Name of the executable
NAME = Menger

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)

# MiniLibX library path
MLX_DIR = /home/s4nxez/minilibx_linux
MLX = $(MLX_DIR)/libmlx.a

# Source files
SRCS = main.c menger_sponge.c

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

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
