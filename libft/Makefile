NAME = libft.a

$(NAME):
	gcc -g -Wall -Wextra -Werror -I includes -c *.c
	ar rc $(NAME) *.o
all: $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
