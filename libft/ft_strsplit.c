/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:47:02 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 13:50:31 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbw(const char *str, char c)
{
	int word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static int		ft_ln(const char *str, char c)
{
	int cnt;

	cnt = 0;
	while (*str != c && *str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**res;

	i = 0;
	j = 0;
	if (!s || (!(res = (char **)malloc(sizeof(char *) * (ft_nbw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(res[j] = (char *)malloc(sizeof(char) * (ft_ln(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				res[j][i++] = (char)*s++;
			res[j][i] = '\0';
			i = 0;
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
