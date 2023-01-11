# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:18:47 by adantas-          #+#    #+#              #
#    Updated: 2023/01/11 12:47:06 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VAR =========================================================================
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LIBPATH = libft/
# COLORS ======================================================================
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
PURPLE		:=	\033[1;35m
CYAN		:=	\033[1;36m
WHITE		:=	\033[1;37m
RESET		:=	\033[0m
# FILES =======================================================================
SRC = errors.c frees.c gameplay.c gameplay_utils.c mlx_begin.c render.c \
	so_long.c verify_file.c verify_map.c verify_map_utils.c