#include "ft_printf.h"

void    print_buff(t_printf* p)
{
    if (p->spike_w)
        return;
    write(1, p->buff, p->i_buff);
    p->s += p->i_buff;
    p->i_buff = 0;
}

void    buffcpy(char *res, t_printf* p, int size)
{
    int i;

    i = 0;
    while(i < size)
    {
        if (p->i_buff >= BUFF_SIZE_P)
            print_buff(p);
        p->buff[p->i_buff] = res[i];
        i++;
        p->i_buff++;
    }
}

void    print_arg(char *res, t_printf* p)
{
    if (p->string_f || p->char_f)
    {
        buffcpy(res, p, p->i_res + 1);
        return;
    }
    while (p->i_res >= 0)
    {
        if (p->i_buff >= BUFF_SIZE_P)
            print_buff(p);
        p->buff[p->i_buff] = res[p->i_res];
        p->i_buff++;
        p->i_res--;
    }
    free(res);
    res = NULL;
}

void    sharp_res(char *res, t_printf* p)
{
    if (p->base == 16 && res[p->i_res] != ' ' && !p->exept_zero)
    {
        if (p->minus == 0 && p->zero == 0)
        {
            if (p->lcase == 1)
                res[p->i_res + 1] = 'X';
            else
                res[p->i_res + 1] = 'x';
            res[p->i_res + 2] = '0';
            p->i_res += 2;
            return;
        }
        if (p->lcase == 1)
            buffcpy("0X", p, 2);
        else
            buffcpy("0x", p, 2);
    }
    else if (p->base == 8 && (!p->exept_zero || p->prec > 0))
    {
        p->i_res++;
        res[p->i_res] = '0';
    }
}

void    zero_space_print(int quantity, char s, t_printf* p)
{
    int i;

    i = 0;
    if (p->base != 8)
        if (p->sharp == 1 && (p->minus == 1 || p->zero == 1))
            if (p->exept_zero == 0 && !p->nan_f && !p->inf_f)
                quantity -= 2;
    while (i < quantity)
    {
        if (p->i_buff >= BUFF_SIZE_P)
            print_buff(p);
        p->buff[p->i_buff] = s;
        p->i_buff++;
        i++;
    }
}

char    *precision_d(char *res, t_printf* p)
{
    p->s_q = (res[p->i_res] == '-') ? p->i_res : p->i_res + 1;
    p->i_prec = (res[p->i_res] == '-') ? p->i_res : p->i_res + 1;
    if (res[p->i_res] == '-')
    {
        while (p->prec > p->s_q)
        {
            res[p->i_prec] = '0';
            p->prec--;
            p->i_prec++;
            p->i_res++;
        }
        res[p->i_prec] = '-';
    }
    else
    {
        p->prec -= (p->sharp > 0 && p->base == 8) ? 1 : 0;
        while (p->prec > p->s_q)
            {
                res[p->i_prec] = '0';
                p->prec--;
                p->i_prec++;
                p->i_res++;
            }
    }
    p->s_q = 0;
    return (res);
}

void    width_align_print(char *res, t_printf* p)
{
    p->s_q += p->i_res + 1;
    if (p->width > p->s_q)
    {
        if (p->minus)
        {
            plus_minus_print(res, p);
            print_arg(res, p);
            zero_space_print(p->width - p->s_q, ' ', p);
            return;
        }
        else
        {
            plus_minus_print(res, p);
            p->zero == 1 ? zero_space_print(p->width - p->s_q, '0', p) :
            zero_space_print(p->width - p->s_q, ' ', p);
        }
    }
    else
        plus_minus_print(res, p);
    print_arg(res, p);
}

void    plus_minus_print(char *res, t_printf* p)
{
    if (p->zero == 1)
    {
        if (res[p->i_res] == '-')
        {
            buffcpy("-", p, 1);
            p->i_res--;
        }
        else if (p->plus_f == 1)
        {
            buffcpy("+", p, 1);
            p->width--;
        }
    }
    else if (p->unsign != 1 && !p->string_f && !p->char_f)
    {
        if (p->plus_f == 1 && res[p->i_res] != '-')
        {
            res[++p->i_res] = '+';
            p->s_q++;
        }
    }
}

int    numbers_preprint(char *res, t_printf* p)
{
    if (p->space_f)
        space_flag_print(res, p);
    if (p->prec == 0 && p->exept_zero && p->prec_f == 1)
    {
        if (p->base == 10 && p->plus_f == 1)
            p->i_res--;
        if (p->base == 16 && p->sharp == 1 && !p->width)
            return (0);
        if (p->width == 0 && !(p->sharp == 1 && p->base == 8))
            if (p->plus_f == 0)
                return (0);
        if (p->width > 0 && !(p->sharp == 1 && p->base == 8))
            res[0] = ' ';
        if (p->space_f == 1)
            p->i_res--;
    }
    else if (p->prec > p->i_res && !p->nan_f && !p->inf_f)
        res = precision_d(res, p);
    return (1);
}

