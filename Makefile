# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/12/03 13:38:57 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c						\
					ft_printf.c					\
					dispatcher.c				\
					parser/parser.c				\
					parser/fmt_to_lst.c			\
					parser/parse_extra.c		\
					exec/ft_csp.c
INCLUDES	=		libft/
OBJ			=		$(SRCS:.c=.o)
# NE PAS OUBLIER DE RAJOUTER LES FLAGS
CC			=		gcc -Wall -Wextra -Werror -fsanitize=address
NAME		=		ft_printf

_BOLD=$'\x1b[1m$'
_UNDER=$'\x1b[4m$'
_GREY=$'\x1b[30m$'
_RED=$'\x1b[31m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_BLUE=$'\x1b[34m$'
_PURPLE=$'\x1b[35m$'
_CYAN=$'\x1b[36m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'
_REV=$'\x1b[7m$'

all:	$(NAME)

$(NAME): pbstart $(OBJ) pbstop
	@make -C libft/
	@$(CC) $(OBJ) -o $(NAME) -I $(INCLUDES) -L libft/ -lft
	@echo "$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)"

pbstart:
	@echo "$(_YELLOW)$(_UNDER)Compiling $(NAME) :$(_WHITE)$(_END)\t$(CC)\n"
	@/bin/echo -n "0% ["

pbstop:
	@/bin/echo "] 100%"
	@echo "\n"

%.o:%.c
	@/bin/echo -n "#"
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C libft/

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft/

re:	fclean all
