/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:17:40 by dansanc3          #+#    #+#             */
/*   Updated: 2024/04/08 17:17:40 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list args, char c);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret += print_format(args, *format);
		}
		else
		{
			if (!ft_putchar(*format))
				return (-1);
			ret++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}

static int	print_format(va_list args, char c)
{
	void	*ptr;

	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x' || c == 'X')
		return (ft_puthex((unsigned long)va_arg(args, unsigned int), c));
	else if (c == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
		{
			ft_putstr("0x");
			return (2 + ft_puthex((unsigned long)ptr, c));
		}
		return (ft_putstr("0x0"));
	}
	return (-1);
}
