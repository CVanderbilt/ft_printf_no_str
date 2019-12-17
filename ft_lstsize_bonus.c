/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:58:17 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 14:58:18 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next;

	i = -1;
	next = lst ? lst->next : 0;
	while ((++i || 1) && lst)
	{
		lst = next;
		next = lst ? lst->next : 0;
	}
	return (i);
}
