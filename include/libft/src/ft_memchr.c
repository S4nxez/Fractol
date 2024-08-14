/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:54:28 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/21 10:38:31 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_aux;
	unsigned char	c_aux;
	size_t			i;

	s_aux = (unsigned char *)s;
	c_aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_aux[i] == c_aux)
			return ((void *)&s_aux[i]);
		i++;
	}
	return (NULL);
}
