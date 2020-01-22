/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:01:16 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 08:23:04 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		new_str[i] = f(s[i]);
		i++;
	}
	return (new_str);
}
