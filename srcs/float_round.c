#include "ft_printf.h"

int		get_dot_pos(char *str)
{
	int i;

	i = 0;
	while ((str[i]) && (str[i] != '.'))
		i++;
	return (i);
}

char	*float_round_prec_0(char *str, int sharp_f)
{
	int		i;
	int		carry;
	int		sum;
	char *temp = 0;
	i = get_dot_pos(str);
	carry = (str[i + 1] >= '5') ? 1 : 0;
	while (--i >= 0)
	{
		sum = ((str[i] - '0') + carry);
		if (sum > 9)
		{
			carry = 1;
			str[i] = '0';
		}
		else
		{
			carry = 0;
			str[i] = sum + '0';
		}
	}
	if (sharp_f)
		temp = ft_strsub(str, 0, get_dot_pos(str) + 1);
	else
		temp = ft_strsub(str, 0, get_dot_pos(str));
	free(str);
	return (temp);
}

int round_exception(char *str, int precision)
{
	int i;
	int a;
	i = 0;
	while (str[i] && str[i] != '.')
		if (str[i] == '9')
			i++;
		else
			return(0);
	i++;
	a = i;
	while(i < a + precision + 1)
		if (str[i] == '9')
			i++;
		else
			return(0);
	return(1);
}

char	*float_round(char *str, int precision)
{
	int		i;
	int		carry;
	int		sum;
	char *r = 0;
	i = get_dot_pos(str) + precision + 1;
	carry = (str[i] >= '5') ? 1 : 0;
	while (--i >= 0)
	{
		if (str[i] == '.')
			i--;
		sum = ((str[i] - '0') + carry);
		if (sum > 9 && carry)
		{
			carry = 1;
			str[i] = '0';
		}
		else
		{
			carry = 0;
			str[i] = sum + '0';
		}
	}
	r = ft_strsub(str, 0, get_dot_pos(str) + precision + 1);
	free(str);
	return (r);
}

char	*float_round_wrapper(char *str, int precision, int sharp_f)
{
	char *out;
	out = 0;
	if (round_exception(str, precision))
	{
		if (!(out = (char *)malloc(sizeof(char) * ft_strlen(str) + 2)))
			exit(-1);
		out[0] = '0';
		out[1] = 0;
		out = ft_strjoin(out, str);
	}
	else
	{
		out = ft_strdup(str);
	}
	free(str);
	if (precision == 0)
		return (float_round_prec_0(out, sharp_f));
	return (float_round(out, precision));
}
