/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:38:32 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 20:49:42 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}