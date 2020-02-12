/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus_zero_space_sharp.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:16:08 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:16:09 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	plus_minus_print(char *res, t_printf *p)
{
	if (p->zero == 1)
	{
		if (res[p->i_res] == '-')
		{
			buffcpy("-", p, 1);
			p->i_res--;
		}
		else if (p->plus_f == 1)
		{
			buffcpy("+", p, 1);
			p->width--;
		}
	}
	else if (p->unsign != 1 && !p->string_f && !p->char_f)
	{
		if (p->plus_f == 1 && res[p->i_res] != '-')
		{
			res[++p->i_res] = '+';
			p->s_q++;
		}
	}
}

void	zero_space_print(int quantity, char s, t_printf *p)
{
	int i;

	i = 0;
	if (p->base != 8)
		if (p->sharp == 1 && (p->minus == 1 || p->zero == 1))
			if (p->exept_zero == 0 && !p->nan_f && !p->inf_f)
				quantity -= 2;
	while (i < quantity)
	{
		if (p->i_buff >= BUFF_SIZE_P)
			print_buff(p);
		p->buff[p->i_buff] = s;
		p->i_buff++;
		i++;
	}
}

void	sharp_res(char *res, t_printf *p)
{
	if (p->base == 16 && res[p->i_res] != ' ' && !p->exept_zero)
	{
		if (p->minus == 0 && p->zero == 0)
		{
			if (p->lcase == 1)
				res[p->i_res + 1] = 'X';
			else
				res[p->i_res + 1] = 'x';
			res[p->i_res + 2] = '0';
			p->i_res += 2;
			return ;
		}
		if (p->lcase == 1)
			buffcpy("0X", p, 2);
		else
			buffcpy("0x", p, 2);
	}
	else if (p->base == 8 && (!p->exept_zero || p->prec > 0))
	{
		p->i_res++;
		res[p->i_res] = '0';
	}
}

void	space_flag_print(char *res, t_printf *p)
{
	if (res[p->i_res] == '-')
		return ;
	else if (p->unsign == 0)
	{
		buffcpy(" ", p, 1);
		p->width--;
	}
}
