NAME =	libftprintf.a

SRCS = 	ft_printf.c \
		parser.c \
		ft_strcpy.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_isdigit.c \
		float_calculations.c\
		epf.c \
		float_conversions.c \
		float_get.c \
		float_strings.c \
		float.c \
		float2.c \
		float_round.c \


OBJS = 	ft_printf.o \
		parser.o \
		ft_strcpy.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_isdigit.o \
		epf.o \
		float_calculations.o\
		float_conversions.o \
		float_get.o \
		float_strings.o \
		float.o \
		float2.o \
		float_round.o \

HEADER = ft_printf.h float_header.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(HEADER) $(FLAGS)
	$(AR) -rcs $(NAME) $(OBJS) $?

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all
