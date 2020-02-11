#include "ft_printf.h"

void	bits_to_epf(char *bits, t_ld_epf *epf)
{
	epf->sign = bits[0];
	get_exponent_from_bits(bits, epf->exp);
	get_mantissa_from_bits(bits, epf->mnt);
	get_decimal_exponent(epf);
	get_integer_part_bin(epf);
	get_fract_part_bin(epf);
}


char *bits_to_str_of_num(int sign, char *bits)
{
    t_ld_epf	epf;
	char		*numstr;

	bits_to_epf(bits, &epf);
	epf.sign = (sign == 1) ? '1' : '0';
	numstr = epf_to_numstr(&epf);
	epf_free(&epf);
	return (numstr);

}

char	*str_from_char(char c)
{
	char	*str;

	if (!(str = (char *)malloc(2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
