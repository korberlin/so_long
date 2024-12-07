/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:05:58 by gkoksal           #+#    #+#             */
/*   Updated: 2023/11/27 17:41:05 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_chrprint(int *len, int c);
void	ft_strprint(int *len, char *str);
void	ft_nbrprint(int *len, int n);
void	checkptr(void *ptr, int *len);
void	ft_unsignedprint(int *len, unsigned int n);
void	ft_hexaprint(char c, int *len, unsigned long n);
void	ft_type(char c, int *len, va_list *ap);
int		ft_printf(const char *format, ...);
#endif
