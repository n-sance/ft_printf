#ifndef FLOAT_HEADER_H
#define FLOAT_HEADER_H
# define ABS(x) ( ( (x) < 0) ? (-x) : (x) )

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"



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
 char   buff[BUFF_SIZE];   //output buffer string
 int    i_buff;
 int    s;       //count of output symbols
 int    i;       //format index
 va_list   ap;       //input argument struct
 long long arg;        //number arg
 char   *format;     //argument string
 int    base;      //base of number
 int    lcase;      //lower or upper case letters send to output hex
 char   box[2];      //upper or lower case letters in output hex-string
 char   mod[2];      //size argument modificator
 int    i_res;      //size of idsxop string
 int    unsign;      //unsigned flag
 int    zero;      //zero flag
 int    minus;      //minus flag
 int    width;      //width of output string
 int    spec_found;     //specifier found
 int    sharp;      //sharp found
 int    prec;      //precision width
 int    prec_f;      //precision flag
 int    space_f;     //space flag
 int    string_f;     //string flag
 int    s_q;      //output symbol quantity
 int    char_f;      //char flag
 int    i_prec;      //precision index
 int    plus_f;      //plus flag
 int    exept_zero;     //exeption flag
 int    ptr_f;      //pointer flag
 int    static_ft_printf;
 int    length_capital_l;
 int    float_f;
 int    nan_f;      //not a number flag
 int    inf_f;      //infinity flag
}    t_printf;





char *float_handler(t_printf *p);
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
char	*float_round_prec_0(char *str);
#endif
