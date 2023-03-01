/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:34:24 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/28 19:22:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	int		i;
	int		l;
	va_list	argptr;

	va_start(argptr, 0);
	i = 0;
	l = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			write(1, &str[i], 1);
			l++;
			i++;
		}
		if (str[i++])
		{
			l = ft_redirect(str[i], argptr, l);
			i++;
		}
	}
	return (l);
}

int	ft_redirect(char c, va_list argptr, int l)
{
	if (c == 'c')
		l = ft_printc(argptr, l);
	if (c == 's')
		l = ft_prints(argptr, l);
	if (c == 'p')
		l = ft_printp(argptr, l);
	if (c == 'd' || c == 'i')
		l = ft_printd(argptr, l);
	if (c == 'u')
		l = ft_printu(argptr, l);
	if (c == 'x')
		l = ft_printx(argptr, l);
	if (c == 'X')
		l = ft_printxm(argptr, l);
	if (c == '%')
	{
		ft_putchar('%');
		l++;
	}
	return (l);
}

/*#include <stdio.h>
int	main()
{
	int	l = 0;
	int	l2 = 0;
	int 	t = -1984;
	//int	*test = 0;
	l = ft_printf("%X%%", t);
	ft_putchar('\n');
	l2 = printf("%X%%", t);
	printf("\n%d", l);
	printf("\n%d\n", l2);
	return 0;
}*/
