/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprint_processing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:16:20 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:16:21 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numbers_preprint(char *res, t_printf *p)
{
	if (p->space_f)
		space_flag_print(res, p);
	if (p->prec == 0 && p->exept_zero && p->prec_f == 1)
	{
		if (p->base == 10 && p->plus_f == 1)
			p->i_res--;
		if (p->base == 16 && p->sharp == 1 && !p->width)
			return (0);
		if (p->width == 0 && !(p->sharp == 1 && p->base == 8))
			if (p->plus_f == 0)
				return (0);
		if (p->width > 0 && !(p->sharp == 1 && p->base == 8))
			res[0] = ' ';
		if (p->space_f == 1)
			p->i_res--;
	}
	else if (p->prec > p->i_res && !p->nan_f && !p->inf_f)
		res = precision_d(res, p);
	return (1);
}

void	ptr_preprint(char *res, t_printf *p)
{
	res[p->i_res + 1] = 'x';
	res[p->i_res + 2] = '0';
	p->i_res += 2;
	if (p->prec_f && !p->prec)
	{
		p->i_res = 1;
		res[0] = 'x';
		res[1] = '0';
	}
}

void	preprint(char *res, t_printf *p)
{
	if (p->prec_f == 1 && p->zero == 1 && !p->float_f)
		p->zero = 0;
	if (p->space_f == 1 && p->plus_f == 1)
		p->space_f = 0;
	if (!p->string_f && !p->char_f)
		if (!(numbers_preprint(res, p)))
		{
			return ;
		}
	if (p->ptr_f == 1)
		ptr_preprint(res, p);
	if (p->prec_f && p->prec < p->i_res + 1 && p->string_f)
		p->i_res = p->prec - 1;
	if (p->sharp)
		sharp_res(res, p);
	width_align_print(res, p);
}
