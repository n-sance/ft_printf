#include "ft_printf.h"

char	*concat_parts(char *integer_part, char *fract_part, char sign)
{
	char	*numstr;
	int		i;
	int		j;

	if (!(numstr = (char *)malloc(ft_strlen(integer_part) +
									ft_strlen(fract_part) + 2)))
		return (NULL);
	i = 0;
	while (integer_part[i])
	{
		numstr[i] = integer_part[i];
		i++;
	}
	numstr[i++] = '.';
	j = -1;
	while (fract_part[++j])
		numstr[i + j] = fract_part[j];
	numstr[i + j] = '\0';
	if (sign == '1')
		numstr = prepend_minus(numstr);
	free(integer_part);
	free(fract_part);
	return (numstr);
}

