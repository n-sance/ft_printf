/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 01:38:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/12 01:53:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len >= len)
		ft_memcpy((void *)dst, (void *)src, len);
	if (src_len < len)
	{
		ft_memcpy((void *)dst, (void *)src, src_len);
		ft_memset((void *)(&dst[src_len]), (int)'\0', len - src_len);
	}
	return (dst);
}
