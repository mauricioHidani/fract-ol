# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 18:17:43 by mhidani           #+#    #+#              #
#    Updated: 2025/10/23 23:56:42 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LOCAL		= 42 São Paulo, Brazil
VERSION		= 1.0.0v

CC			= cc
CFLAGS		= -g -O3 # -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -lX11 -lXext -lm

FRT_DIR		= fractol/
SRCS_DIR	= srcs/
INCS_DIR	= includes/
LIBS_DIR	= libs/
OBJS_DIR	= objs/
BIN_DIR		= bin/

BIN			= $(BIN_DIR)$(NAME)
SRCS		= $(wildcard $(SRCS_DIR)*.c) # todo: remove
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

MLX_DIR	= mlx/
LBF_DIR	= libft/
LBF_SLIB	= $(LIBS_DIR)libft.a

all: $(OBJS_DIR) $(LIBS_DIR) $(BIN_DIR) libft minilibx $(NAME)

libft: 
	@$(MAKE) -C $(LBF_DIR) -s

minilibx: 
	@$(MAKE) -C $(MLX_DIR) -s

$(NAME): 
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LBF_DIR) -I$(MLX_DIR) \
	$(SRCS_DIR)*.c $(LBF_SLIB) \
	$(MLX_FLAGS) \
	-o $(BIN)

$(OBJS_DIR):
	@mkdir -p $@

$(LIBS_DIR):
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

clean:
	@$(MAKE) -C mlx/ clean -s
	@$(MAKE) -C libft/ clean -s
	@rm -rf $(LIBS_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(BIN_DIR)

re: fclean all

.PHONY: clean fclean re all libft minilibx