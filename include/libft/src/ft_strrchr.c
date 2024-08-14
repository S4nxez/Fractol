/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:22:55 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/18 18:22:55 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	i;
	char	c_copy;

	c_copy = (char)c;
	ret = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_copy)
			ret = ((char *)&s[i]);
		i++;
	}
	if (c_copy == '\0')
		return ((char *)&s[i]);
	return (ret);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	a[] = "hola que tal";
	char	*a_ptr = a;

	printf ("antes..: %s\n",a_ptr);
	printf ("despues: %s\n",ft_strchr(a_ptr, 'a'));
}*/