/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_main_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:40 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 20:37:05 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_point(char **s, t_printf *p)
{
	char		*tmp;

	if (p->sharp == 1 && p->prec == 0 && **s != 'n' && **s != 'i'
		&& *(*s + 1) != 'i')
	{
		tmp = *s;
		*s = ft_strjoin(tmp, ".");
		free(tmp);
	}
}

char	*ft_ftoa(long double value, t_printf *p)
{
	int					sign;
	char				f_in_bits[80];
	char				*out;
	t_fl_to_str			bytes;

	sign = 0;
	out = 0;
	bytes.num = value;
	ftoa_handler(bytes, f_in_bits);
	sign = f_in_bits[0] - '0';
	out = float_round_wrapper(bits_to_str_of_num(sign, f_in_bits),
	p->prec, p->sharp);
	return (out);
}

void	return_function(char *s, t_printf *p)
{
	int		i;
	char	*res;

	i = ft_strlen(s);
	res = 0;
	check_point(&s, p);
	res = (char *)malloc(sizeof(char) * i);
	while (--i >= 0)
	{
		res[p->i_res] = s[i];
		p->i_res++;
	}
	p->i_res--;
	if (res[p->i_res] == 'n')
		p->nan_f = 1;
	if (res[p->i_res] == 'i' || res[p->i_res - 1] == 'i')
		p->inf_f = 1;
	free(s);
	preprint(res, p);
}

void	float_handler(t_printf *p)
{
	char			*ret;
	long double		value;
	int				precise;

	ret = 0;
	precise = 6;
	if (p->length_capital_l)
		value = va_arg(p->ap, long double);
	else
		value = va_arg(p->ap, double);
	if (value != value)
	{
		ret = ft_strdup("nan");
		p->plus_f = 0;
		p->space_f = 0;
		p->zero = 0;
	}
	else
		ret = nan_and_inf_handler(p, value);
	return_function(ret, p);
	p->spec_found = 1;
}

char	*nan_and_inf_handler(t_printf *p, long double value)
{
	char *ret;

	ret = 0;
	if (!p->prec_f)
		p->prec = 6;
	if (value == (1.0 / 0.0))
	{
		p->inf_f = 1;
		p->zero = 0;
		ret = ft_strdup("inf");
	}
	else if (value == (-1.0 / 0.0))
	{
		ret = ft_strdup("-inf");
		p->zero = 0;
		p->inf_f = 1;
	}
	else
	{
		ret = ft_ftoa(value, p);
		p->float_f = 1;
	}
	return (ret);
}
