/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:01:57 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 13:03:00 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] == c)
		start++;
	while (s[end - 1] == c)
		end--;
	if (end == 0)
		return (ft_strnew(1));
	new_str = ft_strnew(end - start);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, &s[start], end - start);
	return (new_str);
}
