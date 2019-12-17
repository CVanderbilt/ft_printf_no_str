/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:34 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 14:57:35 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *next;

	next = lst != 0 ? lst->next : 0;
	while (lst)
	{
		f(lst->content);
		lst = next;
		next = lst != 0 ? lst->next : 0;
	}
}
