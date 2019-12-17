/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:35:16 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/13 14:22:37 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_kk(void *s, size_t n)
{
	char *i;

	i = (char*)s;
	while (n > 0)
	{
		*(i++) = 0;
		n--;
	}
}

void		*ft_calloc(size_t count, size_t size)
{
	void *p;

	if (!(p = malloc(count * size)))
		return (0);
	ft_kk(p, count * size);
	return (p);
}
