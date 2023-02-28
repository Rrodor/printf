/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:15:14 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/27 20:24:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (c < 10 && c >= 0)
		c += 48;
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putnbr_base(int n, int l, char *base)
{
	int	lbase;
	char	str[32];
	int	i;

	i = 0;
	lbase = ft_strlen(base);
	//printf("test");
	if (n == 0)
	{
		ft_putchar(base[i]);
		l++;
		return (l);
	}
	while (n > 0)
	{
		//printf("test");
		str[i] = base[n % lbase];
		i++;
		n = n / lbase;
		l++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
	return (l);
}

/*
#include <unistd.h>
#include <stdio.h>
int main()
{
	char	base[] = "0123456789ABCDEF";

	ft_putnbr_base(76, 0, base);
	write(1, "\n", 1);
	return (0);
}*/



