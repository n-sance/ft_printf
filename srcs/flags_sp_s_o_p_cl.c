/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_sp_s_o_p_cl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:14:44 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:14:45 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_f(t_printf *p)
{
	p->space_f = 1;
}

void	str_f(t_printf *p)
{
	char	*res;

	p->string_f = 1;
	res = va_arg(p->ap, char *);
	if (res == NULL)
		res = "(null)";
	while (res[p->i_res] != '\0')
		p->i_res++;
	p->i_res--;
	preprint(res, p);
	p->spec_found = 1;
}

void	o_f(t_printf *p)
{
	p->base = 8;
	dioux(p);
	p->spec_found = 1;
}

void	ptr_f(t_printf *p)
{
	char			*res;
	unsigned long	ul;

	if (!(res = (char *)malloc(sizeof(char) * 100)))
		exit(-1);
	p->ptr_f = 1;
	p->base = 16;
	ul = va_arg(p->ap, unsigned long);
	if (ul == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		preprint(res, p);
		p->spec_found = 1;
		return ;
	}
	itoa_lu(p, ul, res);
	cast_arg(p);
	p->spec_found = 1;
}

void	capital_long_f(t_printf *p)
{
	p->length_capital_l = 1;
}
