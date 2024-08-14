/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:05:24 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 19:05:24 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	if (n > 0)
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
}*/