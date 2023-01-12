# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 11:18:47 by adantas-          #+#    #+#              #
#    Updated: 2023/01/12 12:08:55 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VAR ==========================================================================

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
COMPFLAGS = -L libft -lft -lmlx -lXext -lX11 -lm -lz
LIBPATH = libft/

# COLORS =======================================================================

RED		:=	\033[1;31m
GREEN	:=	\033[1;32m
YELLOW	:=	\033[1;33m
BLUE	:=	\033[1;34m
PURPLE	:=	\033[1;35m
CYAN	:=	\033[1;36m
WHITE	:=	\033[1;37m
RESET	:=	\033[0m

# FILES ========================================================================

F_SRCS = errors.c frees.c gameplay.c gameplay_utils.c mlx_begin.c render.c \
	so_long.c verify_file.c verify_map.c verify_map_utils.c
F_OBJS = $(F_SRCS:%.c=%.o)
BF_SRCS = errors_bonus.c frees_bonus.c gameplay_bonus.c gameplay_utils_bonus.c \
	load_textures_bonus.c mlx_begin_bonus.c render_bonus.c so_long_bonus.c \
	verify_file_bonus.c verify_map_bonus.c verify_map_utils_bonus.c 
BF_OBJS = $(BF_SRCS:%.c=%.o)

# CODE =========================================================================

all: $(NAME)

$(NAME): $(F_OBJS)
	@echo "$(GREEN)Creating $(NAME)...$(RESET)"
	@make -C $(LIBPATH)
	@cc $(CFLAGS) -I . $(F_OBJS) $(LIBPATH)/libft.a $(COMPFLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(F_OBJS):
	cc $(CFLAGS) -I . -c $(@:.o=.c)

bonus:
	@make F_OBJS="$(BF_OBJS)" --no-print-directory

clean:
	@echo "$(WHITE)Removing objects...$(RESET)"
	@rm -rf *.o
	@make clean -C $(LIBPATH)
	@echo "$(WHITE)Objects removed.$(RESET)"
	
fclean: clean
	@echo "$(PURPLE)Removing $(NAME) and libft.a...$(RESET)"
	@rm -rf $(NAME)
	@make fclean -C $(LIBPATH)
	@echo "$(PURPLE)$(NAME) and libft.a removed.$(RESET)"

re: fclean all
	@echo "$(RED)Update completed.$(RESET)"

re_bonus: fclean bonus
	@echo "$(RED)Update completed.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@norminette
	@echo "$(YELLOW)All OK!$(RESET)"

.PHONY: re, clean, fclean, all, norm