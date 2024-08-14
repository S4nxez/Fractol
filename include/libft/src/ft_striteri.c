/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:02:04 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/14 20:02:04 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	*ft_toupper2(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 'A';
	return (c);
}

int main()
{
	char const *s = "Hello, World!";
	char *result = ft_strmapi(s, ft_toupper2);

	if (result)
	{
		printf("%s\n", result);
	}
	return 0;
}*/