#include "ft_printf.h"

int		get_dot_pos(char *str)
{
	int i;

	i = 0;
	while ((str[i]) && (str[i] != '.'))
		i++;
	return (i);
}

char	*float_round_prec_0(char *str)
{
	int		i;
	int		carry;
	int		sum;

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
	return (ft_strsub(str, 0, get_dot_pos(str)));
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
	while(i < a + precision)
		if (str[i] == '9')
			i++;
		else
			return(0);
	return(1);
}

void swap_dot(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if (str[i] == '.' && str[i + 1])
		{
			str[i + 1] = '.';
			str[i] = '9';
			i++;
		}
		i++;
	}
}
char	*float_round(char *str, int precision)
{
	char	*res;
	int		i;
	int		carry;

	i = get_dot_pos(str) + precision + 1 + round_exception(str, precision);
	if (!(res = (char *)malloc(i + 1)))
		return (NULL);
	carry = (str[i] >= '5') ? 1 : 0;
	res[i] = '\0';
	if (round_exception(str, precision))
	{
		res[0] = '1';
		swap_dot(str);
	}
	while ((--i) > 0)
	{
		if (str[i] == '.')
			res[i] = '.';
		else if ((str[i] == '9') && (carry == 1))
		{
			carry = 1;
			res[i] = '0';
		}
		else
		{
			res[i] = str[i] + carry;
			carry = 0;
		}
	}
	return (res);
}

char	*float_round_wrapper(char *str, int precision)
{
	if (precision == 0)
		return (float_round_prec_0(str));
	return (float_round(str, precision));
}
