#include "ft_printf.h"

void	precision_zero(char *res, t_printf *p)
{
	while (p->prec > p->s_q)
	{
		res[p->i_prec] = '0';
		p->prec--;
		p->i_prec++;
		p->i_res++;
	}
}

char	*precision_d(char *res, t_printf *p)
{
	p->s_q = (res[p->i_res] == '-') ? p->i_res : p->i_res + 1;
	p->i_prec = (res[p->i_res] == '-') ? p->i_res : p->i_res + 1;
	if (res[p->i_res] == '-')
	{
		precision_zero(res, p);
		res[p->i_prec] = '-';
	}
	else
	{
		p->prec -= (p->sharp > 0 && p->base == 8) ? 1 : 0;
		precision_zero(res, p);
	}
	p->s_q = 0;
	return (res);
}

void	width_align_print(char *res, t_printf *p)
{
	p->s_q += p->i_res + 1;
	if (p->width > p->s_q)
	{
		if (p->minus)
		{
			plus_minus_print(res, p);
			print_arg(res, p);
			zero_space_print(p->width - p->s_q, ' ', p);
			return ;
		}
		else
		{
			plus_minus_print(res, p);
			p->zero == 1 ? zero_space_print(p->width - p->s_q, '0', p) :
			zero_space_print(p->width - p->s_q, ' ', p);
		}
	}
	else
		plus_minus_print(res, p);
	print_arg(res, p);
}

int		atoi_width_prec(t_printf *p)
{
	int		temp;

	temp = 0;
	while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
	{
		temp = temp * 10 + p->format[p->i] - '0';
		p->i++;
	}
	p->i -= 1;
	if (temp == -2147483647)
	{
		temp = 0;
		if (p->prec_f == 1)
			p->prec_f = 0;
	}
	return (temp);
}

void	width_f(t_printf *p)
{
	if (p->format[p->i] == '+')
	{
		p->plus_f = 1;
		p->i++;
	}
	if (p->format[p->i] == '-')
	{
		p->minus = 1;
		p->i += 1;
	}
	else if (p->format[p->i] == '0')
	{
		p->zero = 1;
		p->i += 1;
	}
	p->width = atoi_width_prec(p);
}
