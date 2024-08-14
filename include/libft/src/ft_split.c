/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:43:44 by dansanc3          #+#    #+#             */
/*   Updated: 2024/02/06 10:43:44 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_delim(char const *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != delim)
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words_num;

	i = 0;
	words_num = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words_num++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words_num);
}

static void	*ft_delete_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		k;
	int		words_num;
	char	**ret;

	if (!s)
		return (NULL);
	words_num = count_words(s, c);
	ret = (char **)malloc((words_num + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	k = -1;
	while (++k < words_num)
	{
		while (s[i] == c)
			i++;
		ret[k] = ft_substr(s, i, ft_strlen_delim(s + i, c));
		if (!ret[k])
			return (ft_delete_matrix(ret));
		i += ft_strlen_delim(s + i, c);
	}
	ret[words_num] = NULL;
	return (ret);
}

/*int	main(void)
{
	const char	strin[] = " hola   que tal";
	const char	c = ' ';
	char		**spliteado = ft_split(strin , c);
	int			num = count_words(strin, c);
	int			j = 0;

	printf("\nnumero : %d\n", num);
	while (j < num)
	{
		printf("\n%s", spliteado[j]);
		j++;
	}
}
*/