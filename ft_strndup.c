/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:50 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/12 15:55:05 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	while (str[i] && i < n)
		i++;
	p = (char*)malloc(i + 1);
	if (p == 0)
		return (p);
	i = -1;
	while (str[++i] && i < n)
		p[i] = str[i];
	p[i] = 0;
	return (p);
}
