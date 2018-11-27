# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/11/27 12:03:39 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c					\
					ft_init_db.c			\

INCLUDES	=		includes/

OBJ			=		$(SRCS:.c=.o)

CC			=		gcc -Wall -Wextra -Werror

NAME		=		printf

_RED=$'\x1b[31m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_BLUE=$'\x1b[34m$'
_CYAN=$'\x1b[36m$'
_WHITE=$'\x1b[37m$'

all:	$(NAME)

$(NAME): $(OBJ) $(SRCS)
	@echo "$(_CYAN)"
	make -C libft/
	@echo "$(_YELLOW)"
	$(CC) $(SRCS) -o $(NAME) -I libft/includes -I $(INCLUDES) -L libft/ -lft

clean:
	@echo "$(_RED)"
	rm -f $(OBJ)
	make clean -C ./libft/

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft/

re:	fclean $(NAME)
