/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:21:38 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 08:22:09 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = ft_strnew(s_len);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}
