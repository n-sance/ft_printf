#include "ft_printf.h"

char	*complete_fract_part(char *str)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len > LEN)
		return (str);
	if (!(newstr = (char *)malloc(LEN)))
		return (NULL);
	newstr[LEN] = '\0';
	i = 0;
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	while (i < LEN)
	{
		newstr[i] = '0';
		i++;
	}
	free(str);
	return (newstr);
}

char	*str_rev(char *str)
{
	char	*str_rev;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (str_len == 1)
		return (str);
	if (!(str_rev = (char *)malloc(str_len + 1)))
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str_rev[i] = str[str_len - 1 - i];
		i++;
	}
	str_rev[i] = '\0';
	free(str);
	return (str_rev);
}

char	*prepend_minus(char *numstr)
{
	char	*minus_str;
	char	*res_str;

	minus_str = ft_strnew(2);
	minus_str[0] = '-';
	res_str = ft_strjoin(minus_str, numstr);
	free(minus_str);
	free(numstr);
	return (res_str);
}

void	swap_str(char **str1, char **str2, int mode)
{
	char	*swp;

	if (mode == 0)
		return ;
	swp = *str1;
	*str1 = *str2;
	*str2 = swp;
}

char	*push_back(char *res, char c)
{
	char	*new_res;
	size_t	len;
	int		i;

	len = (res == NULL) ? 0 : ft_strlen(res);
	if (!(new_res = (char *)malloc(len + 2)))
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		new_res[i] = res[i];
		i++;
	}
	new_res[i] = c;
	new_res[i + 1] = '\0';
	if (res)
		free(res);
	return (new_res);
}
