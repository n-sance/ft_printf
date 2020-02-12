/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:16:04 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:16:05 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	second_percent(t_printf *p)
{
	if (p->minus)
	{
		p->buff[p->i_buff] = '%';
		buffcpy("%", p, 1);
		while (--p->width > 0)
			buffcpy(" ", p, 1);
	}
	else
	{
		while (--p->width > 0)
			buffcpy(" ", p, 1);
		buffcpy("%", p, 1);
	}
}

void	print_to_percent(t_printf *p)
{
	while (p->format[p->i] != '%' && p->format[p->i] != '\0')
	{
		if (p->i_buff >= BUFF_SIZE_P)
			print_buff(p);
		p->buff[p->i_buff] = p->format[p->i];
		p->i_buff++;
		p->i++;
	}
	p->i -= 1;
}

void	percent_found(t_printf *p, t_function_point_array fpa[256])
{
	p->i++;
	while (p->format[p->i] != '\0')
	{
		if ((p->format[p->i] == '%' && p->format[p->i + 1] == '\0')
			|| p->format[p->i] == '%')
		{
			second_percent(p);
			return ;
		}
		(*fpa[(unsigned char)p->format[p->i]])(p);
		if (p->spec_found == 1)
			break ;
		p->i++;
	}
	if (p->format[p->i] == '\0')
		p->i--;
}

int		pars(t_printf *p, t_function_point_array fpa[256])
{
	p->static_ft_printf = 1;
	p->i = 0;
	p->s = 0;
	p->i_buff = 0;
	p->box[0] = 'a';
	p->box[1] = 'A';
	put_zero(p);
	while (p->format[p->i] != '\0')
	{
		if (p->format[p->i] == '%')
		{
			percent_found(p, fpa);
			put_zero(p);
		}
		else
			print_to_percent(p);
		p->i += 1;
	}
	print_buff(p);
	return (p->s);
}
