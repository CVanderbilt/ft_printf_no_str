/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:48 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 14:57:49 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_list;
	t_list	*p;
	void	(*k)(void*);

	k = del;
	new_list = malloc(8);
	p = 0;
	if (!lst)
		return (0);
	*new_list = p;
	while (lst)
	{
		p = ft_lstnew(f(lst->content));
		ft_lstadd_back(new_list, p);
		lst = lst->next;
	}
	p = *new_list;
	free(new_list);
	return (p);
}
