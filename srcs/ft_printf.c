/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:15:58 by nsance            #+#    #+#             */
/*   Updated: 2020/02/12 19:16:00 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	static t_printf					p;
	static t_function_point_array	fpa[256];

	if (p.static_ft_printf == 0)
		spec_flags(fpa);
	p.format = (char *)format;
	va_start(p.ap, format);
	pars(&p, fpa);
	return (p.s);
}
