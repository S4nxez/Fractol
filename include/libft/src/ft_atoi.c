/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:16:25 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/11 10:07:02 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	sign;

	ret = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("Atoi og: %d\n", atoi("--12"));
	printf("Atoi og: %d\n", atoi("-+12"));
	printf("Atoi og: %d\n", atoi("++12"));
	printf("Atoi og: %d\n", atoi(" -12323s2"));
	printf("Atoi og: %d\n", ft_atoi("    123"));

	printf("Atoi ft: %d\n", ft_atoi("--12"));
	printf("Atoi ft: %d\n", ft_atoi("-+12"));
	printf("Atoi ft: %d\n", ft_atoi("++12"));
	printf("Atoi ft: %d\n", ft_atoi(" -12323s2"));
	printf("Atoi ft: %d\n", ft_atoi("    123"));

}
*/