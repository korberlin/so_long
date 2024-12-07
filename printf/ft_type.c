/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:56:47 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/27 17:52:33 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_chrprint(int *len, int c)
{
	char	b;

	b = (char)c;
	write(1, &b, 1);
	*len += 1;
}

void	ft_strprint(int *len, char *str)
{
	if (!str)
		ft_strprint(len, "(null)");
	else
	{
		while (*str)
		{
			write(1, str, 1);
			*len += 1;
			str++;
		}
	}
}

void	ft_nbrprint(int *len, int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_strprint(len, "-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_chrprint(len, '-');
		n = -n;
	}
	while (n > 9)
	{
		ft_nbrprint(len, n / 10);
		n %= 10;
	}
	c = n % 10 + '0';
	ft_chrprint(len, c);
}

void	ft_unsignedprint(int *len, unsigned int n)
{
	char	c;

	while (n > 9)
	{
		ft_unsignedprint(len, n / 10);
		n %= 10;
	}
	c = n % 10 + '0';
	ft_chrprint(len, c);
}

void	ft_hexaprint(char c, int *len, unsigned long n)
{
	char	b;
	char	*set;

	if (c == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_hexaprint(c, len, n / 16);
		n %= 16;
	}
	b = set[n % 16];
	ft_chrprint(len, b);
}
