#include "ft_printf.h"

void	print_buff(t_printf *p)
{
	write(1, p->buff, p->i_buff);
	p->s += p->i_buff;
	p->i_buff = 0;
}

void	buffcpy(char *res, t_printf *p, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (p->i_buff >= BUFF_SIZE_P)
			print_buff(p);
		p->buff[p->i_buff] = res[i];
		i++;
		p->i_buff++;
	}
}

void	print_arg(char *res, t_printf *p)
{
	if (p->string_f || p->char_f)
	{
		buffcpy(res, p, p->i_res + 1);
		return ;
	}
	while (p->i_res >= 0)
	{
		if (p->i_buff >= BUFF_SIZE_P)
			print_buff(p);
		p->buff[p->i_buff] = res[p->i_res];
		p->i_buff++;
		p->i_res--;
	}
	if (!p->float_f)
		free(res);
	res = NULL;
}
