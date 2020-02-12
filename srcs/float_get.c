/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:26 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:40:06 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_integer_part_bin(t_ld_epf *epf)
{
	int	size;
	int	i;

	if (epf->exp_dec >= 64)
		size = 64;
	else if (epf->exp_dec >= 0)
		size = epf->exp_dec + 1;
	else
		size = 0;
	if (!(epf->integer_part_bin = (char *)malloc(size + 1)))
		epf->integer_part_bin = NULL;
	i = 0;
	while (i < size)
	{
		epf->integer_part_bin[i] = epf->mnt[i];
		i++;
	}
	epf->integer_part_bin[i] = '\0';
}

void	get_fract_part_bin(t_ld_epf *epf)
{
	int	integer_part_bin_size;
	int	size;
	int	i;

	integer_part_bin_size = ft_strlen(epf->integer_part_bin);
	size = 64 - integer_part_bin_size;
	if (!(epf->fract_part_bin = (char *)malloc(size + 1)))
		epf->fract_part_bin = NULL;
	i = 0;
	while (i < size)
	{
		epf->fract_part_bin[i] = epf->mnt[integer_part_bin_size + i];
		i++;
	}
	epf->fract_part_bin[i] = '\0';
}

void	get_exponent_from_bits(char *bits, char *exp)
{
	int	i;

	i = 1;
	while (i < 16)
	{
		exp[i - 1] = bits[i];
		i++;
	}
}

void	get_mantissa_from_bits(char *bits, char *mnt)
{
	int	i;

	i = 16;
	while (i < 80)
	{
		mnt[i - 16] = bits[i];
		i++;
	}
}

void	get_decimal_exponent(t_ld_epf *epf)
{
	int	i;
	int	exp_dec;

	i = 0;
	exp_dec = 0;
	while (i < 15)
	{
		exp_dec += (epf->exp[14 - i] - '0') * ft_pow(2, i);
		i++;
	}
	epf->exp_dec = (exp_dec - 16383);
}
