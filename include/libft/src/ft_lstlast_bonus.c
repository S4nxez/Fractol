/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:20:10 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/23 13:20:10 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

/*
#include <stdio.h>
int main(){
	t_list *lista = NULL;

	t_list *primero;
	t_list *segundo;
	t_list *tercero;

	primero = ft_lstnew("hola ");
	segundo = ft_lstnew("mundo");
	tercero = ft_lstnew("!\n");
	ft_lstadd_front(&lista, tercero);
	ft_lstadd_front(&lista, segundo);
	ft_lstadd_front(&lista, primero);

	printf("%s", (char *)ft_lstlast(lista)->content);
}*/