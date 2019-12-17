/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:30:08 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 13:11:35 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst)
		return (0);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	if (s < d)
		while (++i <= len)
			d[len - i] = s[len - i];
	else
		while (len-- > 0)
			*(d++) = *(s++);
	return (dst);
}
