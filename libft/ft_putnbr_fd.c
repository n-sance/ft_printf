/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:32:56 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/12 00:38:56 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;
	int	array_digits[10];
	int	i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	sign = -2 + 3 * (n > 0) + (n < 0);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (n != 0)
	{
		array_digits[i++] = sign * (n % 10);
		n /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(array_digits[i--] + '0', fd);
}
