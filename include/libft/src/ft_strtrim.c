/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:04:08 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/01 20:04:08 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		ini;
	int		fin;

	if (!s1 || !set)
		return (NULL);
	ini = 0;
	while (ft_strchr(set, s1[ini]) && s1[ini])
		ini++;
	fin = ft_strlen(s1);
	while (ft_strchr(set, s1[fin]) && fin > ini)
		fin--;
	fin++;
	ret = ft_substr(s1, ini, fin - ini);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

//#include <shlwapi.h>
/*int	main(void)
{
	printf("FT_Strtrim:%s", ft_strtrim("ababbabbbholabaababba", "ab"));
	//	printf("Strtrim:    %s", strtrim(""));
	return (0);
}*/