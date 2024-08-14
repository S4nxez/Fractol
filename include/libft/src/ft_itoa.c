/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:04:49 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:49 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (nlong > 0)
	{
		ret[len--] = '0' + (nlong % 10);
		nlong /= 10;
	}
	return (ret);
}

/*
#include <stdio.h>
int main(){
	printf("%i \n",int_len(-3720));
	printf("%s \n",ft_itoa(-3720));
}*/