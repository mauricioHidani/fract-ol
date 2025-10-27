# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 18:17:43 by mhidani           #+#    #+#              #
#    Updated: 2025/10/26 22:02:08 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LOCAL		= github.com/mauricioHidani
VERSION		= 1.0.0v

CC			= cc
CFLAGS		= -g -O4 -Wall -Wextra -Werror
MLX_FLAGS	= -Lmlx -lmlx -lX11 -lXext -lm

FRT_DIR		= fractol/
SRCS_DIR	= srcs/
INCS_DIR	= includes/
LIBS_DIR	= libs/
OBJS_DIR	= objs/
BIN_DIR		= bin/

BIN			= $(BIN_DIR)$(NAME)
SRCS		= \
			$(SRCS_DIR)app_utils.c $(SRCS_DIR)fractal_burningship.c \
			$(SRCS_DIR)fractal_julia.c $(SRCS_DIR)fractal_mandelbrot.c \
			$(SRCS_DIR)fractal_utils.c $(SRCS_DIR)graph_utils.c \
			$(SRCS_DIR)handle_keyboard_and_mouse.c $(SRCS_DIR)help_utils.c \
			$(SRCS_DIR)main.c $(SRCS_DIR)render_utils.c $(SRCS_DIR)utils.c \
			$(SRCS_DIR)vector2_utils.c
OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

MLX_DIR		= mlx/
LBF_DIR		= libft/
LBF_SLIB	= $(LIBS_DIR)libft.a
MLX_SLIB	= $(MLX_DIR)libmlx.a

RESET		:= \033[0m
ITALIC		:= \033[3m

C01			:= \033[38;5;27m# Blue
C02			:= \033[38;5;63m# Purplish blue
C03			:= \033[38;5;99m# Purple
C04			:= \033[38;5;135m# Magenta
C05			:= \033[38;5;171m# Pink
C06			:= \033[38;5;207m# Light pink
C07			:= \033[38;5;213m# Deep pink
C08			:= \033[38;5;219m# Pastel pink
C09			:= \033[38;5;215m# Soft orange
C10			:= \033[38;5;208m# Bright orange

all: banner $(OBJS_DIR) $(LIBS_DIR) $(BIN_DIR) $(NAME)

$(NAME): $(MLX_SLIB) $(LBF_SLIB) $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LBF_DIR) -I$(MLX_DIR) \
	$(OBJS) $(LBF_SLIB) $(MLX_SLIB) \
	$(MLX_FLAGS) \
	-o $(BIN)

$(LBF_SLIB): 
	@$(MAKE) -C $(LBF_DIR) -s
	@echo "$(C01)Libft compiled$(RESET)"

$(MLX_SLIB): 
	@$(MAKE) -C $(MLX_DIR) -s
	@echo "$(C01)Minilibx compiled$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LBF_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJS_DIR): 
	@mkdir -p $@

$(LIBS_DIR): 
	@mkdir -p $@

$(BIN_DIR):
	@mkdir -p $@

banner: 
	@echo "$(C01) _____               _              _  $(RESET)";
	@echo "$(C02)|  ___| __ __ _  ___| |_       ___ | | $(RESET)";
	@echo "$(C03)| |_ | '__/ _\` |/ __| __|____ / _ \| | $(RESET)";
	@echo "$(C04)|  _|| | | (_| | (__| ||_____| (_) | | $(RESET)";
	@echo "$(C05)|_|  |_|  \__,_|\___|\__|     \___/|_| $(RESET)";
	@echo "$(C06)fract-ol - $(VERSION)$(RESET)";
	@echo "$(C07)$(LOCAL) - 42 São Paulo, Brazil$(RESET)";

clean: 
	@echo "🧹 $(C10)Clean$(RESET)"
	@$(MAKE) -C mlx/ clean -s
	@$(MAKE) -C libft/ clean -s
	@rm -rf $(LIBS_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "🧹 $(C10)Full Clean$(RESET)"
	@rm -rf $(BIN_DIR)

re: fclean all

.PHONY: clean fclean re all libft minilibx banner