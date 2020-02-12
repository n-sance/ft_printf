/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_get_round.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:08:06 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 20:09:06 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_dot_pos(char *str)
{
	int i;

	i = 0;
	while ((str[i]) && (str[i] != '.'))
		i++;
	return (i);
}

char	*float_round_wrapper(char *str, int precision, int sharp_f)
{
	char *out;

	out = 0;
	if (round_exception(str, precision))
	{
		if (!(out = (char *)malloc(sizeof(char) * ft_strlen(str) + 2)))
			exit(-1);
		out[0] = '0';
		out[1] = 0;
		out = ft_strjoin(out, str);
	}
	else
	{
		out = ft_strdup(str);
	}
	free(str);
	if (precision == 0)
		return (float_round_prec_0(out, sharp_f));
	return (float_round(out, precision));
}
