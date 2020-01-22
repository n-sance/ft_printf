/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:56:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 09:43:58 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n')
		end--;
	if (end == 0)
		return (ft_strnew(1));
	new_str = ft_strnew(end - start);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, &s[start], end - start);
	return (new_str);
}
