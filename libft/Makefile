# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 13:08:27 by mhidani           #+#    #+#              #
#    Updated: 2025/10/17 13:24:50 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft
LOCAL		= www.github.com/mauricioHidani
VERSION		= 1.0.0v

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= -rcs

OBJS_DIR	= ../objs/
LIBS_DIR	= ../libs/

SRCS		= ft_atof.c ft_isdigit.c ft_isspace.c ft_strlen.c ft_strncmp.c
OBJS		= $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))

SLIB		= $(LIBS_DIR)$(NAME).a

all: $(SLIB)

$(SLIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SLIB)

re: fclean all

.PHONY: clean fclean all re
