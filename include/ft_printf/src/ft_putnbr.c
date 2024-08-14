/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:40:52 by dansanc3          #+#    #+#             */
/*   Updated: 2024/05/25 13:38:14 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	long	nlong;

	nlong = n;
	len = int_len(nlong);
	if (nlong < 0)
		nlong *= -1;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
		ret[0] = '-';
	else if (n == 0)
		ret[0] = '0';
	ret[len--] = '\0';
	while (nlong >= 10)
	{
		ret[len--] = '0' + (nlong % 10);
		nlong /= 10;
	}
	ret[len] = nlong + '0';
	return (ret);
}

int	ft_putnbr(int c)
{
	char	*itoa;
	int		ret;

	itoa = ft_itoa(c);
	ret = ft_putstr(itoa);
	free(itoa);
	return (ret);
}
