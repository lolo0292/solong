# NAME = so_long

# CC		  	=	cc
# FLAG		=	-Werror -Wall -Wextra -g3 -I.

# LIBFT_PATH	=	./libft/
# LIBFT_FILE	=	libft.a

# MLX_PATH	=	./minilibx-linux/
# MLX_FILE	=	libmlx.a
# MLX_FLAG	=	-lX11 -lXext
# MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

# SRCS = src/main.c \
#        src/free.c \
#        src/map.c \
#        src/map_utils.c \
#        src/player.c \
#        src/render.c

# OBJS = $(SRCS:.c=.o)

# all: minilibx-linux $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

# src/%.o: src/%.c include/so_long.h
# 	$(CC) $(CFLAGS) -Iinclude -Iminilibx-linux -c $< -o $@

# clean:
# 	rm -f $(OBJS)
# 	make -C minilibx-linux clean

# fclean: clean
# 	rm -f $(NAME)
# 	make -C minilibx-linux fclean

# re: fclean all

# NAME		=	so_long

# CC		  	=	cc
# FLAG		=	-Werror -Wall -Wextra -g3

# LIBFT_PATH	=	./libft/
# LIBFT_FILE	=	libft.a

# MLX_PATH	=	./minilibx-linux/
# MLX_FILE	=	libmlx.a
# MLX_FLAG	=	-lX11 -lXext
# MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

# LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
# MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

# INC_DIR		=	includes/

# SRCS = src/main.c \
#        src/free.c \
#        src/map.c \
#        src/map_utils.c \
#        src/player.c \
#        src/render.c

# OBJ = $(SRCS:.c=.o)

# all: $(NAME)

# .c.o:
# 	$(CC) $(FLAG) -c $< -o $@

# lib:
# 	@make -sC $(LIBFT_PATH)

# mlx:
# 	@make -sC $(MLX_PATH)

# $(NAME): lib mlx $(OBJ)
# 	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIBFT_PATH) $(MLX_EX)

# axel: $(OBJ)
# 	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I$(INC_DIR) -L$(LIBFT_PATH) $(MLX_EX)

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)
# 	@mkdir -p $(OBJ_DIR)/core
# 	@mkdir -p $(OBJ_DIR)/map
# 	@mkdir -p $(OBJ_DIR)/render

# clean:
# 	@make clean -sC $(LIBFT_PATH)
# 	@make clean -sC $(MLX_PATH)
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@rm -f $(NAME)
# 	@make fclean -C $(LIBFT_PATH)

# re: fclean all

# .PHONY: all clean fclean re


NAME = so_long

CC		  	=	cc
FLAG		=	-Werror -Wall -Wextra -g3

MLX_PATH	=	./minilibx-linux/
MLX_FILE	=	libmlx.a
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/X11/lib -lXext -lX11 -lm
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRCS = src/main.c \
       src/free.c \
       src/map.c \
       src/map_utils.c \
       src/player.c \
       src/render.c

OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -Iinclude  -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -sC $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re