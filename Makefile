# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifonne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:05:19 by vifonne           #+#    #+#              #
#    Updated: 2018/11/27 17:41:07 by vifonne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		main.c					\
					ft_printf.c				\
					ft_parse.c				\

INCLUDES	=		includes/

OBJ			=		$(SRCS:.c=.o)









# NE PAS OUBLIER DE RAJOUTER LES FLAGS
CC			=		gcc -fsanitize=address












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
	@echo "$(_WHITE)"

clean:
	@echo "$(_RED)"
	rm -f $(OBJ)
	make clean -C ./libft/
	@echo "$(_WHITE)"

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./libft/
	@echo "$(_WHITE)"

re:	fclean $(NAME)
