# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhasni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/09 06:27:37 by hhasni            #+#    #+#              #
#    Updated: 2015/07/09 06:27:37 by hhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol

CPATH =		./

SRCS =		buddhabrot.c \
			julia.c \
			mandelbrot.c \
			sierpinski.c \
			scarpet.c \
			ft_tools.c \
			ft_draw.c \
			ft_error.c \
			ft_key.c \
			main.c

OBJS =		$(SRCS:.c=.o)

MLXFLAGS =  -I ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all:		$(NAME) 

$(NAME):	$(OBJS)
			@echo "\n\r\033[38;5;11m⌛  MAKE $(NAME) plz wait...\033[0m\033[K"
			@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
			@echo -en "\r\033[38;5;22m✅  MAKE $(NAME)\033[0m\033[K"
			@echo "💟"

%.o:		$(CPATH)%.c
			@$(CC) $(CFLAGS) -I /usr/X11/include -c $< 

clean:
			@$(RM) $(OBJS)
			@echo -en "\r\033[38;5;124m❌  CLEAN $(NAME) \033[0m\033[K"

fclean:		clean
			@$(RM) $(NAME) 
			@echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME) \033[0m\033[K"

re:			fclean all