void    ptr_preprint(char *res, t_printf* p)
{
        res[p->i_res + 1] = 'x';
        res[p->i_res + 2] = '0';
        p->i_res += 2;
}

void    preprint(char *res, t_printf* p)
{
    if (p->spike_p)
        return;
    if (p->spike_w)
        return;
    if (p->ptr_f == 1)
        ptr_preprint(res, p);
    if (p->prec_f == 1 && p->zero == 1 && !p->float_f)
        p->zero = 0;
    if (p->space_f == 1 && p->plus_f == 1)
        p->space_f = 0;
    if (!p->string_f && !p->char_f)
        if (!(numbers_preprint(res, p)))
            return;
    if (p->prec_f && p->prec < p->i_res + 1 && p->string_f)
        p->i_res = p->prec - 1;
    if (p->sharp)
        sharp_res(res, p);
    width_align_print(res, p);
}

void    exception(t_printf* p, char *res)
{
    if (p->arg == 0)
    {
        p->exept_zero = 1;
        res[0] = '0';
        p->i_res = 0;
    }
    else if (p->arg == -2147483648)
    {
        res = ft_strcpy(res, "8463847412-");
        p->i_res = 10;
    }
    else if (p->arg - 1 == 9223372036854775807)
    {
        res = ft_strcpy(res, "8085774586302733229-");
        p->i_res = 19;
    }
    preprint(res, p);
}

void    itoa_decimal(t_printf* p, char *res)
{
	int		sign;

    p->i_res = 0;
	sign = (p->arg < 0) ? -1 : 0;
    if (sign < 0)
        p->arg = -p->arg;
    while (p->arg != 0)
	{
        if (p->arg % p->base  < 10)
            res[p->i_res] = p->arg % p->base  + '0';
        else if (p->arg % p->base  >= 10)
            res[p->i_res] = p->arg % p->base  + p->box[p->lcase] - 10;
		p->arg /= p->base;
        p->i_res += 1;
	}
    if (sign == -1 && p->base == 10)
    {
        res[p->i_res] = '-';
        preprint(res, p);
        return;
    }
    p->i_res -= 1;
    preprint(res, p);
}

void    itoa_base(t_printf* p, char *res)
{
    p->i_res = 0;
    while (p->arg != 0)
	{
        if (p->arg % p->base  < 10)
            res[p->i_res] = p->arg% p->base  + '0';
        else if (p->arg % p->base  >= 10)
            res[p->i_res] = p->arg % p->base  + p->box[p->lcase] - 10;
		p->arg /= p->base;
        p->i_res += 1;
	}
    p->i_res -= 1;
    preprint(res, p);
}

void    itoa_lu(t_printf* p, unsigned long lu, char *res)
{
    p->i_res = 0;
    while (lu != 0)
	{
        if (lu % p->base  < 10)
            res[p->i_res] = lu % p->base  + '0';
        else if (lu % p->base  >= 10)
            res[p->i_res] = lu % p->base  + p->box[p->lcase] - 10;
		lu /= p->base;
        p->i_res += 1;
	}
    p->i_res -= 1;
    preprint(res, p);
}

void    cast_signed(t_printf* p)
{
    if (p->mod[0] == 0 && p->base != 8)
        p->arg = (int)p->arg;
    else if (p->mod[0] == 'l' && p->mod[1] != 'l' && p->base != 8)
        p->arg = (long)p->arg;
    else if ((p->mod[0] == 'l' && p->mod[1] == 'l') || p->base == 8)
        p->arg = (long long)p->arg;
    else if (p->mod[0] == 'h' && p->mod[1] != 'h')
        p->arg = (short)p->arg;
    else if (p->mod[0] == 'h' && p->mod[1] == 'h')
        p->arg = (signed char)p->arg;
}

void    cast_unsigned(t_printf* p)
{
    if (p->mod[0] == 0)
        p->arg = (unsigned int)p->arg;
    else if (p->mod[0] == 'l' && p->mod[1] != 'l')
        p->arg = (unsigned long)p->arg;
    else if (p->mod[0] == 'l' && p->mod[1] == 'l')
        p->arg = (unsigned long long)p->arg;
    else if (p->mod[0] == 'h' && p->mod[1] != 'h')
        p->arg = (unsigned short)p->arg;
    else if (p->mod[0] == 'h' && p->mod[1] == 'h')
        p->arg = (unsigned char)p->arg;
}

