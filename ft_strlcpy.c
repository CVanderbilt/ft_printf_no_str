/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:34:00 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 12:34:03 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*max;
	int		aux;
	char	*ret_s;

	if (!(dst || src))
		return (0);
	max = dst + dstsize;
	ret_s = (char*)src;
	aux = 0;
	while (src[aux] && (dst + aux) < max)
	{
		*(dst + aux) = *(src + aux);
		aux++;
	}
	if ((dst + aux) < max)
		*(dst + aux) = 0;
	else if (dstsize > 0)
		*(dst + aux - 1) = 0;
	aux = 0;
	while (src[aux])
		aux++;
	return (aux);
}
