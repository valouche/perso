#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 18:10:18 by vdiridol          #+#    #+#              #
#    Updated: 2014/01/09 19:05:39 by vdiridol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		= gcc

CFLAG	= -Wall -Wextra -Werror -ltermcap

NAME	= ft_select

SRC		= selec.c ft_chk_sig.c ft_key.c ft_list.c ft_move.c ft_del.c

all: $(NAME)
	@echo "--- Make done ---"

$(NAME): $(SRC)
	@make -C libft
	@$(CC) $(CFLAG) $(SRC) -o $(NAME) -L libft  -lft

clean: 
	@/bin/rm -f DS_Store

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo "--- Fclean Complete ---"

re: fclean all
	
.PHONY: all re fclean
