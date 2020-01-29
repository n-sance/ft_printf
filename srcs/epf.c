#include "ft_printf.h"
#include "libft.h"

void	epf_free(t_ld_epf *epf)
{
	if (epf->integer_part_bin)
		free(epf->integer_part_bin);
	if (epf->fract_part_bin)
		free(epf->fract_part_bin);
}


char	*epf_to_numstr(t_ld_epf *epf)
{
	char	*integer_part;
	char	*fract_part;

	if ((!epf->integer_part_bin) || (!epf->fract_part_bin))
		return (NULL);
	integer_part = epf_to_integer_part(epf);
	fract_part = epf_to_fract_part(epf);
	return (concat_parts(integer_part,
							complete_fract_part(fract_part), epf->sign));
}

char	*epf_to_integer_part(t_ld_epf *epf)
{
	int		i;
	char	*integer_part;

	i = 0;
	integer_part = str_from_char('0');
	while (epf->integer_part_bin[i])
	{
		if (epf->integer_part_bin[i] == '1')
			integer_part = bignum_sum(power_of_2(epf->exp_dec), integer_part);
		epf->exp_dec--;
		i++;
	}
	return (integer_part);
}

char	*epf_to_fract_part(t_ld_epf *epf)
{
	int		i;
	int		len;
	int		last;
	char	*fract_part;
	char	*add;

	i = 0;
	len = (int)ft_strlen(epf->fract_part_bin);
	if (epf->exp_dec < -1000)
		return (ft_strdup("0"));
	fract_part = str_from_char('0');
	while (epf->fract_part_bin[i])
	{
		if (epf->fract_part_bin[i] == '1')
		{
			add = power_of_5(ABS(epf->exp_dec) + i);
			add = mult_by_10_n_times(add, len - 1 - i);
			fract_part = bignum_sum(add, fract_part);
			last = ABS(epf->exp_dec) + i;
		}
		i++;
	}
	return (prepend_zeroes(fract_part, last));
}


char	*prepend_zeroes(char *str, int last)
{
	char	*finstr;
	int		true_len;
	int		diff;
	int		i;

	true_len = count_without_postfix_zeroes(str);
	diff = last - true_len;
	if (!(finstr = (char *)malloc(last + 1)))
		return (NULL);
	i = 0;
	while (i < diff)
	{
		finstr[i] = '0';
		i++;
	}
	while (i < last)
	{
		finstr[i] = str[i - diff];
		i++;
	}
	finstr[last] = '\0';
	free(str);
	return (finstr);
}
