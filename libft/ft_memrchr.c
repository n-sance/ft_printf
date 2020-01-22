/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:44:03 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/13 15:47:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = n;
	ptr = (unsigned char *)s;
	while (ptr[i] != (unsigned char)c && i > 0)
		i--;
	if (ptr[i] == (unsigned char)c)
		return ((void *)(&ptr[i]));
	return (NULL);
}
