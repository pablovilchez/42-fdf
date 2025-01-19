# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 13:19:25 by pvilchez          #+#    #+#              #
#    Updated: 2023/09/28 09:37:19 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -g
MLX42FLAGS_LINUX = -Iinclude -ldl -lglfw -pthread -lm
MLX42FLAGS_MAC = -lglfw -L "/Users/${USER}/.brew/opt/glfw/lib/"
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

LIBFT_PATH = assets/libft
LIBFT_LIB_PATH = assets/libft/libft.a

MLX42_PATH = assets/MLX42
MLX42_LIB_PATH = assets/MLX42/libmlx42.a

HEADERS	= -I $(LIBFT_PATH)/include/ -I $(MLX42_PATH)/include/MLX42/ -I ./include

SRC_FILES = fdf.c get_matrix.c start_matrix.c print_matrix.c free_matrix.c color_functions.c\
			utils.c adjust_values.c

SRC := $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(LIBFT_LIB_PATH) $(MLX42_LIB_PATH) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(MLX42_LIB_PATH) $(MLX42FLAGS_MAC) $(HEADERS) -o $@
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): Mandatory Compiled$(RESET) \n"

$(LIBFT_LIB_PATH):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX42_LIB_PATH):
	@$(MAKE) -C $(MLX42_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)$(NAME) Compiling:$(RESET) $(notdir $<)"

clean:
	@$(REMOVE) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX42_PATH) clean

fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX42_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_LIB_PATH) $(MLX42_LIB_PATH)