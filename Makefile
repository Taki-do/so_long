NAME = so_long
PATH_LIBFT = libft/
LIBFT_LIB = $(PATH_LIBFT)libft.a
PATH_SRC = src
INC_DIR = include
SRCS = $(PATH_SRC)/main.c $(PATH_SRC)/map.c $(PATH_SRC)/mlx_input.c $(PATH_SRC)/utils.c $(PATH_SRC)/render.c \
		$(PATH_SRC)/findpath.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS =  -I$(INC_DIR) -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(PATH_LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(PATH_SRC)/*.o
	make -C $(PATH_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIBFT) fclean

re: fclean all
