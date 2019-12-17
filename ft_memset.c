/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:28:54 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 13:11:20 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	l;

	s = (char*)b;
	l = (unsigned char)c;
	while (len > 0)
	{
		*(s++) = l;
		len--;
	}
	return (b);
}
