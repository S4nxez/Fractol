/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:00:09 by dansanc3          #+#    #+#             */
/*   Updated: 2024/01/26 17:30:48 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;
	size_t	total_len;
	size_t	i;

	if (!s)
		return (NULL);
	total_len = ft_strlen(s);
	if (start > total_len)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ret_str = (char *)malloc(len + 1);
	if (!ret_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret_str[i] = s[start + i];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

/*
int	main(void)
{
	printf("%d\n",substr("hola que tal", 2, 5));
	printf("%s\n",ft_substr("hola que tal", 2, 5));
}*/