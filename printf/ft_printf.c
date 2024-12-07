/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:56:55 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/27 18:12:53 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkptr(void *ptr, int *len)
{
	if (!ptr)
		ft_strprint(len, "(nil)");
	else
	{
		ft_strprint(len, "0x");
		ft_hexaprint('x', len, (unsigned long)ptr);
	}
}

void	ft_type(char c, int *len, va_list *ap)
{
	if (c == 'c')
		ft_chrprint(len, va_arg(*ap, int));
	else if (c == 's')
		(ft_strprint(len, va_arg(*ap, char *)));
	else if (c == 'p')
		checkptr(va_arg(*ap, void *), len);
	else if (c == 'd' || c == 'i')
		(ft_nbrprint(len, va_arg(*ap, int)));
	else if (c == 'u')
		(ft_unsignedprint(len, va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		(ft_hexaprint(c, len, va_arg(*ap, unsigned int)));
	else if (c == '%')
		(ft_chrprint(len, '%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_type(*++format, &len, &ap);
		else
		{
			ft_chrprint(&len, *format);
		}
		format++;
	}
	va_end (ap);
	return (len);
}
