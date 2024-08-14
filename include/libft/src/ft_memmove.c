/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:32:20 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/11 10:37:16 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*aux_src;
	char		*aux_dst;
	size_t		n;

	if (!dst && !src)
		return (NULL);
	aux_dst = (char *)dst;
	aux_src = (char *)src;
	n = 0;
	if (aux_dst > aux_src)
	{
		while (len--)
			aux_dst[len] = aux_src[len];
		return (aux_dst);
	}
	else
	{
		while (n < len)
		{
			aux_dst[n] = aux_src[n];
			n++;
		}
		return (aux_dst);
	}
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	source[] = "Hello, World!";
	char	destination[5];
	char	*src_ptr = source;
	char	*dst_ptr = src_ptr + 5;

	// Using the standard library memmove for comparison
	printf("OG memmove return value:  %s\n", memmove( src_ptr, dst_ptr,5));
	printf("Standard memmove: %s\n", source);

	char	source2[] = "Hello, World!";
	char	destination2[5];
	char	*src_ptr2 = source2;
	char	*dst_ptr2 = src_ptr2 + 5;
	// Using custom memmove implementation
	printf("Custom memmove ret value:  %s\n", ft_memmove(src_ptr2, dst_ptr2, 5));
	printf("Custom memmove:.. %s\n", source2);

	return (0);
}*/