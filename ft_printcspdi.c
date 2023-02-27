/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcspdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:43:09 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/27 20:11:27 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printc(va_list argptr, int l)
{
	int		n;

	n = va_arg(argptr, int);
	l++;
	ft_putchar(n);
	return (l);
}

int		ft_prints(va_list argptr, int l)
{
	char	*str;

	str = va_arg(argptr, char *);
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

int		ft_printp(va_list argptr, int l)
{
	
}
