/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:15:01 by dansanc3          #+#    #+#             */
/*   Updated: 2024/05/17 17:23:53 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	ret;

	ret = 0;
	if (!s)
	{
		if (write (1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[ret])
	{
		if (write(1, &s[ret], 1) != 1)
			return (-1);
		ret++;
	}
	return (ret);
}
