NAME =		libftprintf.a
LIBFT =	libft

COMP =		gcc -g -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I libft/includes

OBJ_DIR =	obj
SRC_DIR =	srcs
LIB_DIR =	libft

SOURCES = ft_printf.c 				\
		cast.c 							\
		buffer_print.c 					\
		dioux.c 						\
		flags_sp_s_o_p_cl.c 			\
		flags_unk_c_h_sh_po.c 			\
		flags_unk_c_h_sh_po.c 			\
		flags_x_u_i_l.c                 \
		plus_minus_zero_space_sharp.c 	\
		preparation.c 					\
		preprint_processing.c 			\
		width_prec.c 					\
		parser.c 						\
		float_calculations.c			\
		float_epf.c 					\
		float_conversions.c 			\
		float_get.c 					\
		float_strings.c 				\
		float_main_handler.c 			\
		float_main_handler_2.c 			\
		float_round.c 					\
		float_strings_2.c				\
		float_bits_handle.c				\
		float_get_round.c

SRCS = $(addprefix $(SRC_DIR)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		make -C libft
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p obj
		gcc -Wall -Wextra -Werror -I includes -o $@ -c $<

clean:
		@rm -rf *.o libft/*.o
		rm -rf $(OBJ_DIR)/*.o
		make clean -C $(LIBFT)

fclean: clean
		@rm -rf $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean flcean re
