/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:21:26 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/16 17:23:20 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrayndup(const char *str, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char*)malloc(n);
	if (p == 0)
		return (p);
	i = -1;
	while (++i < n)
		p[i] = str[i];
	return (p);
}
