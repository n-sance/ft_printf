/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bits_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:00 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 21:03:10 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	byte_to_bits(char byte, char *bits_from_byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		bits_from_byte[i] = (byte & (1 << i) ? '1' : '0');
		i--;
	}
}

void	copy_bits_from_byte(char *bits_from_b, char *bits, int pos)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[80 - pos - i] = bits_from_b[i];
		i++;
	}
}

void	float_to_bits(char *bytes, char *bits)
{
	char	bits_from_byte[8];
	int		i;
	int		pos;

	i = 0;
	pos = 1;
	while (i < 10)
	{
		byte_to_bits(bytes[i], bits_from_byte);
		copy_bits_from_byte(bits_from_byte, bits, pos);
		i++;
		pos += 8;
	}
	copy_bits_from_byte(bits_from_byte, bits, 80);
	i = 0;
}
