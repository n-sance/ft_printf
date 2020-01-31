#include "ft_printf.h"

void	xf(t_printf *p)
{
	p->base = 16;
	p->lcase = 0;
	dioux(p);
	p->spec_found = 1;
}

void	upx_f(t_printf *p)
{
	p->base = 16;
	p->lcase = 1;
	dioux(p);
	p->spec_found = 1;
}

void	intf(t_printf *p)
{
	p->base = 10;
	dioux(p);
	p->spec_found = 1;
}

void	check_unsigned(t_printf *p)
{
	if (p->format[p->i] == 'u')
		p->unsign = 1;
	p->base = 10;
	dioux(p);
	p->spec_found = 1;
}

void	long_f(t_printf *p)
{
	if (p->format[p->i] == 'l' && p->format[p->i + 1] != 'l')
		p->mod[0] = 'l';
	else if (p->format[p->i] == 'l' && (p->format[p->i + 1] == 'l'))
	{
		p->mod[0] = 'l';
		p->mod[1] = 'l';
	}
}