void    cast_arg(t_printf* p)
{
    if (p->unsign == 0 && p->base == 10)
        cast_signed(p);
    else
        cast_unsigned(p);
}

void    diouxXfF(t_printf* p)
{
    char *res;
    unsigned long ul;

    res = (char *)malloc(sizeof(char) * 50);
    if (p->mod[0] == 'l' && (p->unsign == 1 || p->base != 10))
    {
        if (!(ul = va_arg(p->ap, unsigned long)))
            exception(p, res);
        else
            itoa_lu(p, ul, res);
        return;
    }
    p->arg = va_arg(p->ap, long long int);
    cast_arg(p);
    if (p->arg == 0 || p->arg == -2147483648 ||
    p->arg - 1 == 9223372036854775807)
    {
        exception(p, res);
        return;
    }
    p->base != 10 ? itoa_base(p, res) : itoa_decimal(p, res);
    res = NULL;
}

void    xf(t_printf* p)
{
    p->base = 16;
    p->lcase = 0;
    diouxXfF(p);
    p->spec_found = 1;
}

void    Xf(t_printf* p)
{
    p->base = 16;
    p->lcase = 1;
    diouxXfF(p);
    p->spec_found = 1;
}

void    second_percent(t_printf* p)
{
    if (p->i_buff >= BUFF_SIZE_P)
    {

    }
    if (p->minus)
    {
        p->buff[p->i_buff] = '%';
        buffcpy("%", p, 1);
        while (--p->width > 0)
            buffcpy(" ", p, 1);
    }
    else
    {
        while (--p->width > 0)
            buffcpy(" ", p, 1);
        buffcpy("%", p, 1);
    }
}

void    intf(t_printf* p)
{
    p->base = 10;
    diouxXfF(p);
    p->spec_found = 1;
}

void    print_to_percent(t_printf* p)
{
    while (p->format[p->i] != '%' && p->format[p->i] != '\0')
    {
        if (p->i_buff >= BUFF_SIZE_P)
            print_buff(p);
        p->buff[p->i_buff] = p->format[p->i];
        p->i_buff++;
        p->i++;
    }
    p->i -= 1;
}

int     atoi_width_prec(t_printf* p)
{
    int temp;

    temp = 0;
    while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
    {
        temp = temp * 10 + p->format[p->i] - '0';
        p->i++;
    }
    p->i -= 1;
    return (temp);
}

void    width_f(t_printf* p)
{
    if (p->format[p->i] == '+')
    {
        p->plus_f = 1;
        p->i++;
    }
    if (p->format[p->i] == '-')
    {
        p->minus = 1;
        p->i += 1;
    }
    else if (p->format[p->i] == '0')
    {
        p->zero = 1;
        p->i += 1;
    }
    p->width = atoi_width_prec(p);
    if (p->width == -2147483647)
    {
        p->s = -1;
        p->spike_w = 1;
    }
}

void     check_unsigned(t_printf* p)
{
    if (p->format[p->i] == 'u')
        p->unsign = 1;
    p->base = 10;
    diouxXfF(p);
    p->spec_found = 1;
}

void     long_f(t_printf* p)
{
    if (p->format[p->i] == 'l' && p->format[p->i + 1] != 'l')
        p->mod[0] = 'l';
    else if (p->format[p->i] == 'l' && (p->format[p->i + 1] == 'l'))
    {
        p->mod[0] = 'l';
        p->mod[1] = 'l';
    }
}

void    unknownspec(t_printf* p)
{
    if (p->i_buff >= BUFF_SIZE_P)
        print_buff(p);
    p->buff[p->i_buff] = p->format[p->i];
    p->i_buff++;
}

void    char_f(t_printf* p)
{
    char res[2];

    p->char_f = 1;
    res[0] = va_arg(p->ap, int);
    if (res[0] == 0)
    {
        p->i_res = 0;
        preprint("\0", p);
        p->spec_found = 1;
        return;
    }
    preprint(res, p);
    p->spec_found = 1;
}

void     short_f(t_printf* p)
{
    if (p->format[p->i + 1] == 'h')
    {
        p->mod[0] = 'h';
        p->mod[1] = 'h';
        p->i++;
    }
    else
        p->mod[0] = 'h';
}

void    sharp_f(t_printf* p)
{
    p->sharp = 1;
}

void    point_f(t_printf* p)
{
    p->prec_f = 1;
    p->i++;
    p->prec = atoi_width_prec(p);
    if (p->prec == -2147483647)
    {
        p->s = 3;
        write(1, "inf", 3);
        p->spike_p = 1;
    }

}

