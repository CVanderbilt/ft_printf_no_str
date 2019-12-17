/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:34:29 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 18:12:24 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(size_t *a, size_t *b, char **h, char *ret)
{
	*a = 0;
	*b = 0;
	*h = ret;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ret;
	char	*h;
	char	*n;
	size_t	aux;
	size_t	aux2;

	ret = (char*)haystack;
	n = (char*)needle;
	ft_init(&aux, &aux2, &h, ret);
	while (h[aux] && n[aux2] && aux < len)
	{
		ret = h[aux] != n[aux2] ? 0 : ret;
		aux2 = h[aux] != n[aux2] ? 0 : aux2;
		if (h[aux] == n[aux2])
		{
			ret = ret != 0 ? ret : h + aux;
			if (n[++aux2] == 0)
				return (ret);
		}
		aux++;
	}
	return (needle[aux2] == 0 ? ret : 0);
}
