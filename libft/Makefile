# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 13:08:27 by mhidani           #+#    #+#              #
#    Updated: 2025/10/20 08:27:31 by mhidani          ###   ########.fr        #
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

SRCS		= $(wildcard *.c) # todo: remove
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
