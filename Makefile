NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -g -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I libft/includes

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	libft/

CFILE = $(SRC_DIR)ft_printf.c 				\
		$(SRC_DIR)cast.c 							\
		$(SRC_DIR)buffer_print.c 					\
		$(SRC_DIR)dioux.c 						\
		$(SRC_DIR)flags_sp_s_o_p_cl.c 			\
		$(SRC_DIR)flags_unk_c_h_sh_po.c 			\
		$(SRC_DIR)flags_unk_c_h_sh_po.c 			\
		$(SRC_DIR)flags_x_u_i_l.c                 \
		$(SRC_DIR)plus_minus_zero_space_sharp.c 	\
		$(SRC_DIR)preparation.c 					\
		$(SRC_DIR)preprint_processing.c 			\
		$(SRC_DIR)width_prec.c 					\
		$(SRC_DIR)parser.c 						\
		$(SRC_DIR)float_calculations.c			\
		$(SRC_DIR)float_epf.c 					\
		$(SRC_DIR)float_conversions.c 			\
		$(SRC_DIR)float_get.c 					\
		$(SRC_DIR)float_strings.c 				\
		$(SRC_DIR)float_main_handler.c 			\
		$(SRC_DIR)float_main_handler_2.c 			\
		$(SRC_DIR)float_round.c 					\
		$(SRC_DIR)float_strings_2.c				\
		$(SRC_DIR)float_bits_handle.c				\

OFILE =		$(CFILE:%.c=%.o)

all: $(NAME)

$(NAME):
		@echo LIBFT START
		gcc -g -c -Wall -Werror -Wextra libft/*.c -I libft/includes
		gcc -g -c $(CFILE) -I includes
		ar rc $(NAME) *.o
		@echo FT_PRINTF COMPLETE

clean:
		@rm -rf *.o libft/*.o

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean flcean re
