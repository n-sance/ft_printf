/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:14:36 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 21:38:00 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_lu(t_printf *p, unsigned long lu, char *res)
{
	p->i_res = 0;
	while (lu != 0)
	{
		if (lu % p->base < 10)
			res[p->i_res] = lu % p->base + '0';
		else if (lu % p->base >= 10)
			res[p->i_res] = lu % p->base + p->box[p->lcase] - 10;
		lu /= p->base;
		p->i_res += 1;
	}
	p->i_res -= 1;
	preprint(res, p);
}

void	itoa_base(t_printf *p, char *res)
{
	p->i_res = 0;
	while (p->arg != 0)
	{
		if (p->arg % p->base < 10)
			res[p->i_res] = p->arg % p->base + '0';
		else if (p->arg % p->base >= 10)
			res[p->i_res] = p->arg % p->base + p->box[p->lcase] - 10;
		p->arg /= p->base;
		p->i_res += 1;
	}
	p->i_res -= 1;
	preprint(res, p);
}

void	exception(t_printf *p, char *res)
{
	if (p->arg == 0)
	{
		p->exept_zero = 1;
		res[0] = '0';
		p->i_res = 0;
	}
	else if (p->arg == -2147483648)
	{
		res = ft_strcpy(res, "8463847412-");
		p->i_res = 10;
	}
	else if (p->arg - 1 == 9223372036854775807)
	{
		res = ft_strcpy(res, "8085774586302733229-");
		p->i_res = 19;
	}
	preprint(res, p);
}

void	itoa_decimal(t_printf *p, char *res)
{
	int	sign;

	p->i_res = 0;
	sign = (p->arg < 0) ? -1 : 0;
	if (sign < 0)
		p->arg = -p->arg;
	while (p->arg != 0)
	{
		if (p->arg % p->base < 10)
			res[p->i_res] = p->arg % p->base + '0';
		else if (p->arg % p->base >= 10)
			res[p->i_res] = p->arg % p->base + p->box[p->lcase] - 10;
		p->arg /= p->base;
		p->i_res += 1;
	}
	if (sign == -1 && p->base == 10)
	{
		res[p->i_res] = '-';
		preprint(res, p);
		return ;
	}
	p->i_res -= 1;
	preprint(res, p);
}

void	dioux(t_printf *p)
{
	char			*res;
	unsigned long	ul;

	if (!(res = (char *)malloc(sizeof(char) * 100)))
		exit(-1);
	if (p->mod[0] == 'l' && (p->unsign == 1 || p->base != 10))
	{
		if (!(ul = va_arg(p->ap, unsigned long)))
			exception(p, res);
		else
			itoa_lu(p, ul, res);
		return ;
	}
	p->arg = va_arg(p->ap, long long int);
	cast_arg(p);
	if (p->arg == 0 || p->arg == -2147483648 ||
			p->arg - 1 == 9223372036854775807)
	{
		exception(p, res);
		return ;
	}
	p->base != 10 ? itoa_base(p, res) : itoa_decimal(p, res);
}
