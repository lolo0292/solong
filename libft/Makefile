# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 20:58:55 by nsiefert          #+#    #+#              #
#    Updated: 2025/01/05 16:44:54 by nsiefert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror -g3

#Folders
INCLUDE		=	includes/
LIBFT 		=	libft/
PRINTF 		=	printf/
GNL 		=	gnl/
PERSO		=	perso/
TOKEN		=	tokenizer/

OBJ_DIR		=	obj/

RM			=	@rm -f

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

LIBFTSRC 	= 	ft_atoi.c	 				\
				ft_bzero.c 					\
				ft_isalnum.c 				\
				ft_isalpha.c 				\
				ft_isascii.c 				\
				ft_isdigit.c 				\
				ft_isprint.c 				\
				ft_memchr.c 				\
				ft_memcmp.c 				\
				ft_memcpy.c 				\
				ft_memmove.c 				\
				ft_memset.c 				\
				ft_strchr.c 				\
				ft_strlcat.c 				\
				ft_strlcpy.c 				\
				ft_strlen.c 				\
				ft_strncmp.c 				\
				ft_strnstr.c 				\
				ft_strrchr.c 				\
				ft_tolower.c 				\
				ft_toupper.c 				\
				ft_calloc.c 				\
				ft_strdup.c 				\
				ft_substr.c 				\
				ft_strjoin.c 				\
				ft_strtrim.c 				\
				ft_split.c 					\
				ft_itoa.c 					\
				ft_strmapi.c 				\
				ft_striteri.c 				\
				ft_putchar_fd.c				\
				ft_putstr_fd.c 				\
				ft_putendl_fd.c 			\
				ft_putnbr_fd.c				\
				rmv_lst.c					\

LIBFTSRCB 	=	ft_lstnew.c 				\
				ft_lstadd_front.c 			\
				ft_lstsize.c 				\
				ft_lstlast.c 				\
				ft_lstadd_back.c 			\
				ft_lstdelone.c 				\
				ft_lstclear.c 				\
				ft_lstiter.c 				\
				ft_lstmap.c					\
				ft_lstto_tab.c

PRINTFSRC 	= 	ft_fd_print_hex.c			\
				ft_fd_print_ptr.c			\
				ft_fd_printf_utils.c		\
				ft_fd_print_unsigned.c		\
				ft_fd_printf.c				\
				ft_printf.c					\

GNLSRC	  	=	get_next_line.c				\
				get_next_line_utils.c		\

PERSOSRC  	=	ft_countchar.c				\
				ft_free_tab.c				\
				ft_iswhitespace.c			\
				print_tab.c					\

TOKENSRC	=	t_tkn.c						\
				tokenizer.c					\
				is_operator.c				\

# LIBFT
SRC_LIBFT	= 	$(addprefix $(LIBFT), $(LIBFTSRC))
OBJ_LIBFT	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRC:.c=.o))
# LIBFT-BONUS
SRC_LIBFTB	= 	$(addprefix $(LIBFT), $(LIBFTSRCB))
OBJ_LIBFTB	= 	$(addprefix $(OBJ_DIR), $(LIBFTSRCB:.c=.o))
# PRINTF
SRC_PRINTF	=	$(addprefix $(PRINTF), $(PRINTFSRC))
OBJ_PRINTF	= 	$(addprefix $(OBJ_DIR), $(PRINTFSRC:.c=.o))
# GET_NEXT_LINE
SRC_GNL		=	$(addprefix $(GNL), $(GNLSRC))
OBJ_GNL		= 	$(addprefix $(OBJ_DIR), $(GNLSRC:.c=.o))
# PERSONNAL FUNCTIONS
SRC_PERSO	=	$(addprefix $(PERSO), $(PERSOSRC))
OBJ_PERSO	= 	$(addprefix $(OBJ_DIR), $(PERSOSRC:.c=.o))
# TOKENIZER FUNCTIONS
SRC_TOKEN	=	$(addprefix $(TOKEN), $(TOKENSRC))
OBJ_TOKEN	= 	$(addprefix $(OBJ_DIR), $(TOKENSRC:.c=.o))

OBJF		=	.cache_exists

all: $(NAME)

$(NAME): $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)
	@ar rc $(NAME) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)
	@ranlib $(NAME)
	
$(OBJ_DIR)%.o: $(LIBFT)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(GNL)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(PERSO)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(TOKEN)%.c $(OBJF)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_LIBFTB) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re