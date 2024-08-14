/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:54:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 16:54:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	i = 0;
	while (*src && i < dstsize - len_dst - 1)
	{
		dst[i + len_dst] = *src;
		i++;
		src++;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}

/*
#include <stdio.h>

int main()
{
	char dest[50] = "Hello, ";
	char *src = "World!";

	size_t dest_size = 50;
	int new_len = (int)ft_strlcat(dest, src, dest_size);

	printf("New string: %s\n", dest);
	printf("New length: %d\n", new_len);

	return 0;
}*/