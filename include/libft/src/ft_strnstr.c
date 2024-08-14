/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:40:02 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/26 16:44:31 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	const	char *haystack = "Hello, World! This is a test string.";
	const	char *needle = "World";
	size_t	len = ft_strlen(haystack);

	char	*result = ft_strnstr(haystack, needle, len);

	if (result)
	{
		printf("Needle found at index: %ld\n", result - haystack);
	}
	else
	{
		printf("Needle not found.\n");
	}
	return (0);
}
*/