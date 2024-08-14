/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:45:38 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/14 20:45:38 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nlong;

	nlong = n;
	if (fd < 0)
		return ;
	if (nlong < 0)
	{
		nlong = -nlong;
		ft_putchar_fd('-', fd);
	}
	if (nlong < 10)
		ft_putchar_fd(nlong + '0', fd);
	else
	{
		ft_putnbr_fd(nlong / 10, fd);
		ft_putchar_fd(nlong % 10 + '0', fd);
	}
}

/*
int	main(void)
{
	ft_putnbr_fd(-9832, 1);
}
*/