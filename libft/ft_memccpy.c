/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:30:35 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/11 03:43:26 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;

	ptr_d = (char *)dst;
	ptr_s = (char *)src;
	while ((n--) >= 1)
	{
		if ((unsigned char)*ptr_s == (unsigned char)c)
		{
			*ptr_d++ = *ptr_s++;
			return ((void *)ptr_d);
		}
		*ptr_d++ = *ptr_s++;
	}
	return (NULL);
}
