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

char *ft_ftoa(long double value, t_printf *p)
{
	int sign = 0;
    char float_in_bits[80];
	char *out = 0;
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
	out = float_round_wrapper(bits_to_str_of_num(sign, float_in_bits), p->prec, p->sharp);
    return(out);
}

void	return_function(char *s, t_printf *p)
{
	int		i;
	//char res[512];
	char *res;
	i = ft_strlen(s);
	//res = 0;
	res = 0;
	check_point(&s, p);
		//while (s[i] != '\0')
			//i++;
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
		//ret = (char[4]){"nan\0"};
		p->plus_f = 0;
		p->space_f = 0;
		p->zero = 0;
	}
	else
	{
		if(!p->prec_f)
			p->prec = 6;
		if (value == (1.0 /0.0))
			{
				p->inf_f = 1;			//check maybe this flag is useless?
				p->zero = 0;
				ret = ft_strdup("inf");
				//ret = (char[4]){"inf\0"};
			}
		else if (value == (-1.0/0.0))
			{
				ret = (char *)malloc(sizeof(char) * 5);
				ret[0] = '-';
				ret[1] = 'i';
				ret[2] = 'n';
				ret[3] = 'f';
				ret[4] = 0;
				p->zero = 0;
				p->inf_f = 1;			//check maybe this flag is useless?
			}
		else
		{
			ret = ft_ftoa(value, p);
			p->float_f = 1;
		}
	}
		return_function(ret, p);
		p->spec_found = 1;
}
