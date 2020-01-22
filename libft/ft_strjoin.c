/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:14:13 by pcarolei          #+#    #+#             */
/*   Updated: 2019/12/29 04:02:21 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1 - ((ft_strlen(s1) == 0)
				|| (ft_strlen(s2) == 0)));
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, s1, ft_strlen(s1));
	ft_strncpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	return (ptr);
}
