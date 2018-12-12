# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/12/12 18:12:18 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_printf.c			\
					ft_dispatcher.c		\
					ft_parser.c			\
					ft_fmt_to_lst.c		\
					ft_parse_extra.c	\
					ft_cspxx.c			\
					ft_multiple_itoa.c	\
					ft_dioufper.c		\
					ft_putaddr.c		\
					ft_round.c			\
					ft_utoa.c			\
					ft_bonus.c			\
					ft_cast.c			\
					ft_ucast.c			\
					ft_format.c
LIBFT		=		libft/
OBJ			=		$(SRCS:.c=.o)
CC			=		gcc -Wall -Wextra -Werror
NAME		=		libftprintf.a
.PHONY		=		all $(NAME) pbstart pbstop $(OBJ) dir clean fclean re
_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)"

%.o: %.c
	$(CC) -I $(LIBFT) -I includes/ -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all
