/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:38:46 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/29 11:18:36 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(long unsigned int n, char *base)
{
	int		len;
	int		dgts;
	char	*nbr_base;

	if (!base)
		return (0);
	len = ft_strlen(base);
	dgts = ft_dgts_base(n, len);
	if (!(nbr_base = malloc(dgts + 1)))
		return (0);
	nbr_base[dgts] = 0;
	while (--dgts >= 0)
	{
		nbr_base[dgts] = base[n % len];
		n /= len;
	}
	return (nbr_base);
}
