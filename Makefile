# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/12/05 00:06:10 by vifonne          ###   ########.fr        #
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
					conv/ft_f_width.c
INCLUDES	=		libft/
OBJDIR		=		obj/
OBJ			=		$(addprefix $(OBJDIR), $(SRCS:.c=.o))

# NE PAS OUBLIER D'ENLEVER FSANITIZESAMERE
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

$(NAME): dir pbstart $(OBJ) pbstop
	@make -C libft/
	@$(CC) $(OBJ) -o $(NAME) -I $(INCLUDES) -L libft/ -lft
	@echo "$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)"

pbstart:
	@echo "$(_YELLOW)$(_UNDER)Compiling $(NAME) :$(_WHITE)$(_END)\t$(CC)\n"
	@/bin/echo -n "0% ["

pbstop:
	@echo "] 100%\n"

$(OBJDIR)%.o: %.c
	@/bin/echo -n "#"
	@$(CC) -c $< -o $@

dir:
	@echo "\n$(_YELLOW)$(_UNDER)Making directories for objects files :$(_END)\n"
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)conv
	mkdir $(OBJDIR)parser
	@echo ""

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft/

fclean:	clean
	@rm -f $(NAME)
	@make fclean -C libft/

re:	fclean all
