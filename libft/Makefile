NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HEADER = includes

LIBFILES = $(SRC:.c=.o)

SRC = *.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(LIBFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(LIBFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
