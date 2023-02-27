/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:34:24 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/27 20:24:09 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	int	i;
	int	l;
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
	return (l);
}

int	main()
{
	int	l = 0;

	l = ft_printf("salut%s", " a tous");
	printf("\n%d", l);
	return 0;
}
