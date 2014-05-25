#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 16:18:58 by vdiridol          #+#    #+#              #
#    Updated: 2014/01/22 15:50:28 by vdiridol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = ft_minishell1

SRC = ft_exe.c ft_fork.c ft_check_env.c minishell.c ft_error.c -g

all:$(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -L libft  -lft

fclean:
	/bin/rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all re fclean
