 NAME = a.out

FLAGS =  -g -Wall -Wextra -Werror

SRC = ft.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft all
	@gcc $(FLAGS) -I libft/ -c $(SRC) $<
	@gcc -o $(NAME) $(OBJ) -L libft/ -lft

%o: %c
	@gcc $(FLAGS) -I libft/ -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
