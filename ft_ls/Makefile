#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 17:24:33 by vdiridol          #+#    #+#              #
#    Updated: 2013/12/13 13:47:54 by vdiridol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = a.out

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	gcc $(FLAGS) -I libft/includes/ -c ft_ls.c
	gcc -o ft_ls ft_ls.o -L libft/ -lft

clean:
	@rm -f get_next_line.o main.o

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