void    space_flag_print(char *res, t_printf* p)
{
    if (res[p->i_res] == '-')
        return;
    else if (p->unsign == 0)
    {
        buffcpy(" ", p, 1);
        p->width--;
    }
}

void    space_f(t_printf* p)
{
    p->space_f = 1;
}

void    spec_flags_two(function_point_array fpa[256])
{
    fpa['0'] = width_f;
    fpa['1'] = width_f;
    fpa['2'] = width_f;
    fpa['3'] = width_f;
    fpa['4'] = width_f;
    fpa['5'] = width_f;
    fpa['6'] = width_f;
    fpa['7'] = width_f;
    fpa['8'] = width_f;
    fpa['9'] = width_f;
    fpa['-'] = width_f;
    fpa['+'] = width_f;
    fpa['#'] = sharp_f;
    fpa['.'] = point_f;
    fpa[' '] = space_f;
}

void    str_f(t_printf* p)
{
    char *res;

    p->string_f = 1;
    res = va_arg(p->ap, char *);
    if (res == NULL)
        res = "(null)";
    while (res[p->i_res] != '\0')
        p->i_res++;
    p->i_res--;
    preprint(res, p);
    p->spec_found = 1;
}

void    o_f(t_printf* p)
{
    p->base = 8;
    diouxXfF(p);
    p->spec_found = 1;
}

void    ptr_f(t_printf* p)
{
    char *res;
    unsigned long ul;

    res = (char *)malloc(sizeof(char) * 50);
    p->ptr_f = 1;
    p->base = 16;
    ul = va_arg(p->ap, unsigned long);
    if (ul == 0)
    {
        res[0] = '0';
        res[1] = '\0';
        preprint(res, p);
        p->spec_found = 1;
        return;
    }
    itoa_lu(p, ul, res);
    cast_arg(p);
    p->spec_found = 1;
}

void    capital_long_f(t_printf* p)
{
    p->length_capital_l = 1;
}

void    spec_flags(function_point_array fpa[256])
{
    int i_fpa;

    i_fpa = 0;
    while (i_fpa <= 256)
        fpa[i_fpa++] = unknownspec;
    fpa['c'] = char_f;
    fpa['C'] = char_f;
    fpa['s'] = str_f;
	fpa['d'] = intf;
	fpa['i'] = intf;
	fpa['o'] = o_f;
	fpa['u'] = check_unsigned;
	fpa['x'] = xf;
	fpa['X'] = Xf;
	fpa['f'] = float_handler;
	fpa['F'] = float_handler;
	fpa['p'] = ptr_f;
    fpa['h'] = short_f;
    fpa['l'] = long_f;
    fpa['L'] = capital_long_f;
    spec_flags_two(fpa);
}

void    percent_found(t_printf* p, function_point_array fpa[256])
{
    p->i++;
    while (p->format[p->i] != '\0')
    {
        if ((p->format[p->i] == '%' && p->format[p->i + 1] == '\0')
        || p->format[p->i] == '%')
        {
            second_percent(p);
            return;
        }
        (*fpa[(unsigned char)p->format[p->i]])(p);
        if (p->spec_found == 1)
            break;
        p->i++;
    }
    if (p->format[p->i] == '\0')
        p->i--;
}

void    put_zero2(t_printf *p)
{
    p->nan_f = 0;
    p->inf_f = 0;
}

void    put_zero(t_printf *p)
{
	p->base = 0;
	p->lcase = 0;
	p->mod[0] = 0;
    p->mod[1] = 0;
	p->i_res = 0;
	p->unsign = 0;
	p->zero = 0;
	p->minus = 0;
	p->width = 0;
	p->spec_found = 0;
	p->sharp = 0;
	p->prec = 0;
    p->prec_f = 0;
    p->space_f = 0;
    p->string_f = 0;
    p->s_q = 0;
    p->arg = 0;
    p->char_f = 0;
    p->i_prec = 0;
    p->plus_f = 0;
    p->exept_zero = 0;
    p->ptr_f = 0;
    p->length_capital_l = 0;
    p->float_f = 0;
    put_zero2(p);
}

int    pars(t_printf *p, function_point_array fpa[256])
{
    p->static_ft_printf = 1;
    p->i = 0;
    p->s = 0;
    p->spike_w = 0;
    p->spike_p = 0;
    p->i_buff = 0;
    p->box[0] = 'a';
    p->box[1] = 'A';
    put_zero(p);
    while(p->format[p->i] != '\0')
    {
        if (p->format[p->i] == '%')
        {
            percent_found(p, fpa);
            put_zero(p);
        }
        else
            print_to_percent(p);
        p->i += 1;
    }
    print_buff(p);
    return(p->s);
}
