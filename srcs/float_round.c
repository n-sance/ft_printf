/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:44 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 20:37:41 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*float_round_prec_0(char *str, int sharp_f)
{
	int		i;
	char	*temp;

	i = get_dot_pos(str);
	temp = 0;
	fl_round_pr_0_handle(i, str);
	if (sharp_f)
		temp = ft_strsub(str, 0, get_dot_pos(str) + 1);
	else
		temp = ft_strsub(str, 0, get_dot_pos(str));
	free(str);
	return (temp);
}

char	*fl_round_pr_0_handle(int i, char *str)
{
	int sum;
	int carry;

	carry = (str[i + 1] >= '5') ? 1 : 0;
	while (--i >= 0)
	{
		sum = ((str[i] - '0') + carry);
		if (sum > 9)
		{
			carry = 1;
			str[i] = '0';
		}
		else
		{
			carry = 0;
			str[i] = sum + '0';
		}
	}
}

int		round_exception(char *str, int precision)
{
	int i;
	int a;

	i = 0;
	while (str[i] && str[i] != '.')
		if (str[i] == '9')
			i++;
		else
			return (0);
	i++;
	a = i;
	while (i < a + precision + 1)
		if (str[i] == '9')
			i++;
		else
			return (0);
	return (1);
}

void	flat_around_handler(int i, char *str, int carry)
{
	int		sum;

	sum = 0;
	while (--i >= 0)
	{
		if (str[i] == '.')
			i--;
		sum = ((str[i] - '0') + carry);
		if (sum > 9 && carry)
		{
			carry = 1;
			str[i] = '0';
		}
		else
		{
			carry = 0;
			str[i] = sum + '0';
		}
	}
}

char	*float_round(char *str, int precision)
{
	int		i;
	int		carry;
	char	*r;

	r = 0;
	i = get_dot_pos(str) + precision + 1;
	carry = (str[i] >= '5') ? 1 : 0;
	flat_around_handler(i, str, carry);
	r = ft_strsub(str, 0, get_dot_pos(str) + precision + 1);
	free(str);
	return (r);
}
