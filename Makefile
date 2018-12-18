# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/12/18 15:35:01 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_printf.c			\
					ft_dispatcher.c		\
					ft_parser.c			\
					ft_fmt_to_lst.c		\
					ft_parse_extra.c	\
					ft_cspxx.c			\
					ft_itoa_base.c		\
					ft_diouf.c			\
					ft_putaddr.c		\
					ft_round.c			\
					ft_utoa.c			\
					ft_bonus.c			\
					ft_cast.c			\
					ft_format.c			\
					ft_print_list.c		\
					ft_mod.c			\
					ft_flags.c			\
					ft_width.c			\
					ft_dtoa.c
LIBFT		=		libft/
OBJ			=		$(SRCS:.c=.o)
CC			=		gcc -Wall -Wextra -Werror
NAME		=		libftprintf.a
.PHONY		=		all $(NAME) $(OBJ) clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -I $(LIBFT) -I includes/ -c $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all
