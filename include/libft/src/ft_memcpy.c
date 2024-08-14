/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:08:27 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/10 20:08:27 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	const unsigned char	*src_bytes;
	unsigned char		*dst_bytes;
	size_t				i;

	dst_bytes = dst;
	src_bytes = src;
	if (!dst_bytes && !src_bytes)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_bytes[i] = src_bytes[i];
		i++;
	}
	return (dst);
}
