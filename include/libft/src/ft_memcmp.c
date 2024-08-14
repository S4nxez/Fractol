/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:45:26 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/11 10:17:04 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;
	size_t			i;

	s1_aux = (unsigned char *) s1;
	s2_aux = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1_aux[i] != s2_aux[i])
			return (s1_aux[i] - s2_aux[i]);
		i++;
	}
	return (0);
}
