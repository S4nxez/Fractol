/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 11:29:00 by dansanc3          #+#    #+#             */
/*   Updated: 2024/03/24 11:29:00 by dansanc3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*cast_content;

	if (!lst || !del || !f)
		return (0);
	new_list = NULL;
	while (lst != NULL)
	{
		cast_content = f(lst->content);
		new_obj = ft_lstnew(cast_content);
		if (!new_obj)
		{
			del(cast_content);
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	ft_lstadd_back(&new_list, lst);
	return (new_list);
}
