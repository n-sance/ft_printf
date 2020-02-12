/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:52 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 21:02:33 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*concat_parts(char *int_part, char *fract_part, char sign)
{
	char	*numstr;
	int		i;
	int		j;

	if (!(numstr = (char *)malloc(ft_strlen(int_part) +
									ft_strlen(fract_part) + 2)))
		return (NULL);
	i = 0;
	while (int_part[i])
	{
		numstr[i] = int_part[i];
		i++;
	}
	numstr[i++] = '.';
	j = -1;
	while (fract_part[++j])
		numstr[i + j] = fract_part[j];
	numstr[i + j] = '\0';
	if (sign == '1')
		numstr = prepend_minus(numstr);
	free(int_part);
	free(fract_part);
	return (numstr);
}

void	reverse(unsigned char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	temp = 0;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
