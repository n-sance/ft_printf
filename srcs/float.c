#include "ft_printf.h"



// Реверсирует строку из цифр после конвертации из int
void reverse(unsigned char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}


void	byte_to_bits(char byte, char *bits_from_byte)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		bits_from_byte[i] = (byte & (1 << i) ? '1' : '0');
		i--;
	}
}

void	copy_bits_from_byte(char *bits_from_byte, char *bits, int pos)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bits[80 - pos - i] = bits_from_byte[i];
		i++;
	}
}

void	float_to_bits(char *bytes, char *bits)
{
	char	bits_from_byte[8];
	int		i;
	int		pos;

	i = 0;
	pos = 1;
	while (i < 10)
	{
		byte_to_bits(bytes[i], bits_from_byte);
		copy_bits_from_byte(bits_from_byte, bits, pos);
		i++;
		pos += 8;
	}
	copy_bits_from_byte(bits_from_byte, bits, 80);
	i = 0;
}

void			check_point(char **s, t_printf *p)
{
	char		*tmp;

	if (p->sharp == 1 && p->prec == 0 && **s != 'n' && **s != 'i'
		&& *(*s + 1) != 'i')
	{
		tmp = *s;
		*s = ft_strjoin(tmp, ".");
		free(tmp);
	}
}

//конвертирует из long double в строку
// n - переводимое число
// res - строка в которую сохраняем число
// afterpoint - точность с которой сохраняем знаки после запятой
char *ft_ftoa(long double value, int afterpoint)
{
	int sign = 0;
    char float_in_bits[80];
    t_fl_to_str bytes;
    char bits_in_byte_buffer[8];
    int pos = 1;
    int i = 0;
    bytes.num = value;
    while(i < 10)
    {
        byte_to_bits(bytes.str[i], bits_in_byte_buffer);
        copy_bits_from_byte(bits_in_byte_buffer, float_in_bits, pos);
        i++;
        pos += 8;
    }
	sign = float_in_bits[0] - '0';
    return(float_round_wrapper(bits_to_str_of_num(sign, float_in_bits), afterpoint));
}

void	return_function(char *s, t_printf *p)
{
	int		i;
	char *res;
	i = 0;
	res = 0;
	check_point(&s, p);
		while (s[i] != '\0')
			i++;
		res = (char *)malloc(sizeof(char) * i);
		while (--i >= 0)
		{
			res[p->i_res] = s[i];
			p->i_res++;
		}
		p->i_res--;
		if (res[p->i_res] == 'n')
			p->nan_f = 1;
		if (res[p->i_res] == 'i' || res[p->i_res - 1] == 'i')
			p->inf_f = 1;
		free(s);
	preprint(res, p);
}

//главня функция
void	float_handler(t_printf *p)
{
	char *ret;
	long double value; //число которое переводим
	int precise; //точность
	ret = 0;
    precise = 6;
	//если есть L то ждем переменную long double, если нет то double
	if (p->length_capital_l)
		value = va_arg(p->ap, long double);
	else
		value = va_arg(p->ap, double);
	if (value != value)
	{
		ret = ft_strdup("nan");
		p->plus_f = 0;
		p->space_f = 0;
	}
	else
	{
		if(!p->prec_f)
			p->prec = 6;
	//	if (value < 0)
	//	{
	//		sign = 1;
	//		value *= -1;
	//	}
		if (value == (1.0 /0.0))
			{
				p->inf_f = 1;			//check maybe this flag is useless?
				ret = ft_strdup("inf");
			}
		else if (value == (-1.0/0.0))
			{
				ret = ft_strdup("-inf");
				p->inf_f = 1;			//check maybe this flag is useless?
			}
		else
			ret = ft_ftoa(value, p->prec);
	}
		return_function(ret, p);
		p->spec_found = 1;
}



