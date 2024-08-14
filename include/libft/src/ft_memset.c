/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:02:53 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/10 14:02:53 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*aux;

	aux = (unsigned char *)b;
	while (len--)
	{
		*aux = (unsigned char)c;
		aux++;
	}
	return (b);
}
