#include "ft_printf.h"

int	ft_printu(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789");
	return (l);
}

int	ft_printx(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789abcdef");
	return (l);
}

int	ft_printxm(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789ABCDEF");
	return (l);
}
