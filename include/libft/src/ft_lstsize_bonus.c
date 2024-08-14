/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:05:35 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/23 12:05:35 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst)
	{
		size = 0;
		while (lst->next != NULL)
		{
			size++;
			lst = lst->next;
		}
		return (++size);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(){
	t_list *new;

	new = NULL;
	t_list *first;
	t_list *second;
	t_list *third;

	first = ft_lstnew("hola");
	second = ft_lstnew("mundo");
	third = ft_lstnew("!");

	ft_lstadd_front(&new, third);
	ft_lstadd_front(&new, second);
	ft_lstadd_front(&new, first);
	printf("%d\n",ft_lstsize(new));
	while(new)
	{
		printf("%s", (char *)new->content);
		new = new->next;
	}
}
*/