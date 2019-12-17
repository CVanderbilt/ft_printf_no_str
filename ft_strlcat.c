/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:34:12 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 12:34:15 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dsts;
	size_t	srcs;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	dsts = i;
	i = 0;
	while (src[i])
		i++;
	srcs = i;
	if (dstsize == 0 || dstsize - 1 < dsts)
		return (dstsize + srcs);
	i = 0;
	while (src[i] && i + dsts < dstsize - 1)
	{
		dst[i + dsts] = src[i];
		i++;
	}
	dst[i + dsts] = 0;
	return (dsts + srcs);
}
