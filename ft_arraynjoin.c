/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraynjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:05:40 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/16 17:23:45 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arraynjoin(const void *tab1, const void *tab2, int n1, int n2)
{
	char *str1;
	char *str2;
	char *ret;
	int i;
	int j;

	i = -1;
	j = -1;
	if (!tab1 || !tab2)
		return (0);
	n1 = n1 >=  0  ? n1 : 0;
	n2 = n2 >=  0  ? n2 : 0;
	str1 = (char*)tab1;
	str2 = (char*)tab2;
	if (!(ret = malloc(n1 + n2)))
		return (0);
	while (++i < n1)
		ret[i] = str1[i];
	while (++j < n2)
		ret[i + j] = str2[j];
	return (ret);
}
