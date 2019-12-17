/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:30:34 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 12:30:36 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cstr;
	unsigned char	l;

	l = (unsigned char)c;
	cstr = (unsigned char*)s;
	while (n--)
		if (*cstr++ == l)
			return (cstr - 1);
	return (0);
}
