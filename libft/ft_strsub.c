/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:05:00 by jremarqu          #+#    #+#             */
/*   Updated: 2019/04/28 01:24:35 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cps;

	if (s == 0)
		return (0);
	i = 0;
	cps = ft_strnew(len);
	if (cps == 0)
		return (0);
	while (i < len)
		cps[i++] = s[start++];
	return (cps);
}
