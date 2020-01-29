#include "ft_printf.h"


char	*bignum_sum(char *num1, char *num2)
{
	char	*res;
	int		sum;
	int		i;
	int		carry;

	swap_str(&num1, &num2, ft_strlen(num1) > ft_strlen(num2));
	num1 = str_rev(num1);
	num2 = str_rev(num2);
	i = 0;
	carry = 0;
	res = NULL;
	while (i < (int)ft_strlen(num2))
	{
		if (i < (int)ft_strlen(num1))
			sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
		else
			sum = (num2[i] - '0') + carry;
		res = push_back(res, (sum % 10) + '0');
		carry = sum / 10;
		i++;
	}
	if (carry)
		res = push_back(res, carry + '0');
	free_nums(num1, num2);
	return (str_rev(res));
}

void	free_nums(char *num1, char *num2)
{
	free(num1);
	free(num2);
}

int		count_without_postfix_zeroes(char *str)
{
	int		len;
	int		zeroes_cnt;
	int		i;

	len = ft_strlen(str);
	i = len - 1;
	zeroes_cnt = 0;
	while (str[i] == '0')
	{
		zeroes_cnt++;
		i--;
	}
	return (len - zeroes_cnt);
}

