#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

//# define BUFF_SIZE 1000

# define ABS(x) ( ( (x) < 0) ? (-x) : (x) )

//#define BUFF_SIZE 2048
#define LEN 99
typedef union s_float_to_string_representation
{
    long double num;
    char str[10];
}           t_fl_to_str;


typedef struct	s_ld_epf
{
	char	sign;
	char	exp[15];
	char	mnt[64];
	char	*integer_part_bin;
	char	*fract_part_bin;
	int		exp_dec;
}				t_ld_epf;

typedef struct s_printf
{
	char			buff[BUFF_SIZE];			//output buffer string
	int				i_buff;
	int				s;							//count of output symbols
	int				i;							//format index
	va_list			ap;							//input argument struct
	long long arg;								//number arg
	char			*format;					//argument string
	int				base;						//base of number
	int				lcase;						//lower or upper case letters send to output hex
	char			box[2];					    //upper or lower case letters in output hex-string
	char			mod[2];						//size argument modificator
	int				i_res;						//size of idsxop string
	int				unsign;						//unsigned flag
	int				zero;						//zero flag
	int				minus;						//minus flag
	int				width;						//width of output string
	int				spec_found;					//specifier found
	int				sharp;						//sharp found
	int				prec;						//precision width
	int				prec_f;						//precision flag
	int				space_f;					//space flag
	int				string_f;					//string flag
	int				s_q;						//output symbol quantity
	int				char_f;						//char flag
	int 			i_prec;						//precision index
	int				plus_f;						//plus flag
	int				exept_zero;					//exeption flag
	int				ptr_f;						//pointer flag
	int				static_ft_printf;
	int				length_capital_l;
	int				float_f;
	int				nan_f;						//not a number flag
	int				inf_f;						//infinity flag
	int				spike_w;
	int				spike_p;
}				t_printf;

typedef void (*function_point_array)(t_printf*);

int		ft_printf(const char *format, ...);
int     pars(t_printf *p, function_point_array fpa[256]);
void    spec_flags(function_point_array fpa[256]);
void    spec_flags_two(function_point_array fpa[256]);
void	unknownspec(t_printf* p);
void    print_to_percent(t_printf* p);
void    second_percent(t_printf* p);
void    itoa_int(int arg);
void    diouxXfF(t_printf* p);
void    xf(t_printf* p);
void    Xf(t_printf* p);
void    itoa_base(t_printf* p, char *res);
void    itoa_decimal(t_printf* p, char *res);
void    print_arg(char *res, t_printf* p);
void    width_f(t_printf* p);
void    long_f(t_printf* p);
int     atoi_width_prec(t_printf* p);
void    zero_space_print(int quantity, char s, t_printf* p);
void    exception(t_printf* p, char *res);
void    percent_found(t_printf* p, function_point_array fpa[256]);
void    cast_arg(t_printf* p);
void    char_f(t_printf* p);
void    point_f(t_printf* p);
char    *precision_d(char *res, t_printf* p);
void    put_zero(t_printf *p);
void    preprint(char *res, t_printf* p);
char	*ft_strcpy(char *dst, const char *src);
void    sharp_res(char *res, t_printf* p);
void    space_f(t_printf* p);
void    space_flag_print(char *res, t_printf* p);
void    str_f(t_printf* p);
void    plus_minus_print(char *res, t_printf* p);
int    	numbers_preprint(char *res, t_printf* p);
void    cast_signed(t_printf* p);
void    cast_unsigned(t_printf* p);
void    ptr_f(t_printf* p);
void    ptr_preprint(char *res, t_printf* p);
void    print_buff(t_printf* p);
void    buffcpy(char *res, t_printf* p, int size);
void	format_float(t_printf *p);
void	print_float(char *s, t_printf *p);
void	print_float2(char *s, t_printf *p);
void	check_point(char **s, t_printf *p);
void	print_str_float(char *s, t_printf *p);
char	*double_trouble(double *n, int pre, char *dubstr);
int		expa_choice(unsigned int val);
char	*long_double_trouble(long double *n, int pre, char *dubstr);
void	round_up(uint32_t *nd, int nd_lo, int mask);
void	round_lo(int pre, int prepos, int *ndlo);
int		round_tail(int nd_lo, int pre, uint32_t *nd, int mask);
void	dubtoi(int up, char **pos, uint32_t u, int pre);
int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void    put_zero2(t_printf *p);
void	float_handler(t_printf *p);
char *ft_ftoa(long double value, int afterpoint, int sign);
char *bits_to_str_of_num(int sign, char *bits);
void	bits_to_epf(char *bits, t_ld_epf *epf);
char	*epf_to_numstr(t_ld_epf *epf);
void	epf_free(t_ld_epf *epf);
void	get_exponent_from_bits(char *bits, char *exp);
void	get_mantissa_from_bits(char *bits, char *mnt);
void	get_decimal_exponent(t_ld_epf *epf);
void	get_fract_part_bin(t_ld_epf *epf);
void	get_integer_part_bin(t_ld_epf *epf);
char	*epf_to_integer_part(t_ld_epf *epf);
char	*epf_to_fract_part(t_ld_epf *epf);
char	*concat_parts(char *integer_part, char *fract_part, char sign);
char	*complete_fract_part(char *str);
char	*str_from_char(char c);
char	*power_of_2(int n);
char	*power_of_5(int n);
char	*bignum_sum(char *num1, char *num2);
void	free_nums(char *num1, char *num2);
void	swap_str(char **str1, char **str2, int mode);
char	*mult_by_10_n_times(char *num, int n);
char	*prepend_zeroes(char *str, int last);
int		count_without_postfix_zeroes(char *str);
char	*bignum_multiply_by_n(char *num, int n);
char	*str_rev(char *str);
char	*prepend_minus(char *numstr);
char	*push_back(char *res, char c);
int		ft_pow(int n, int pow);
char	*float_round_wrapper(char *str, int precision);
void	return_function(char *s, t_printf *p);

#endif
