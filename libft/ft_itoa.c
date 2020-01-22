/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 02:38:30 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 08:04:27 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_itoa_min_int_helper(void)
{
	char	*part1;
	char	*part2;
	char	*res;

	part1 = ft_itoa(-2147483);
	part2 = ft_itoa(648);
	if (!part1 || !part2)
		return (NULL);
	res = ft_strcat(part1, part2);
	return (res);
}

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*n_string;
	int		flag;

	flag = ((n < 0) ? 1 : 0);
	i = 1;
	n_size = get_number_len(n) + flag;
	if (n == -2147483648)
		return (ft_itoa_min_int_helper());
	n_string = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!n_string)
		return (NULL);
	if (n < 0)
		n_string[0] = '-';
	n = ((n < 0) ? (-n) : n);
	while (i <= n_size)
	{
		if (n_size - i == 0 && flag == 1)
			break ;
		n_string[n_size - (i++)] = n % 10 + '0';
		n = n / 10;
	}
	n_string[n_size] = '\0';
	return (n_string);
}
