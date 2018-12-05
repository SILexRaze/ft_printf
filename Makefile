# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/12/05 19:12:27 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c						\
					ft_printf.c					\
					dispatcher.c				\
					parser/parser.c				\
					parser/fmt_to_lst.c			\
					parser/parse_extra.c		\
					parser/ft_lst_clear.c		\
					conv/ft_cspxx.c				\
					conv/ft_multiple_itoa.c		\
					conv/ft_dioufper.c			\
					conv/ft_putaddr.c			\
					conv/ft_round.c				\
					conv/ft_utoa.c				\
					conv/ft_format.c
SRC			=		$(addprefix src/, $(SRCS))
LIBFT		=		src/libft/
OBJ			=		$(addprefix obj/, $(SRC:.c=.o))
CC			=		gcc -Wall -Wextra -Werror
CCF			=		gcc -Wall -Wextra -Werror -fsanitize=address
NAME		=		ft_printf
.PHONY		=		all $(NAME) pbstart pbstop $(OBJ) dir clean fclean re
_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'

all:	$(NAME)

$(NAME): dir pbstart $(OBJ) pbstop 
	@make -C $(LIBFT)
	@$(CCF) $(OBJ) -o $(NAME) -I $(LIBFT) -I includes/ -L src/libft/ -lft
	@echo "$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)"

pbstart:
	@echo "$(_YELLOW)$(_UNDER)Compiling $(NAME) :$(_WHITE)$(_END)\t$(CC)\n"
	@/bin/echo -n "0% ["

pbstop:
	@echo "] 100%\n"

obj/%.o: %.c
	@/bin/echo -n "#"
	@$(CC) -I $(LIBFT) -I includes/ -c $< -o $@

dir:
	@echo "\n$(_YELLOW)$(_UNDER)Making directories for objects files :$(_END)\n"
	mkdir -p obj/src/conv
	mkdir -p obj/src/parser
	@echo ""

clean:
	@rm -rf obj/
	@make clean -C $(LIBFT)

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re:	fclean all
