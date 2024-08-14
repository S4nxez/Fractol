/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:24:13 by dansanc3          #+#    #+#             */
/*   Updated: 2024/05/25 22:07:11 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_rec(unsigned long n, char format, int *ret)
{
	const char	*converter;

	if (format == 'X')
		converter = "0123456789ABCDEF";
	else
		converter = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex_rec(n / 16, format, ret);
		n %= 16;
	}
	*ret += write(1, &(converter[n]), 1);
}

int	ft_puthex(unsigned long n, char format)
{
	int	ret;

	ret = 0;
	ft_puthex_rec(n, format, &ret);
	return (ret);
}
