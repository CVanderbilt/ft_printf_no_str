/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:11 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 14:57:12 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(void*))
{
	t_list *next;

	if (head && del)
	{
		while (*head)
		{
			next = (*head)->next ? (*head)->next : 0;
			ft_lstdelone(*head, del);
			*head = next;
		}
		head = 0;
	}
}
