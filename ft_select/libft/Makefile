#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 16:01:17 by vdiridol          #+#    #+#              #
#    Updated: 2014/01/09 19:03:54 by vdiridol         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC	= gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ft_atoi.c ft_isascii.c ft_memset.c ft_putstr.c ft_strcpy.c\
	   ft_tolower.c ft_isalnum.c ft_isdigit.c ft_putchar.c ft_strchr.c\
	   ft_strlen.c ft_strrchr.c	ft_toupper.c ft_isalpha.c ft_isprint.c\
	   ft_putnbr.c ft_strcmp.c ft_strncpy.c	ft_strstr.c ft_bzero.c ft_memcpy.c\
	   ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c\
	   ft_strncmp.c ft_strdup.c ft_strlcat.c ft_memmove.c ft_strnstr.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl.c\
	   ft_putendl_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strclr.c\
	   ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
	   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
	   ft_realloc.c ft_strsplit.c

OBJ = ft_atoi.o ft_isascii.o ft_memset.o ft_putstr.o ft_strcpy.o\
      ft_tolower.o ft_isalnum.o ft_isdigit.o ft_putchar.o ft_strchr.o\
      ft_strlen.o ft_strrchr.o ft_toupper.o ft_isalpha.o ft_isprint.o\
	  ft_putnbr.o ft_strcmp.o ft_strncpy.o ft_strstr.o ft_bzero.o ft_memcpy.o\
	  ft_memccpy.o ft_memchr.o ft_memcmp.o ft_strcat.o ft_strncat.o\
	  ft_strncmp.o ft_strdup.o ft_strlcat.o ft_memmove.o ft_strnstr.o\
	  ft_putchar_fd.o ft_putstr_fd.o ft_putnbr_fd.o ft_putendl.o\
	  ft_putendl_fd.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strclr.o\
	  ft_strdel.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o\
	  ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o ft_strtrim.o\
	  ft_realloc.o ft_strsplit.o

all: $(NAME)

$(NAME):
		@$(CC) -c $(SRCS) $(CFLAGS)
		@ar rcs $(NAME) $(OBJ)
		@echo "--- Libft make done ---"

clean:
		@rm -f $(OBJ)
		@rm -f .DS_Store

fclean: clean
		@rm -f $(NAME)
		@echo "--- Libft Fclean Complete ---"

re: fclean all
