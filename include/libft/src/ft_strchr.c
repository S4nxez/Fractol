/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:34:50 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 17:34:50 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_copy;

	c_copy = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_copy)
			return ((char *)&s[i]);
		i++;
	}
	if (c_copy == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	a[] = "hola que tal";
	char	*a_ptr = a;

	printf ("antes..: %s\n",a_ptr);
	printf ("despues: %s\n",ft_strchr(a_ptr, '\0'));
}*/