NAME = so_long

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -Iinclude -I./minilibx-linux
# MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
# LIBFT_PATH				= libft/
# LIBFT_EX				= libft.a

CC		  	=	cc
FLAG		=	-Werror -Wall -Wextra -g3

LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a

MLX_PATH	=	./minilibx-linux/
MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRCS = src/main.c \
       src/free.c \
       src/map.c \
       src/map_utils.c \
       src/player.c \
       src/render.c

OBJS = $(SRCS:.c=.o)

all: minilibx-linux $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

src/%.o: src/%.c include/so_long.h
	$(CC) $(CFLAGS) -Iinclude -Iminilibx-linux -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C minilibx-linux fclean

re: fclean all


