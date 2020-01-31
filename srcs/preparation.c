#include "ft_printf.h"

void	spec_flags_two(t_function_point_array fpa[256])
{
	fpa['0'] = width_f;
	fpa['1'] = width_f;
	fpa['2'] = width_f;
	fpa['3'] = width_f;
	fpa['4'] = width_f;
	fpa['5'] = width_f;
	fpa['6'] = width_f;
	fpa['7'] = width_f;
	fpa['8'] = width_f;
	fpa['9'] = width_f;
	fpa['-'] = width_f;
	fpa['+'] = width_f;
	fpa['#'] = sharp_f;
	fpa['.'] = point_f;
	fpa[' '] = space_f;
}

void	spec_flags(t_function_point_array fpa[256])
{
	int i_fpa;

	i_fpa = 0;
	while (i_fpa <= 256)
		fpa[i_fpa++] = unknownspec;
	fpa['c'] = char_f;
	fpa['C'] = char_f;
	fpa['s'] = str_f;
	fpa['d'] = intf;
	fpa['i'] = intf;
	fpa['o'] = o_f;
	fpa['u'] = check_unsigned;
	fpa['x'] = xf;
	fpa['X'] = upx_f;
	fpa['f'] = float_handler;
	fpa['F'] = float_handler;
	fpa['p'] = ptr_f;
	fpa['h'] = short_f;
	fpa['l'] = long_f;
	fpa['L'] = capital_long_f;
	spec_flags_two(fpa);
}

void	put_zero2(t_printf *p)
{
	p->nan_f = 0;
	p->inf_f = 0;
}

void	put_zero(t_printf *p)
{
	p->base = 0;
	p->lcase = 0;
	p->mod[0] = 0;
	p->mod[1] = 0;
	p->i_res = 0;
	p->unsign = 0;
	p->zero = 0;
	p->minus = 0;
	p->width = 0;
	p->spec_found = 0;
	p->sharp = 0;
	p->prec = 0;
	p->prec_f = 0;
	p->space_f = 0;
	p->string_f = 0;
	p->s_q = 0;
	p->arg = 0;
	p->char_f = 0;
	p->i_prec = 0;
	p->plus_f = 0;
	p->exept_zero = 0;
	p->ptr_f = 0;
	p->length_capital_l = 0;
	p->float_f = 0;
	put_zero2(p);
}
