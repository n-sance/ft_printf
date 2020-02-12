/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:59:20 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 21:17:35 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# define BUFF_SIZE_F	2048
# define LEN 			99
# define BUFF_SIZE_P	1000

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include "../libft/includes/libft.h"

typedef struct		s_printf
{
	char			buff[BUFF_SIZE_P];
	int				i_buff;
	int				s;
	int				i;
	va_list			ap;
	long long		arg;
	char			*format;
	int				base;
	int				lcase;
	char			box[2];
	char			mod[2];
	int				i_res;
	int				unsign;
	int				zero;
	int				minus;
	int				width;
	int				spec_found;
	int				sharp;
	int				prec;
	int				prec_f;
	int				space_f;
	int				string_f;
	int				s_q;
	int				char_f;
	int				i_prec;
	int				plus_f;
	int				exept_zero;
	int				ptr_f;
	int				static_ft_printf;
	int				length_capital_l;
	int				float_f;
	int				nan_f;
	int				inf_f;
}					t_printf;

typedef void		(*t_function_point_array)(t_printf*);

int					ft_printf(const char *format, ...);
int					pars(t_printf *p, t_function_point_array fpa[256]);
void				spec_flags(t_function_point_array fpa[256]);
void				spec_flags_two(t_function_point_array fpa[256]);
void				unknownspec(t_printf *p);
void				print_to_percent(t_printf *p);
void				second_percent(t_printf *p);
void				itoa_int(int arg);
void				dioux(t_printf *p);
void				xf(t_printf *p);
void				upx_f(t_printf *p);
void				itoa_base(t_printf *p, char *res);
void				itoa_decimal(t_printf *p, char *res);
void				print_arg(char *res, t_printf *p);
void				width_f(t_printf *p);
void				long_f(t_printf *p);
int					atoi_width_prec(t_printf *p);
void				zero_space_print(int quantity, char s, t_printf *p);
void				exception(t_printf *p, char *res);
void				percent_found(t_printf *p, t_function_point_array fpa[256]);
void				cast_arg(t_printf *p);
void				char_f(t_printf *p);
void				point_f(t_printf *p);
char				*precision_d(char *res, t_printf *p);
void				put_zero(t_printf *p);
void				preprint(char *res, t_printf *p);
char				*ft_strcpy(char *dst, const char *src);
void				sharp_res(char *res, t_printf *p);
void				space_f(t_printf *p);
void				space_flag_print(char *res, t_printf *p);
void				str_f(t_printf *p);
void				plus_minus_print(char *res, t_printf *p);
int					numbers_preprint(char *res, t_printf *p);
void				cast_signed(t_printf *p);
void				cast_unsigned(t_printf *p);
void				ptr_f(t_printf *p);
void				ptr_preprint(char *res, t_printf *p);
void				print_buff(t_printf *p);
void				buffcpy(char *res, t_printf *p, int size);
void				format_float(t_printf *p);
void				print_float(char *s, t_printf *p);
void				print_float2(char *s, t_printf *p);
void				check_point(char **s, t_printf *p);
void				print_str_float(char *s, t_printf *p);
void				put_zero2(t_printf *p);
void				sharp_f(t_printf *p);
void				intf(t_printf *p);
void				itoa_lu(t_printf *p, unsigned long lu, char *res);
void				o_f(t_printf *p);
void				check_unsigned(t_printf *p);
void				short_f(t_printf *p);
void				capital_long_f(t_printf *p);
void				width_align_print(char *res, t_printf *p);
void				precision_zero(char *res, t_printf *p);

typedef union		u_float_to_string_representation
{
	long double		num;
	char			str[10];
}					t_fl_to_str;

typedef struct		s_ld_epf
{
	char			sign;
	char			exp[15];
	char			mnt[64];
	char			*integer_part_bin;
	char			*fract_part_bin;
	int				exp_dec;
}					t_ld_epf;

typedef	struct		s_round_prec_0
{
	int				i;
	int				carry;
	int				sum;
	char			*temp;
}					t_r_prec_0;

void				float_handler(t_printf *p);
char				*ft_ftoa(long double value, t_printf *p);
char				*bits_to_str_of_num(int sign, char *bits);
void				bits_to_epf(char *bits, t_ld_epf *epf);
char				*epf_to_numstr(t_ld_epf *epf);
void				epf_free(t_ld_epf *epf);
void				get_exponent_from_bits(char *bits, char *exp);
void				get_mantissa_from_bits(char *bits, char *mnt);
void				get_decimal_exponent(t_ld_epf *epf);
void				get_fract_part_bin(t_ld_epf *epf);
void				get_integer_part_bin(t_ld_epf *epf);
char				*epf_to_integer_part(t_ld_epf *epf);
char				*epf_to_fract_part(t_ld_epf *epf);
char				*concat_parts(char *int_part, char *fract_part, char sign);
char				*complete_fract_part(char *str);
char				*str_from_char(char c);
char				*power_of_2(int n);
char				*power_of_5(int n);
char				*bignum_sum(char *num1, char *num2);
void				free_nums(char *num1, char *num2);
void				swap_str(char **str1, char **str2, int mode);
char				*mult_by_10_n_times(char *num, int n);
char				*prepend_zeroes(char *str, int last);
int					count_without_postfix_zeroes(char *str);
char				*bignum_multiply_by_n(char *num, int n);
char				*str_rev(char *str);
char				*prepend_minus(char *numstr);
char				*push_back(char *res, char c);
int					ft_pow(int n, int pow);
char				*float_round_wrapper(char *str, int precision, int sharp_f);
char				*float_round_prec_0(char *str, int sharp_f);
void				check_point(char **s, t_printf *p);
int					round_exception(char *str, int precision);
void				copy_bits_from_byte(char *bits_from_b, char *bits, int pos);
void				byte_to_bits(char byte, char *bits_from_byte);
char				*nan_and_inf_handler(t_printf *p, long double value);
void				flat_around_handler(int i, char *str, int carry);
void				fl_round_pr_0_handle(int i, char *str);
char				*float_round(char *str, int precision);
int					get_dot_pos(char *str);
void				ftoa_handler(t_fl_to_str bytes, char *f_in_bits);
#endif
