/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:29:53 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 12:29:57 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	l;

	l = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
	{
		*d++ = *s;
		if (*(s++) == l)
			return (d);
	}
	return (0);
}
