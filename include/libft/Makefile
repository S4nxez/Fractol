CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
NAME = libft.a
INCLUDES = ./include

SRC_DIR = src

SRC_FILES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp \
ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup \
ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr\
ft_tolower ft_toupper get_next_line

OBJ_DIR = obj

OBJS =	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))


BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS_BNS = $(BNS:.c=.o)
OBJS_BNS := $(addprefix $(OBJ_DIR)/, $(OBJS_BNS))

OBJF		=	.cache_exists

all: $(OBJF) $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)/libft.h |$(OBJF)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF): 
		@mkdir -p $(OBJ_DIR)/

bonus: $(OBJS) $(OBJS_BNS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BNS)

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all NAME clean fclean re rebonus
