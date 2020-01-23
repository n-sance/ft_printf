#include "ft_printf.h"


char	*power_of_2(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (str_from_char('1'));
	res = str_from_char('2');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 2);
		i++;
	}
	return (res);
}

char	*power_of_5(int n)
{
	int		i;
	char	*res;

	if (n == 0)
		return (str_from_char('1'));
	res = str_from_char('5');
	i = 1;
	while (i < n)
	{
		res = bignum_multiply_by_n(res, 5);
		i++;
	}
	return (res);
}


char	*mult_by_10_n_times(char *num, int n)
{
	char	*res;

	res = num;
	while (n > 0)
	{
		res = bignum_multiply_by_n(res, 10);
		n--;
	}
	return (res);
}

char	*bignum_multiply_by_n(char *num, int n)
{
	int		i;
	int		carry;
	int		prod;
	int		len;
	char	*res;

	i = 0;
	carry = 0;
	len = (int)ft_strlen(num);
	num = str_rev(num);
	res = NULL;
	while (i < len)
	{
		prod = (num[i] - '0') * n + carry;
		res = push_back(res, (prod % 10) + '0');
		carry = prod / 10;
		i++;
	}
	while (carry)
	{
		res = push_back(res, (carry % 10) + '0');
		carry /= 10;
	}
	free(num);
	return (str_rev(res));
}

int		ft_pow(int n, int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res *= n;
		pow--;
	}
	return (res);
}
