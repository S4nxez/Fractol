/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:18:51 by dansanc3          #+#    #+#             */
/*   Updated: 2024/05/25 19:15:25 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_rec(unsigned int n, int *ret)
{
	if (n >= 10)
		ft_putunbr_rec(n / 10, ret);
	*ret += ft_putchar((n % 10) + '0');
}

int	ft_putunbr(unsigned int n)
{
	int	ret;

	ret = 0;
	ft_putunbr_rec(n, &ret);
	return (ret);
}
