/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 22:44:05 by amargy            #+#    #+#             */
/*   Updated: 2019/05/02 23:32:10 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		i2;

	i2 = 0;
	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s3 = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s3[i - 1] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		s3[i] = s2[i2];
		i++;
		i2++;
	}
	return (s3);
}
