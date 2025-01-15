NAME = so_long

# Dossiers
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Fichiers sources
SRCS = $(SRC_DIR)/moving.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation
CC = gcc
CFLAGS =  -I$(INC_DIR)

# Bibliothèques MiniLibX
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
