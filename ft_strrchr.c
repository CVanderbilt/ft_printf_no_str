/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:33:11 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/11 12:33:13 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = -1;
	ret = 0;
	while (s[++i])
		if (s[i] == c)
			ret = (char*)(s + i);
	if (s[i] == c)
		ret = (char*)(s + i);
	return (ret);
}
